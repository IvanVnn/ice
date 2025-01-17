//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `Instrumentation.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <IceStorm/Instrumentation.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ValueFactory.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/InputStream.h>
#include <Ice/OutputStream.h>
#include <Ice/LocalException.h>
#include <IceUtil/PopDisableWarnings.h>

#if defined(_MSC_VER)
#   pragma warning(disable:4458) // declaration of ... hides class member
#elif defined(__clang__)
#   pragma clang diagnostic ignored "-Wshadow"
#elif defined(__GNUC__)
#   pragma GCC diagnostic ignored "-Wshadow"
#endif

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 >= 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 10
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace
{

}

IceStorm::Instrumentation::TopicObserver::~TopicObserver()
{
}

IceStorm::Instrumentation::SubscriberObserver::~SubscriberObserver()
{
}

IceStorm::Instrumentation::ObserverUpdater::~ObserverUpdater()
{
}

IceStorm::Instrumentation::TopicManagerObserver::~TopicManagerObserver()
{
}

#else // C++98 mapping

namespace
{

namespace
{

}

}

IceStorm::Instrumentation::TopicObserver::~TopicObserver()
{
}

/// \cond INTERNAL
::Ice::LocalObject* IceStorm::Instrumentation::upCast(TopicObserver* p) { return p; }
/// \endcond

IceStorm::Instrumentation::SubscriberObserver::~SubscriberObserver()
{
}

/// \cond INTERNAL
::Ice::LocalObject* IceStorm::Instrumentation::upCast(SubscriberObserver* p) { return p; }
/// \endcond

IceStorm::Instrumentation::ObserverUpdater::~ObserverUpdater()
{
}

/// \cond INTERNAL
::Ice::LocalObject* IceStorm::Instrumentation::upCast(ObserverUpdater* p) { return p; }
/// \endcond

IceStorm::Instrumentation::TopicManagerObserver::~TopicManagerObserver()
{
}

/// \cond INTERNAL
::Ice::LocalObject* IceStorm::Instrumentation::upCast(TopicManagerObserver* p) { return p; }
/// \endcond

namespace Ice
{
}

#endif
