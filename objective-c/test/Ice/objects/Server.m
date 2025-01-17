//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#import <objc/Ice.h>
#import <TestCommon.h>
#import <objects/TestI.h>

static int
run(id<ICECommunicator> communicator)
{
    [[communicator getProperties] setProperty:@"TestAdapter.Endpoints" value:getTestEndpoint(communicator, 0)];
    id<ICEObjectAdapter> adapter = [communicator createObjectAdapter:@"TestAdapter"];
    ICEObject* initial = [TestObjectsInitialI initial];
    [adapter add:initial identity:[ICEUtil stringToIdentity:@"initial"]];

    ICEObject* testObj = ICE_AUTORELEASE([[TestObjectsTestIntfI alloc] init]);
    [adapter add:testObj identity:[ICEUtil stringToIdentity:@"test"]];

    ICEObject* f2Obj = ICE_AUTORELEASE([[TestObjectsF2I alloc] init]);
    [adapter add:f2Obj identity:[ICEUtil stringToIdentity:@"F21"]];

    ICEObject* uoet = ICE_AUTORELEASE([[UnexpectedObjectExceptionTestI alloc] init]);
    [adapter add:uoet identity:[ICEUtil stringToIdentity:@"uoet"]];
    [adapter activate];

    serverReady(communicator);

    [communicator waitForShutdown];
    return EXIT_SUCCESS;
}

#if TARGET_OS_IPHONE
#  define main objectsServer
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
            initData.properties = defaultServerProperties(&argc, argv);
            [initData.properties setProperty:@"Ice.Warn.Dispatch" value:@"0"];
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

        if(communicator)
        {
            [communicator destroy];
        }
    }
    return status;
}
