//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `Connection.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef ICE_API_EXPORTS
#   define ICE_API_EXPORTS
#endif
#include <Ice/Connection.h>
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

Ice::ConnectionInfo::~ConnectionInfo()
{
}

Ice::Connection::~Connection()
{
}

Ice::IPConnectionInfo::~IPConnectionInfo()
{
}

Ice::TCPConnectionInfo::~TCPConnectionInfo()
{
}

Ice::UDPConnectionInfo::~UDPConnectionInfo()
{
}

Ice::WSConnectionInfo::~WSConnectionInfo()
{
}

namespace Ice
{
}

#else // C++98 mapping

namespace
{

}

Ice::ConnectionInfo::~ConnectionInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(ConnectionInfo* p) { return p; }
/// \endcond

Ice::CloseCallback::~CloseCallback()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(CloseCallback* p) { return p; }
/// \endcond

Ice::HeartbeatCallback::~HeartbeatCallback()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(HeartbeatCallback* p) { return p; }
/// \endcond

Ice::Connection::~Connection()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(Connection* p) { return p; }
/// \endcond

Ice::IPConnectionInfo::~IPConnectionInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(IPConnectionInfo* p) { return p; }
/// \endcond

Ice::TCPConnectionInfo::~TCPConnectionInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(TCPConnectionInfo* p) { return p; }
/// \endcond

Ice::UDPConnectionInfo::~UDPConnectionInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(UDPConnectionInfo* p) { return p; }
/// \endcond

Ice::WSConnectionInfo::~WSConnectionInfo()
{
}

/// \cond INTERNAL
ICE_API ::Ice::LocalObject* Ice::upCast(WSConnectionInfo* p) { return p; }
/// \endcond

namespace Ice
{
}

#endif
