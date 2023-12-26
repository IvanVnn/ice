//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `Types.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __IceBT_Types_h__
#define __IceBT_Types_h__

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
#include <Ice/ExceptionHelpers.h>
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

#ifndef ICEBT_API
#   if defined(ICE_STATIC_LIBS)
#       define ICEBT_API /**/
#   elif defined(ICEBT_API_EXPORTS)
#       define ICEBT_API ICE_DECLSPEC_EXPORT
#   else
#       define ICEBT_API ICE_DECLSPEC_IMPORT
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace IceBT
{

/**
 * Indicates a failure in the Bluetooth plug-in.
 * \headerfile IceBT/IceBT.h
 */
class ICE_CLASS(ICEBT_API) BluetoothException : public ::Ice::LocalExceptionHelper<BluetoothException, ::Ice::LocalException>
{
public:

    ICE_MEMBER(ICEBT_API) virtual ~BluetoothException();

    BluetoothException(const BluetoothException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    BluetoothException(const char* file, int line) : ::Ice::LocalExceptionHelper<BluetoothException, ::Ice::LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason Provides more information about the failure.
     */
    BluetoothException(const char* file, int line, const ::std::string& reason) : ::Ice::LocalExceptionHelper<BluetoothException, ::Ice::LocalException>(file, line),
        reason(reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICEBT_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICEBT_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * Provides more information about the failure.
     */
    ::std::string reason;
};

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

#else // C++98 mapping

namespace IceBT
{

/**
 * Indicates a failure in the Bluetooth plug-in.
 * \headerfile IceBT/IceBT.h
 */
class ICEBT_API BluetoothException : public ::Ice::LocalException
{
public:

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    BluetoothException(const char* file, int line);
    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason Provides more information about the failure.
     */
    BluetoothException(const char* file, int line, const ::std::string& reason);

#ifdef ICE_CPP11_COMPILER
    BluetoothException(const BluetoothException&) = default;
    virtual ~BluetoothException();
#else
    virtual ~BluetoothException() throw();
#endif

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    virtual ::std::string ice_id() const;
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    virtual void ice_print(::std::ostream& stream) const;
    /**
     * Polymorphically clones this exception.
     * @return A shallow copy of this exception.
     */
    virtual BluetoothException* ice_clone() const;
    /**
     * Throws this exception.
     */
    virtual void ice_throw() const;

    /**
     * Provides more information about the failure.
     */
    ::std::string reason;
};

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif