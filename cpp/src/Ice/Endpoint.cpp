//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `Endpoint.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef ICE_API_EXPORTS
#   define ICE_API_EXPORTS
#endif
#include <Ice/Endpoint.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/InputStream.h>
#include <Ice/OutputStream.h>
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

Ice::EndpointInfo::~EndpointInfo()
{
}

Ice::Endpoint::~Endpoint()
{
}

Ice::IPEndpointInfo::~IPEndpointInfo()
{
}

Ice::TCPEndpointInfo::~TCPEndpointInfo()
{
}

Ice::UDPEndpointInfo::~UDPEndpointInfo()
{
}

Ice::WSEndpointInfo::~WSEndpointInfo()
{
}

Ice::OpaqueEndpointInfo::~OpaqueEndpointInfo()
{
}

#else // C++98 mapping

namespace
{

}

Ice::EndpointInfo::~EndpointInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(EndpointInfo* p) { return p; }
/// \endcond

Ice::Endpoint::~Endpoint()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(Endpoint* p) { return p; }
/// \endcond

Ice::IPEndpointInfo::~IPEndpointInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(IPEndpointInfo* p) { return p; }
/// \endcond

Ice::TCPEndpointInfo::~TCPEndpointInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(TCPEndpointInfo* p) { return p; }
/// \endcond

Ice::UDPEndpointInfo::~UDPEndpointInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(UDPEndpointInfo* p) { return p; }
/// \endcond

Ice::WSEndpointInfo::~WSEndpointInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(WSEndpointInfo* p) { return p; }
/// \endcond

Ice::OpaqueEndpointInfo::~OpaqueEndpointInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(OpaqueEndpointInfo* p) { return p; }
/// \endcond

namespace Ice
{
}

#endif
