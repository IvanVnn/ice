//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#include <TestI.h>
#include <Ice/Ice.h>
#include <TestHelper.h>

using namespace Test;
using namespace std;

namespace
{

void breakCycles(Ice::ValuePtr);

template<typename T>
void breakCycles(const vector<ICE_SHARED_PTR<T>>& s)
{
    for(auto e : s)
    {
        breakCycles(e);
    }
}

template<typename K, typename V>
void breakCycles(const map<K, ICE_SHARED_PTR<V>>& d)
{
    for(auto e : d)
    {
        breakCycles(e.second);
    }
}

void breakCycles(Ice::ValuePtr o)
{
    if(ICE_DYNAMIC_CAST(D1, o))
    {
        auto d1 = ICE_DYNAMIC_CAST(D1, o);
        auto tmp = d1->pd1;
        d1->pd1 = nullptr;
        if(tmp != d1)
        {
            breakCycles(tmp);
        }
    }
    if(ICE_DYNAMIC_CAST(D2, o))
    {
        auto d2 = ICE_DYNAMIC_CAST(D2, o);
        d2->pd2 = nullptr;
    }
    if(ICE_DYNAMIC_CAST(D4, o))
    {
        auto d4 = ICE_DYNAMIC_CAST(D4, o);
        d4->p1 = nullptr;
        d4->p2 = nullptr;
    }
    if(ICE_DYNAMIC_CAST(B, o))
    {
        auto b = ICE_DYNAMIC_CAST(B, o);
        if(b->pb)
        {
            b->pb->pb = nullptr;
        }
        b->pb = nullptr;
    }
    if(ICE_DYNAMIC_CAST(Preserved, o))
    {
        auto p = ICE_DYNAMIC_CAST(Preserved, o);
        if(p->ice_getSlicedData())
        {
            p->ice_getSlicedData()->clear();
        }
    }
    if(ICE_DYNAMIC_CAST(PDerived, o))
    {
        auto p = ICE_DYNAMIC_CAST(PDerived, o);
        p->pb = nullptr;
    }
    if(ICE_DYNAMIC_CAST(CompactPDerived, o))
    {
        auto p = ICE_DYNAMIC_CAST(CompactPDerived, o);
        p->pb = nullptr;
    }
    if(ICE_DYNAMIC_CAST(PNode, o))
    {
        auto curr = ICE_DYNAMIC_CAST(PNode, o);
        while(curr && o != curr->next)
        {
            curr = curr->next;
        }
        if(curr && o == curr->next)
        {
            curr->next = nullptr;
        }
    }
    if(ICE_DYNAMIC_CAST(PSUnknown, o))
    {
        auto p = ICE_DYNAMIC_CAST(PSUnknown, o);
        breakCycles(p->graph);
    }
    if(ICE_DYNAMIC_CAST(PSUnknown2, o))
    {
        auto p = ICE_DYNAMIC_CAST(PSUnknown2, o);
        p->pb = nullptr;
    }
    if(ICE_DYNAMIC_CAST(SS1, o))
    {
        auto s = ICE_DYNAMIC_CAST(SS1, o);
        breakCycles(s->s);
    }
    if(ICE_DYNAMIC_CAST(SS2, o))
    {
        auto s = ICE_DYNAMIC_CAST(SS2, o);
        breakCycles(s->s);
    }
    if(ICE_DYNAMIC_CAST(Forward, o))
    {
        auto f = ICE_DYNAMIC_CAST(Forward, o);
        f->h = nullptr;
    }
    if(ICE_DYNAMIC_CAST(SUnknown, o))
    {
        auto u = ICE_DYNAMIC_CAST(SUnknown, o);
        u->cycle = nullptr;
    }
}

}

TestI::TestI()
{
}

TestI::~TestI()
{
    for(auto e : _values)
    {
        breakCycles(e);
    }
}

Ice::ValuePtr
TestI::SBaseAsObject(const ::Ice::Current&)
{
    SBasePtr sb = ICE_MAKE_SHARED(SBase);
    sb->sb = "SBase.sb";
    return sb;
}

SBasePtr
TestI::SBaseAsSBase(const ::Ice::Current&)
{
    SBasePtr sb = ICE_MAKE_SHARED(SBase);
    sb->sb = "SBase.sb";
    return sb;
}

