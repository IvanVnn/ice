//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `EndpointF.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_EndpointF_h__
#define __Ice_EndpointF_h__

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

class EndpointInfo;
class IPEndpointInfo;
class TCPEndpointInfo;
class UDPEndpointInfo;
class WSEndpointInfo;
class Endpoint;

}

namespace Ice
{

/**
 * A sequence of endpoints.
 */
using EndpointSeq = ::std::vector<::std::shared_ptr<Endpoint>>;

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

/// \cond INTERNAL
namespace Ice
{

using EndpointInfoPtr = ::std::shared_ptr<EndpointInfo>;

using IPEndpointInfoPtr = ::std::shared_ptr<IPEndpointInfo>;

using TCPEndpointInfoPtr = ::std::shared_ptr<TCPEndpointInfo>;

using UDPEndpointInfoPtr = ::std::shared_ptr<UDPEndpointInfo>;

using WSEndpointInfoPtr = ::std::shared_ptr<WSEndpointInfo>;

using EndpointPtr = ::std::shared_ptr<Endpoint>;

}
/// \endcond

#else // C++98 mapping

namespace Ice
{

class EndpointInfo;
/// \cond INTERNAL
ICE_API LocalObject* upCast(EndpointInfo*);
/// \endcond
typedef ::IceInternal::Handle< EndpointInfo> EndpointInfoPtr;

class IPEndpointInfo;
/// \cond INTERNAL
ICE_API LocalObject* upCast(IPEndpointInfo*);
/// \endcond
typedef ::IceInternal::Handle< IPEndpointInfo> IPEndpointInfoPtr;

class TCPEndpointInfo;
/// \cond INTERNAL
ICE_API LocalObject* upCast(TCPEndpointInfo*);
/// \endcond
typedef ::IceInternal::Handle< TCPEndpointInfo> TCPEndpointInfoPtr;

class UDPEndpointInfo;
/// \cond INTERNAL
ICE_API LocalObject* upCast(UDPEndpointInfo*);
/// \endcond
typedef ::IceInternal::Handle< UDPEndpointInfo> UDPEndpointInfoPtr;

class WSEndpointInfo;
/// \cond INTERNAL
ICE_API LocalObject* upCast(WSEndpointInfo*);
/// \endcond
typedef ::IceInternal::Handle< WSEndpointInfo> WSEndpointInfoPtr;

class Endpoint;
/// \cond INTERNAL
ICE_API LocalObject* upCast(Endpoint*);
/// \endcond
typedef ::IceInternal::Handle< Endpoint> EndpointPtr;

}

namespace Ice
{

/**
 * A sequence of endpoints.
 */
typedef ::std::vector<EndpointPtr> EndpointSeq;

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
