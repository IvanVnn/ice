//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#import <objc/Ice.h>
#import <TestCommon.h>
#import <objects/TestI.h>

#if !TARGET_OS_IPHONE
#   import <Foundation/NSGarbageCollector.h>
#endif

#if defined(__clang__) && __has_feature(objc_arc)
static ICEValueFactory factory = ^ICEValue* (NSString* type) NS_RETURNS_RETAINED
#else
static ICEValueFactory factory = ^ICEValue* (NSString* type)
#endif
{
    if([type isEqualToString:@"::Test::B"])
    {
        return [[TestObjectsBI alloc] init];
    }
    else if([type isEqualToString:@"::Test::C"])
    {
        return [[TestObjectsCI alloc] init];
    }
    else if([type isEqualToString:@"::Test::D"])
    {
        return [[TestObjectsDI alloc] init];
    }
    else if([type isEqualToString:@"::Test::E"])
    {
        return [[TestObjectsEI alloc] init];
    }
    else if([type isEqualToString:@"::Test::F"])
    {
        return [[TestObjectsFI alloc] init];
    }
    else
    {
        test(NO);
    }
    return nil;
};

static int
run(id<ICECommunicator> communicator)
{
    id<ICEValueFactoryManager> manager = [communicator getValueFactoryManager];
    [manager add:factory sliceId:@"::Test::B"];
    [manager add:factory sliceId:@"::Test::C"];
    [manager add:factory sliceId:@"::Test::D"];
    [manager add:factory sliceId:@"::Test::E"];
    [manager add:factory sliceId:@"::Test::F"];

    id<TestObjectsInitialPrx> objectsAllTests(id<ICECommunicator>, bool);
    id<TestObjectsInitialPrx> initial = objectsAllTests(communicator, NO);
    [initial shutdown];
    return EXIT_SUCCESS;
}

#if TARGET_OS_IPHONE
#  define main objectsClient
#endif

int
main(int argc, char* argv[])
{
#ifdef ICE_STATIC_LIBS
    ICEregisterIceSSL(YES);
    ICEregisterIceWS(YES);
#if TARGET_OS_IPHONE && !TARGET_IPHONE_SIMULATOR
    ICEregisterIceIAP(YES);
#endif
#endif

    int status;
    @autoreleasepool
    {
        id<ICECommunicator> communicator = nil;
        @try
        {
            ICEInitializationData* initData = [ICEInitializationData initializationData];
            initData.properties = defaultClientProperties(&argc, argv);
            [initData.properties setProperty:@"Ice.AcceptClassCycles" value:@"1"];
#if TARGET_OS_IPHONE
            initData.prefixTable_ = [NSDictionary dictionaryWithObjectsAndKeys:
                                      @"TestObjects", @"::Test",
                                      nil];
#endif
            communicator = [ICEUtil createCommunicator:&argc argv:argv initData:initData];
            status = run(communicator);
        }
        @catch(ICEException* ex)
        {
            tprintf("%@\n", ex);
            status = EXIT_FAILURE;
        }
        @catch(TestFailedException* ex)
        {
            status = EXIT_FAILURE;
        }

        if(communicator)
        {
            [communicator destroy];
        }
    }
    return status;
}