SBasePtr
TestI::SBSKnownDerivedAsSBase(const ::Ice::Current&)
{
    SBSKnownDerivedPtr sbskd = ICE_MAKE_SHARED(SBSKnownDerived);
    sbskd->sb = "SBSKnownDerived.sb";
    sbskd->sbskd = "SBSKnownDerived.sbskd";
    return sbskd;
}

SBSKnownDerivedPtr
TestI::SBSKnownDerivedAsSBSKnownDerived(const ::Ice::Current&)
{
    SBSKnownDerivedPtr sbskd = ICE_MAKE_SHARED(SBSKnownDerived);
    sbskd->sb = "SBSKnownDerived.sb";
    sbskd->sbskd = "SBSKnownDerived.sbskd";
    return sbskd;
}

SBasePtr
TestI::SBSUnknownDerivedAsSBase(const ::Ice::Current&)
{
    SBSUnknownDerivedPtr sbsud = ICE_MAKE_SHARED(SBSUnknownDerived);
    sbsud->sb = "SBSUnknownDerived.sb";
    sbsud->sbsud = "SBSUnknownDerived.sbsud";
    return sbsud;
}

SBasePtr
TestI::SBSUnknownDerivedAsSBaseCompact(const ::Ice::Current&)
{
    SBSUnknownDerivedPtr sbsud = ICE_MAKE_SHARED(SBSUnknownDerived);
    sbsud->sb = "SBSUnknownDerived.sb";
    sbsud->sbsud = "SBSUnknownDerived.sbsud";
    return sbsud;
}

Ice::ValuePtr
TestI::SUnknownAsObject(const ::Ice::Current&)
{
    SUnknownPtr su = ICE_MAKE_SHARED(SUnknown);
    su->su = "SUnknown.su";
    su->cycle = su;
    _values.push_back(su);
    return su;
}

void
TestI::checkSUnknown(ICE_IN(Ice::ValuePtr) obj, const ::Ice::Current& current)
{
    SUnknownPtr su = ICE_DYNAMIC_CAST(SUnknown, obj);
    if(current.encoding == Ice::Encoding_1_0)
    {
        test(!su);
    }
    else
    {
        test(su);
        test(su->su == "SUnknown.su");
    }
    su->cycle = nullptr;
}

BPtr
TestI::oneElementCycle(const ::Ice::Current&)
{
    BPtr b = ICE_MAKE_SHARED(B);
    b->sb = "B1.sb";
    b->pb = b;
    _values.push_back(b);
    return b;
}

BPtr
TestI::twoElementCycle(const ::Ice::Current&)
{
    BPtr b1 = ICE_MAKE_SHARED(B);
    b1->sb = "B1.sb";
    BPtr b2 = ICE_MAKE_SHARED(B);
    b2->sb = "B2.sb";
    b2->pb = b1;
    b1->pb = b2;
    _values.push_back(b1);
    return b1;
}

BPtr
TestI::D1AsB(const ::Ice::Current&)
{
    D1Ptr d1 = ICE_MAKE_SHARED(D1);
    d1->sb = "D1.sb";
    d1->sd1 = "D1.sd1";
    D2Ptr d2 = ICE_MAKE_SHARED(D2);
    d2->pb = d1;
    d2->sb = "D2.sb";
    d2->sd2 = "D2.sd2";
    d2->pd2 = d1;
    d1->pb = d2;
    d1->pd1 = d2;
    _values.push_back(d1);
    return d1;
}

D1Ptr
TestI::D1AsD1(const ::Ice::Current&)
{
    D1Ptr d1 = ICE_MAKE_SHARED(D1);
    d1->sb = "D1.sb";
    d1->sd1 = "D1.sd1";
    D2Ptr d2 = ICE_MAKE_SHARED(D2);
    d2->pb = d1;
    d2->sb = "D2.sb";
    d2->sd2 = "D2.sd2";
    d2->pd2 = d1;
    d1->pb = d2;
    d1->pd1 = d2;
    _values.push_back(d1);
    return d1;
}

BPtr
TestI::D2AsB(const ::Ice::Current&)
{
    D2Ptr d2 = ICE_MAKE_SHARED(D2);
    d2->sb = "D2.sb";
    d2->sd2 = "D2.sd2";
    D1Ptr d1 = ICE_MAKE_SHARED(D1);
    d1->pb = d2;
    d1->sb = "D1.sb";
    d1->sd1 = "D1.sd1";
    d1->pd1 = d2;
    d2->pb = d1;
    d2->pd2 = d1;
    _values.push_back(d1);
    return d2;
}

