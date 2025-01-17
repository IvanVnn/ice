//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#import <ObjectsTest.h>
#import <ObjectsForward.h>

@interface TestObjectsBI : TestObjectsB
{
}
@end

@interface TestObjectsCI : TestObjectsC
{
}
@end

@interface TestObjectsDI : TestObjectsD
{
}
@end

@interface TestObjectsEI : TestObjectsE
@end

@interface TestObjectsFI : TestObjectsF
@end

@interface TestObjectsF2I : TestObjectsF2<TestObjectsF2>
{
}
-(void) op:(ICECurrent*)current;
@end

@interface TestObjectsInitialI : TestObjectsInitial<TestObjectsInitial>
{
    TestObjectsB* _b1;
    TestObjectsB* _b2;
    TestObjectsC* _c;
    TestObjectsD* _d;
    TestObjectsE* _e;
    TestObjectsF* _f;
}
-(id) init;
-(void) shutdown:(ICECurrent*)current;
-(TestObjectsB *) getB1:(ICECurrent *)current;
-(TestObjectsB *) getB2:(ICECurrent *)current;
-(TestObjectsC *) getC:(ICECurrent *)current;
-(TestObjectsD *) getD:(ICECurrent *)current;
-(TestObjectsE *) getE:(ICECurrent *)current;
-(TestObjectsF *) getF:(ICECurrent *)current;
-(void) getAll:(TestObjectsB **)b1 b2:(TestObjectsB **)b2 theC:(TestObjectsC **)theC theD:(TestObjectsD **)theD current:(ICECurrent *)current;
-(TestObjectsCompact*) getCompact:(ICECurrent*)current;
-(void) setG:(TestObjectsG *)theG current:(ICECurrent *)current;
-(TestObjectsObjectSeq *) getObjectSeq:(TestObjectsMutableObjectSeq *)s current:(ICECurrent *)current;
-(TestObjectsObjectPrxSeq *) getObjectPrxSeq:(TestObjectsMutableObjectPrxSeq *)s current:(ICECurrent *)current;
-(TestObjectsBaseSeq *) getBaseSeq:(TestObjectsMutableBaseSeq *)s current:(ICECurrent *)current;
-(TestObjectsObjectDict *) getObjectDict:(TestObjectsMutableObjectDict *)d current:(ICECurrent *)current;
-(TestObjectsObjectPrxDict *) getObjectPrxDict:(TestObjectsMutableObjectPrxDict *)d current:(ICECurrent *)current;
-(TestObjectsBaseDict *) getBaseDict:(TestObjectsMutableBaseDict *)d current:(ICECurrent *)current;
-(TestObjectsM *) opM:(TestObjectsM *)v1 v2:(TestObjectsM **)v2 current:(ICECurrent *)current;
-(TestObjectsF1 *) opF1:(TestObjectsF1 *)f11 f12:(TestObjectsF1 **)f12 current:(ICECurrent *)current;
-(TestObjectsF2Prx *) opF2:(TestObjectsF2Prx *)f21 f22:(TestObjectsF2Prx **)f22 current:(ICECurrent *)current;
-(BOOL) hasF3:(ICECurrent *)current;
@end

@interface UnexpectedObjectExceptionTestI : ICEBlobject<ICEBlobject>
@end

@interface TestObjectsTestIntfI : TestObjectsTestIntf<TestObjectsTestIntf>
-(TestObjectsBase*) opDerived:(ICECurrent *)current;
-(void) throwDerived:(ICECurrent *)current;
@end
