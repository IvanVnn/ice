//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `InstrumentationF.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_InstrumentationF_h__
#define __Ice_InstrumentationF_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <IceUtil/ScopedArray.h>
#include <Ice/Optional.h>
#include <IceUtil/UndefSysMacros.h>

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

#ifndef ICE_API
#   if defined(ICE_STATIC_LIBS)
#       define ICE_API /**/
#   elif defined(ICE_API_EXPORTS)
#       define ICE_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace Ice
{


namespace Instrumentation
{

class Observer;
class CommunicatorObserver;

}

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

/// \cond INTERNAL
namespace Ice
{

/// \cond INTERNAL
namespace Instrumentation
{

using ObserverPtr = ::std::shared_ptr<Observer>;

using CommunicatorObserverPtr = ::std::shared_ptr<CommunicatorObserver>;

}
/// \endcond

}
/// \endcond

#else // C++98 mapping

namespace Ice
{

namespace Instrumentation
{

class Observer;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(Observer*);
/// \endcond
typedef ::IceInternal::Handle< Observer> ObserverPtr;

class CommunicatorObserver;
/// \cond INTERNAL
ICE_API ::Ice::LocalObject* upCast(CommunicatorObserver*);
/// \endcond
typedef ::IceInternal::Handle< CommunicatorObserver> CommunicatorObserverPtr;

}

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