void
TestI::paramTest1(BPtr& p1, BPtr& p2, const ::Ice::Current&)
{
    D1Ptr d1 = ICE_MAKE_SHARED(D1);
    d1->sb = "D1.sb";
    d1->sd1 = "D1.sd1";
    D2Ptr d2 = ICE_MAKE_SHARED(D2);
    d2->pb = d1;
    d2->sb = "D2.sb";
    d2->sd2 = "D2.sd2";
    d2->pd2 = d1;
    d1->pb = d2;
    d1->pd1 = d2;
    p1 = d1;
    p2 = d2;
    _values.push_back(d1);
}

void
TestI::paramTest2(BPtr& p1, BPtr& p2, const ::Ice::Current&)
{
    ::Ice::Current c;
    paramTest1(p2, p1, c);
}

BPtr
TestI::paramTest3(BPtr& p1, BPtr& p2, const ::Ice::Current&)
{
    D2Ptr d2 = ICE_MAKE_SHARED(D2);
    d2->sb = "D2.sb (p1 1)";
    d2->pb = 0;
    d2->sd2 = "D2.sd2 (p1 1)";
    p1 = d2;

    D1Ptr d1 = ICE_MAKE_SHARED(D1);
    d1->sb = "D1.sb (p1 2)";
    d1->pb = 0;
    d1->sd1 = "D1.sd2 (p1 2)";
    d1->pd1 = 0;
    d2->pd2 = d1;

    D2Ptr d4 = ICE_MAKE_SHARED(D2);
    d4->sb = "D2.sb (p2 1)";
    d4->pb = 0;
    d4->sd2 = "D2.sd2 (p2 1)";
    p2 = d4;

    D1Ptr d3 = ICE_MAKE_SHARED(D1);
    d3->sb = "D1.sb (p2 2)";
    d3->pb = 0;
    d3->sd1 = "D1.sd2 (p2 2)";
    d3->pd1 = 0;
    d4->pd2 = d3;

    _values.push_back(d1);
    _values.push_back(d2);
    _values.push_back(d3);
    _values.push_back(d4);

    return d3;
}

BPtr
TestI::paramTest4(BPtr& p1, const ::Ice::Current&)
{
    D4Ptr d4 = ICE_MAKE_SHARED(D4);
    d4->sb = "D4.sb (1)";
    d4->pb = 0;
    d4->p1 = ICE_MAKE_SHARED(B);
    d4->p1->sb = "B.sb (1)";
    d4->p2 = ICE_MAKE_SHARED(B);
    d4->p2->sb = "B.sb (2)";
    p1 = d4;
    _values.push_back(d4);
    return d4->p2;
}

BPtr
TestI::returnTest1(BPtr& p1, BPtr& p2, const ::Ice::Current&)
{
    ::Ice::Current c;
    paramTest1(p1, p2, c);
    return p1;
}

BPtr
TestI::returnTest2(BPtr& p1, BPtr& p2, const ::Ice::Current&)
{
    ::Ice::Current c;
    paramTest1(p2, p1, c);
    return p1;
}

BPtr
TestI::returnTest3(ICE_IN(BPtr) p1, ICE_IN(BPtr) p2, const ::Ice::Current&)
{
    _values.push_back(p1);
    _values.push_back(p2);
    return p1;
}

SS3
TestI::sequenceTest(ICE_IN(SS1Ptr) p1, ICE_IN(SS2Ptr) p2, const ::Ice::Current&)
{
    SS3 ss;
    ss.c1 = p1;
    ss.c2 = p2;
    _values.push_back(p1);
    _values.push_back(p2);
    return ss;
}

Test::BDict
TestI::dictionaryTest(ICE_IN(BDict) bin, BDict& bout, const ::Ice::Current&)
{
    int i;
    for(i = 0; i < 10; ++i)
    {
        BPtr b = bin.find(i)->second;
        D2Ptr d2 = ICE_MAKE_SHARED(D2);
        d2->sb = b->sb;
        d2->pb = b->pb;
        d2->sd2 = "D2";
        d2->pd2 = d2;
        _values.push_back(d2);
        bout[i * 10] = d2;
    }
    BDict r;
    for(i = 0; i < 10; ++i)
    {
        std::ostringstream s;
        s << "D1." << i * 20;
        D1Ptr d1 = ICE_MAKE_SHARED(D1);
        d1->sb = s.str();
        d1->pb = (i == 0 ? BPtr(0) : r.find((i - 1) * 20)->second);
        d1->sd1 = s.str();
        d1->pd1 = d1;
        _values.push_back(d1);
        r[i * 20] = d1;
    }
    return r;
}

