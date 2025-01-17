//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#import <objc/Ice.h>
#import <TestCommon.h>
#import <ObjectsTest.h>
#import <ObjectsForward.h>

void breakRetainCycleB(TestObjectsB* b1);
void breakRetainCycleC(TestObjectsC* c1);
void breakRetainCycleD(TestObjectsD* d1);

void breakRetainCycleB(TestObjectsB* b1)
{
    if([b1.theA isKindOfClass:[TestObjectsB class]])
    {
        TestObjectsB* b2 = (TestObjectsB*)b1.theA;
        b2.theA = nil;
        b2.theB.theA = nil;
        b2.theB.theB = nil;
        b2.theB.theC = nil;
        b2.theB = nil;
        b2.theC = nil;
        b2 = nil;
    }
    b1.theA = nil;
    b1.theB = nil;
    b1.theC = nil;
}

void breakRetainCycleC(TestObjectsC* c1)
{
    breakRetainCycleB(c1.theB);
    c1.theB = nil;

}

void breakRetainCycleD(TestObjectsD* d1)
{
    breakRetainCycleB((TestObjectsB*)d1.theA);
    breakRetainCycleB(d1.theB);
}

id<TestObjectsInitialPrx>
objectsAllTests(id<ICECommunicator> communicator, BOOL __unused collocated)
{
    tprintf("testing stringToProxy... ");
    NSString* ref = [NSString stringWithFormat:@"initial:%@", getTestEndpoint(communicator, 0)];
    id<ICEObjectPrx> base = [communicator stringToProxy:ref];
    test(base);
    tprintf("ok\n");

    tprintf("testing checked cast... ");
    id<TestObjectsInitialPrx> initial = [TestObjectsInitialPrx checkedCast:base];
    test(initial);
    test([initial isEqual:base]);
    tprintf("ok\n");

    tprintf("testing constructor, convenience constructor, and copy... ");

    TestObjectsBase* ba1 = [TestObjectsBase base];

    test([ba1.theS.str isEqual:@""]);
    test([ba1.str isEqual:@""]);
    ba1.theS = nil;

    TestObjectsS* s = [TestObjectsS s];
    s.str = @"hello";
    TestObjectsBase* ba2 = [TestObjectsBase base:s str:@"hi"];
    test(ba2.theS == s);
    test([ba2.str isEqualToString:@"hi"]);
    ba2.theS = nil;

    TestObjectsBase* ba3 = ICE_AUTORELEASE([ba2 copy]);
    test(ba3 != ba2);
    test(ba3.theS == ba2.theS);
    test(ba3.str == ba2.str);
    ba3.theS = nil;

#if 0
    // Can't override assignment operator in Objective-C.
    *ba1 = *ba2;
    test([ba1.theS.str isEqualToString:@"hello"]);
    test([ba1.str isEqualToString:@"hi"]);

    TestObjectsBase* bp1 = [TestObjectsBase base];
    *bp1 = *ba2;
    test([bp1.theS.str isEqualToString:@"hello"]);
    test([bp1.str isEqualToString:@"hi"]);
#endif

    tprintf("ok\n");

    tprintf("getting B1... ");
    TestObjectsB* b1 = [initial getB1];
    test(b1);
    tprintf("ok\n");

    tprintf("getting B2... ");
    TestObjectsB* b2 = [initial getB2];
    test(b2);
    tprintf("ok\n");

    tprintf("getting C... ");
    TestObjectsC* c = [initial getC];
    test(c);
    tprintf("ok\n");

    tprintf("getting D... ");
    TestObjectsD* d = [initial getD];
    test(d);
    tprintf("ok\n");

    tprintf("checking consistency... ");
    test(b1 != b2);
    test(b1 != (TestObjectsB*)c);
    test(b1 != (TestObjectsB*)d);
    test(b2 != (TestObjectsB*)c);
    test(b2 != (TestObjectsB*)d);
    test(c != (TestObjectsC*)d);
    test(b1.theB == b1);
    test(b1.theC == 0);
    test([b1.theA isKindOfClass:[TestObjectsB class]]);
    test(((TestObjectsB*)b1.theA).theA == b1.theA);
    test(((TestObjectsB*)b1.theA).theB == b1);
    test([((TestObjectsB*)b1.theA).theC isKindOfClass:[TestObjectsC class]]);
    test(((TestObjectsC*)((TestObjectsB*)b1.theA).theC).theB == b1.theA);
    test(b1.preMarshalInvoked);
    test(b1.postUnmarshalInvoked);
    test(b1.theA.preMarshalInvoked);
    test(b1.theA.postUnmarshalInvoked);
    test(((TestObjectsB*)b1.theA).theC.preMarshalInvoked);
    test(((TestObjectsB*)b1.theA).theC.postUnmarshalInvoked);

    // More tests possible for b2 and d, but I think this is already sufficient.
    test(b2.theA == b2);
    test(d.theC == 0);

    breakRetainCycleB(b1);
    breakRetainCycleB(b2);
    breakRetainCycleC(c);
    breakRetainCycleD(d);

    tprintf("ok\n");

    tprintf("getting B1, B2, C, and D all at once... ");
    [initial getAll:&b1 b2:&b2 theC:&c theD:&d];
    test(b1);
    test(b2);
    test(c);
    test(d);
    tprintf("ok\n");

    tprintf("checking consistency... ");
    test(b1 != b2);
    test(b1 != (TestObjectsB*)c);
    test(b1 != (TestObjectsB*)d);
    test(b2 != (TestObjectsB*)c);
    test(b2 != (TestObjectsB*)d);
    test(c != (TestObjectsC*)d);
    test(b1.theA == b2);
    test(b1.theB == b1);
    //test(b1.theC == 0);
    test(b2.theA == b2);
    test(b2.theB == b1);
    test(b2.theC == c);
    test(c.theB == b2);
    test(d.theA == b1);
    test(d.theB == b2);
    //test(d.theC == 0);

    test(d.preMarshalInvoked);
    test(d.postUnmarshalInvoked);
    test(d.theA.preMarshalInvoked);
    test(d.theA.postUnmarshalInvoked);
    test(d.theB.preMarshalInvoked);
    test(d.theB.postUnmarshalInvoked);
    test(d.theB.theC.preMarshalInvoked);
    test(d.theB.theC.postUnmarshalInvoked);

    breakRetainCycleB(b1);
    breakRetainCycleB(b2);
    breakRetainCycleC(c);
    breakRetainCycleD(d);

    tprintf("ok\n");

    tprintf("testing protected members... ");
    TestObjectsE* e = [initial getE];

    test(e.i == 1);
    test([e.s isEqualToString:@"hello"]);

    TestObjectsF* f = [initial getF];
    test(f.e1 && f.e1 == f.e2);
    test(f.e1.i == 1 && [e.s isEqualToString:@"hello"]);
    tprintf("ok\n");

    tprintf("setting G... ");
    TestObjectsG *g = ICE_AUTORELEASE([[TestObjectsG alloc] init]);
    g.theS = s;
    g.str = @"g";
    @try
    {
        [initial setG:g];
    }
    @catch(ICEOperationNotExistException*)
    {
    }
    tprintf("ok\n");

    tprintf("getting K... ");
    {
        TestObjectsK* k = (TestObjectsK*)[initial getK];
        TestObjectsL* l = (TestObjectsL*)k.value;
        test([l.data isEqualToString:@"l"]);
    }
    tprintf("ok\n");

    tprintf("testing Value as parameter... ");
    {
        TestObjectsL* v1 = [[TestObjectsL alloc] init:@"l"];
        ICEValue* v2;
        TestObjectsL* v3 = (TestObjectsL*)[initial opValue:v1 v2:&v2];
        test([v3.data isEqualToString:@"l"]);
        test([((TestObjectsL*)v2).data isEqualToString:@"l"]);
    }

    {
        TestObjectsL* l = [[TestObjectsL alloc] init:@"l"];
        NSArray* v1 = @[l];
        NSMutableArray* v2;
        NSArray* v3 = [initial opValueSeq:v1 v2:&v2];
        test([((TestObjectsL*)v3[0]).data isEqualToString:@"l"]);
        test([((TestObjectsL*)v2[0]).data isEqualToString:@"l"]);
    }

    {
        TestObjectsL* l = [[TestObjectsL alloc] init:@"l"];
        NSDictionary* v1 = @{@"l" : l};
        NSMutableDictionary* v2;
        NSDictionary* v3 = [initial opValueMap:v1 v2:&v2];
        test([((TestObjectsL*)v3[@"l"]).data isEqualToString:@"l"]);
        test([((TestObjectsL*)v2[@"l"]).data isEqualToString:@"l"]);
    }
    tprintf("ok\n");

    tprintf("testing recursive type... ");
    TestObjectsRecursive* top = [TestObjectsRecursive recursive];
    TestObjectsRecursive* p = top;
    int depth = 0;
    @try
    {
#if defined(NDEBUG) || !defined(__APPLE__)
        const int maxDepth = 20000;
#else
        // With debug, marshalling a graph of 20000 elements can cause a stack overflow on macOS
        const int maxDepth = 1500;
#endif
        for(; depth <= maxDepth; ++depth)
        {
            p.v = [TestObjectsRecursive recursive];
            p = p.v;
            if((depth < 10 && (depth % 10) == 0) ||
               (depth < 1000 && (depth % 100) == 0) ||
               (depth < 10000 && (depth % 1000) == 0) ||
               (depth % 10000) == 0)
            {
                [initial setRecursive:top];
            }
        }
        test(![initial supportsClassGraphDepthMax]);
    }
    @catch(ICEUnknownLocalException*)
    {
        // Expected marshal exception from the server (max class graph depth reached)
        test(depth == 100); // The default is 100.
    }
    @catch(ICEUnknownException*)
    {
        // Expected stack overflow from the server (Java only)
    }
    [initial setRecursive:[TestObjectsRecursive recursive]];
    tprintf("ok\n");

    tprintf("testing sequences... ");
    TestObjectsMutableBaseSeq* inS = [TestObjectsMutableBaseSeq array];
    TestObjectsMutableBaseSeq* outS;
    TestObjectsMutableBaseSeq* retS = [initial opBaseSeq:inS outSeq:&outS];

    [inS addObject:[TestObjectsBase base]];
    retS = [initial opBaseSeq:inS outSeq:&outS];
    test([retS count] == 1 && [outS count] == 1);
    tprintf("ok\n");

    tprintf("testing compact ID...");
    @try
    {
        test([initial getCompact]);
    }
    @catch(ICEOperationNotExistException*)
    {
    }
    tprintf("ok\n");

    tprintf("testing marshaled results...");
    b1 = [initial getMB];
    test(b1 != nil && b1.theB == b1);
    breakRetainCycleB(b1);
    b1 = [initial end_getAMDMB:[initial begin_getAMDMB]];
    test(b1 != nil && b1.theB == b1);
    breakRetainCycleB(b1);
    tprintf("ok\n");

    tprintf("testing UnexpectedObjectException... ");
    ref = [NSString stringWithFormat:@"uoet:%@", getTestEndpoint(communicator, 0)];
    base = [communicator stringToProxy:ref];
    test(base);
    id<TestObjectsUnexpectedObjectExceptionTestPrx> uoet = [TestObjectsUnexpectedObjectExceptionTestPrx uncheckedCast:base];
    test(uoet);
    @try
    {
        [uoet op];
        test(NO);
    }
    @catch(ICEUnexpectedObjectException* ex)
    {
        test([ex.type isEqualToString:@"::Test::AlsoEmpty"]);
        test([ex.expectedType isEqualToString:@"::Test::Empty"]);
    }
    @catch(ICEException* ex)
    {
        test(NO);
    }
    tprintf("ok\n");

    //
    // TestObjectss specific to Objective-C.
    //
    {
        tprintf("setting Object sequence... ");
        TestObjectsMutableObjectSeq* seq = [TestObjectsMutableObjectSeq array];

        [seq addObject:[NSNull null]];

        TestObjectsBase* b = [TestObjectsBase base];
        b.theS = [TestObjectsS s];
        b.theS.str = @"Hello";
        b.str = @"World";
        [seq addObject:b];

        @try
        {
            TestObjectsObjectSeq* r = [initial getObjectSeq:seq];
            test([r objectAtIndex:0 == [NSNull null]]);
            TestObjectsBase* br = [r objectAtIndex:1];
            test([br.theS.str isEqualToString:@"Hello"]);
            test([br.str isEqualToString:@"World"]);
        }
        @catch(ICEOperationNotExistException*)
        {
            // Expected if we are testing against a non-Objective-C server.
        }
        @catch(...)
        {
            test(NO);
        }
        tprintf("ok\n");
    }

    {
        tprintf("setting Object proxy sequence... ");
        TestObjectsMutableObjectPrxSeq* seq = [TestObjectsMutableObjectPrxSeq array];

        [seq addObject:[NSNull null]];
        [seq addObject:initial];

        @try
        {
            TestObjectsObjectPrxSeq* r = [initial getObjectPrxSeq:seq];
            test([r objectAtIndex:0 == [NSNull null]]);
            test([[r objectAtIndex:1] isEqual:initial]);
        }
        @catch(ICEOperationNotExistException*)
        {
            // Expected if we are testing against a non-Objective-C server.
        }
        @catch(...)
        {
            test(NO);
        }
        tprintf("ok\n");
    }

    {
        tprintf("setting Base sequence... ");
        TestObjectsMutableBaseSeq* seq = [TestObjectsMutableBaseSeq array];

        [seq addObject:[NSNull null]];

        TestObjectsBase* b = [TestObjectsBase base];
        b.theS = [TestObjectsS s];
        b.theS.str = @"Hello";
        b.str = @"World";
        [seq addObject:b];

        @try
        {
            TestObjectsBaseSeq* r = [initial getBaseSeq:seq];
            test([r objectAtIndex:0 == [NSNull null]]);
            TestObjectsBase* br = [r objectAtIndex:1];
            test([br.theS.str isEqualToString:@"Hello"]);
            test([br.str isEqualToString:@"World"]);
            br.theS = nil;
        }
        @catch(ICEOperationNotExistException*)
        {
            // Expected if we are testing against a non-Objective-C server.
        }
        @catch(...)
        {
            test(NO);
        }

        {
            TestObjectsBase* br = [seq objectAtIndex:1];
            br.theS = nil;
            b.theS = nil;
        }
        tprintf("ok\n");
    }

    {
        tprintf("setting Object dictionary... ");
        TestObjectsMutableObjectDict* dict = [TestObjectsMutableObjectDict dictionary];

        [dict setObject:[NSNull null] forKey:@"zero"];

        TestObjectsBase* b = [TestObjectsBase base];
        b.theS = [TestObjectsS s];
        b.theS.str = @"Hello";
        b.str = @"World";
        [dict setObject:b forKey:@"one"];

        @try
        {
            TestObjectsObjectDict* r = [initial getObjectDict:dict];
            test([r objectForKey:@"zero"] == [NSNull null]);
            TestObjectsBase* br = [r objectForKey:@"one"];
            test([br.theS.str isEqualToString:@"Hello"]);
            test([br.str isEqualToString:@"World"]);
            br.theS = nil;
        }
        @catch(ICEOperationNotExistException*)
        {
            // Expected if we are testing against a non-Objective-C server.
        }
        @catch(...)
        {
            test(NO);
        }
        {
            TestObjectsBase* br = [dict objectForKey:@"one"];
            br.theS = nil;
            b.theS = nil;
        }
        tprintf("ok\n");
    }

    {
        tprintf("setting Object proxy dictionary... ");
        TestObjectsMutableObjectPrxDict* dict = [TestObjectsMutableObjectPrxDict dictionary];

        [dict setObject:[NSNull null] forKey:@"zero"];
        ref = [NSString stringWithFormat:@"object:%@", getTestEndpoint(communicator, 0)];
        id<ICEObjectPrx> o = [communicator stringToProxy:ref];
        [dict setObject:o forKey:@"one"];

        @try
        {
            TestObjectsObjectPrxDict* r = [initial getObjectPrxDict:dict];
            test([r objectForKey:@"zero"] == [NSNull null]);
            test([[r objectForKey:@"one"] isEqual:o]);
        }
        @catch(ICEOperationNotExistException*)
        {
            // Expected if we are testing against a non-Objective-C server.
        }
        @catch(...)
        {
            test(NO);
        }
        tprintf("ok\n");
    }

    {
        tprintf("setting Base dictionary... ");
        TestObjectsMutableBaseDict* dict = [TestObjectsMutableBaseDict dictionary];

        [dict setObject:[NSNull null] forKey:@"zero"];

        TestObjectsBase* b = [TestObjectsBase base];
        b.theS = [TestObjectsS s];
        b.theS.str = @"Hello";
        b.str = @"World";
        [dict setObject:b forKey:@"one"];

        @try
        {
            TestObjectsBaseDict* r = [initial getBaseDict:dict];
            test([r objectForKey:@"zero"] == [NSNull null]);
            TestObjectsBase* br = [r objectForKey:@"one"];
            test([br.theS.str isEqualToString:@"Hello"]);
            test([br.str isEqualToString:@"World"]);
            br.theS = nil;
        }
        @catch(ICEOperationNotExistException*)
        {
            // Expected if we are testing against a non-Objective-C server.
        }
        @catch(...)
        {
            test(NO);
        }
        {
            TestObjectsBase* br = [dict objectForKey:@"one"];
            br.theS = nil;
            b.theS = nil;
        }
        tprintf("ok\n");
    }

    @try
    {
        ref = [NSString stringWithFormat:@"test:%@", getTestEndpoint(communicator, 0)];
        id<TestObjectsTestIntfPrx> q = [TestObjectsTestIntfPrx checkedCast:[communicator stringToProxy:ref]];

        {
            tprintf("testing getting ExceptionFactory registration... ");
            @try
            {
                [q throwDerived];
                test(NO);
            }
            @catch(TestObjectsBaseEx* ex)
            {
                test([[ex ice_id] isEqualToString:@"::Test::DerivedEx"]);
            }
            tprintf("ok\n");
        }
    }
    @catch(ICEObjectNotExistException*)
    {
        // cross-test server does not implement this object
    }

    {
        tprintf("testing class containing a complex dictionary... ");
        TestObjectsMutableLMap* v = [TestObjectsMutableLMap dictionary];
        TestObjectsStructKey* k1 = [[TestObjectsStructKey alloc] init:1 s:@"1"];
        [v setObject:[[TestObjectsL alloc] init:@"one"] forKey:k1];
        TestObjectsStructKey* k2 = [[TestObjectsStructKey alloc] init:2 s:@"2"];
        [v setObject:[[TestObjectsL alloc] init:@"two"] forKey:k2];
        TestObjectsM* m = [[TestObjectsM alloc] init:v];

        TestObjectsM* m1;
        TestObjectsM* m2 = [initial opM:m v2:&m1];
        test([m1.v count] == 2);
        test([m2.v count] == 2);

        test([((TestObjectsL*)[m1.v objectForKey:k1]).data isEqualToString:@"one"]);
        test([((TestObjectsL*)[m1.v objectForKey:k2]).data isEqualToString:@"two"]);

        test([((TestObjectsL*)[m2.v objectForKey:k1]).data isEqualToString:@"one"]);
        test([((TestObjectsL*)[m2.v objectForKey:k2]).data isEqualToString:@"two"]);

        tprintf("ok\n");
    }

    {
        tprintf("testing forward declarations... ");
        TestObjectsF1* f12;
        TestObjectsF1* f11 = [initial opF1:[[TestObjectsF1 alloc] init:@"F11"] f12:&f12];
        test([f11.name isEqualToString:@"F11"]);
        test([f12.name isEqualToString:@"F12"]);

        TestObjectsF2Prx* f22;
        ref = [NSString stringWithFormat:@"F21:%@", getTestEndpoint(communicator, 0)];
        TestObjectsF2Prx* f21 = [initial opF2:[TestObjectsF2Prx uncheckedCast:[communicator stringToProxy:ref]]
                                          f22: &f22];
        test([[f21 ice_getIdentity].name isEqualToString:@"F21"]);
        [f21 op];
        test([[f22 ice_getIdentity].name isEqualToString:@"F22"]);
        tprintf("ok\n");
    }

    {
        tprintf("testing sending class cycle... ");
        TestObjectsRecursive* rec = [TestObjectsRecursive recursive];
        rec.v = rec;
        bool acceptsCycles = [initial acceptsClassCycles];
        @try
        {
            [initial setCycle:rec];
            test(acceptsCycles);
        }
        @catch(ICEUnknownLocalException*)
        {
             test(!acceptsCycles);
        }
        rec.v = nil;
        tprintf("ok\n");
    }

    return initial;
}