Test::PBasePtr
TestI::exchangePBase(ICE_IN(Test::PBasePtr) pb, const Ice::Current&)
{
    _values.push_back(pb);
    return pb;
}

Test::PreservedPtr
TestI::PBSUnknownAsPreserved(const Ice::Current& current)
{
    PSUnknownPtr r = ICE_MAKE_SHARED(PSUnknown);
    r->pi = 5;
    r->ps = "preserved";
    r->psu = "unknown";
    r->graph = 0;
    if(current.encoding != Ice::Encoding_1_0)
    {
        //
        // 1.0 encoding doesn't support unmarshaling unknown classes even if referenced
        // from unread slice.
        //
        r->cl = ICE_MAKE_SHARED(MyClass, 15);
    }
    return r;
}

void
TestI::checkPBSUnknown(ICE_IN(Test::PreservedPtr) p, const Ice::Current& current)
{
    PSUnknownPtr pu =  ICE_DYNAMIC_CAST(PSUnknown, p);
    if(current.encoding == Ice::Encoding_1_0)
    {
        test(!pu);
        test(p->pi == 5);
        test(p->ps == "preserved");
    }
    else
    {
        test(pu);
        test(pu->pi == 5);
        test(pu->ps == "preserved");
        test(pu->psu == "unknown");
        test(!pu->graph);
        test(pu->cl && pu->cl->i == 15);
    }
}

#ifdef ICE_CPP11_MAPPING
void
TestI::PBSUnknownAsPreservedWithGraphAsync(function<void(const shared_ptr<Test::Preserved>&)> response,
                                            function<void(exception_ptr)>,
                                            const Ice::Current&)
#else
void
TestI::PBSUnknownAsPreservedWithGraph_async(const Test::AMD_TestIntf_PBSUnknownAsPreservedWithGraphPtr& cb,
                                            const Ice::Current&)
#endif
{
    PSUnknownPtr r = ICE_MAKE_SHARED(PSUnknown);
    r->pi = 5;
    r->ps = "preserved";
    r->psu = "unknown";
    r->graph = ICE_MAKE_SHARED(PNode);
    r->graph->next = ICE_MAKE_SHARED(PNode);
    r->graph->next->next = ICE_MAKE_SHARED(PNode);
    r->graph->next->next->next = r->graph;
#ifdef ICE_CPP11_MAPPING
    response(r);
#else
    cb->ice_response(r);
#endif
    r->graph->next->next->next = 0; // Break the cycle.
}

void
TestI::checkPBSUnknownWithGraph(ICE_IN(Test::PreservedPtr) p, const Ice::Current& current)
{
    PSUnknownPtr pu = ICE_DYNAMIC_CAST(PSUnknown, p);
    if(current.encoding == Ice::Encoding_1_0)
    {
        test(!pu);
        test(p->pi == 5);
        test(p->ps == "preserved");
    }
    else
    {
        test(pu);
        test(pu->pi == 5);
        test(pu->ps == "preserved");
        test(pu->psu == "unknown");
        test(pu->graph != pu->graph->next);
        test(pu->graph->next != pu->graph->next->next);
        test(pu->graph->next->next->next == pu->graph);
        pu->graph->next->next->next = 0; // Break the cycle.
    }
}

#ifdef ICE_CPP11_MAPPING
void
TestI::PBSUnknown2AsPreservedWithGraphAsync(function<void(const shared_ptr<Test::Preserved>&)> response,
                                             function<void(exception_ptr)>,
                                             const Ice::Current&)
#else
void
TestI::PBSUnknown2AsPreservedWithGraph_async(const Test::AMD_TestIntf_PBSUnknown2AsPreservedWithGraphPtr& cb,
                                             const Ice::Current&)
#endif
{
    PSUnknown2Ptr r = ICE_MAKE_SHARED(PSUnknown2);
    r->pi = 5;
    r->ps = "preserved";
    r->pb = r;
#ifdef ICE_CPP11_MAPPING
    response(r);
#else
    cb->ice_response(r);
#endif
    r->pb = 0; // Break the cycle.
}

void
TestI::checkPBSUnknown2WithGraph(ICE_IN(Test::PreservedPtr) p, const Ice::Current& current)
{
    PSUnknown2Ptr pu = ICE_DYNAMIC_CAST(PSUnknown2, p);
    if(current.encoding == Ice::Encoding_1_0)
    {
        test(!pu);
        test(p->pi == 5);
        test(p->ps == "preserved");
    }
    else
    {
        test(pu);
        test(pu->pi == 5);
        test(pu->ps == "preserved");
        test(pu->pb == pu);
        pu->pb = 0; // Break the cycle.
    }
}

Test::PNodePtr
TestI::exchangePNode(ICE_IN(Test::PNodePtr) pn, const Ice::Current&)
{
    _values.push_back(pn);
    return pn;
}

void
TestI::throwBaseAsBase(const ::Ice::Current&)
{
    BaseException be;
    be.sbe = "sbe";
    be.pb = ICE_MAKE_SHARED(B);
    be.pb->sb = "sb";
    be.pb->pb = be.pb;
    _values.push_back(be.pb);
    throw be;
}

void
TestI::throwDerivedAsBase(const ::Ice::Current&)
{
    DerivedException de;
    de.sbe = "sbe";
    de.pb = ICE_MAKE_SHARED(B);
    de.pb->sb = "sb1";
    de.pb->pb = de.pb;
    de.sde = "sde1";
    de.pd1 = ICE_MAKE_SHARED(D1);
    de.pd1->sb = "sb2";
    de.pd1->pb = de.pd1;
    de.pd1->sd1 = "sd2";
    de.pd1->pd1 = de.pd1;
    _values.push_back(de.pb);
    _values.push_back(de.pd1);
    throw de;
}

void
TestI::throwDerivedAsDerived(const ::Ice::Current&)
{
    DerivedException de;
    de.sbe = "sbe";
    de.pb = ICE_MAKE_SHARED(B);
    de.pb->sb = "sb1";
    de.pb->pb = de.pb;
    de.sde = "sde1";
    de.pd1 = ICE_MAKE_SHARED(D1);
    de.pd1->sb = "sb2";
    de.pd1->pb = de.pd1;
    de.pd1->sd1 = "sd2";
    de.pd1->pd1 = de.pd1;
    _values.push_back(de.pb);
    _values.push_back(de.pd1);
    throw de;
}

void
TestI::throwUnknownDerivedAsBase(const ::Ice::Current&)
{
    D2Ptr d2 = ICE_MAKE_SHARED(D2);
    d2->sb = "sb d2";
    d2->pb = d2;
    d2->sd2 = "sd2 d2";
    d2->pd2 = d2;
    _values.push_back(d2);
    UnknownDerivedException ude;
    ude.sbe = "sbe";
    ude.pb = d2;
    ude.sude = "sude";
    ude.pd2 = d2;
    throw ude;
}

#ifdef ICE_CPP11_MAPPING
void
TestI::throwPreservedExceptionAsync(function<void()>,
                                     function<void(exception_ptr)> exception,
                                     const ::Ice::Current&)
#else
void
TestI::throwPreservedException_async(const AMD_TestIntf_throwPreservedExceptionPtr& cb, const ::Ice::Current&)
#endif
{
    PSUnknownException ue;
    ue.p = ICE_MAKE_SHARED(PSUnknown2);
    ue.p->pi = 5;
    ue.p->ps = "preserved";
    ue.p->pb = ue.p;
#ifdef ICE_CPP11_MAPPING
    try
    {
        throw ue;
    }
    catch(...)
    {
        exception(current_exception());
    }
#else
    cb->ice_exception(ue);
#endif
    ue.p->pb = 0; // Break the cycle.
}

void
TestI::useForward(ForwardPtr& f, const ::Ice::Current&)
{
    f = ICE_MAKE_SHARED(Forward);
    f->h = ICE_MAKE_SHARED(Hidden);
    f->h->f = f;
    _values.push_back(f);
}

void
TestI::shutdown(const ::Ice::Current& current)
{
    current.adapter->getCommunicator()->shutdown();
}
