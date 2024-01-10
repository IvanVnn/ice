# -*- coding: utf-8 -*-
#
# Copyright (c) ZeroC, Inc. All rights reserved.
#
#
# Ice version 3.7.10
#
# <auto-generated>
#
# Generated from file `Current.ice'
#
# Warning: do not edit this file.
#
# </auto-generated>
#

from sys import version_info as _version_info_
import Ice, IcePy
import Ice.ObjectAdapterF_local
import Ice.ConnectionF_local
import Ice.Context_ice
import Ice.Identity_ice
import Ice.OperationMode_ice
import Ice.Version_ice

# Included module Ice
_M_Ice = Ice.openModule('Ice')

# Start of module Ice
__name__ = 'Ice'

if 'Current' not in _M_Ice.__dict__:
    _M_Ice.Current = Ice.createTempClass()
    class Current(object):
        """
         Information about the current method invocation for servers. Each operation on the server has a
         Current as its implicit final parameter. Current is mostly used for Ice services. Most
         applications ignore this parameter.
        Members:
        adapter --  The object adapter.
        con --  Information about the connection over which the current method invocation was received. If the invocation is
         direct due to collocation optimization, this value is set to null.
        id --  The Ice object identity.
        facet --  The facet.
        operation --  The operation name.
        mode --  The mode of the operation.
        ctx --  The request context, as received from the client.
        requestId --  The request id unless oneway (0).
        encoding --  The encoding version used to encode the input and output parameters.
        """
        def __init__(self, adapter=None, con=None, id=Ice._struct_marker, facet='', operation='', mode=_M_Ice.OperationMode.Normal, ctx=None, requestId=0, encoding=Ice._struct_marker):
            self.adapter = adapter
            self.con = con
            if id is Ice._struct_marker:
                self.id = _M_Ice.Identity()
            else:
                self.id = id
            self.facet = facet
            self.operation = operation
            self.mode = mode
            self.ctx = ctx
            self.requestId = requestId
            if encoding is Ice._struct_marker:
                self.encoding = _M_Ice.EncodingVersion()
            else:
                self.encoding = encoding

        def __eq__(self, other):
            if other is None:
                return False
            elif not isinstance(other, _M_Ice.Current):
                return NotImplemented
            else:
                if self.adapter != other.adapter:
                    return False
                if self.con != other.con:
                    return False
                if self.id != other.id:
                    return False
                if self.facet != other.facet:
                    return False
                if self.operation != other.operation:
                    return False
                if self.mode != other.mode:
                    return False
                if self.ctx != other.ctx:
                    return False
                if self.requestId != other.requestId:
                    return False
                if self.encoding != other.encoding:
                    return False
                return True

        def __ne__(self, other):
            return not self.__eq__(other)

        def __str__(self):
            return IcePy.stringify(self, _M_Ice._t_Current)

        __repr__ = __str__

    _M_Ice._t_Current = IcePy.defineStruct('::Ice::Current', Current, (), (
        ('adapter', (), _M_Ice._t_ObjectAdapter),
        ('con', (), _M_Ice._t_Connection),
        ('id', (), _M_Ice._t_Identity),
        ('facet', (), IcePy._t_string),
        ('operation', (), IcePy._t_string),
        ('mode', (), _M_Ice._t_OperationMode),
        ('ctx', (), _M_Ice._t_Context),
        ('requestId', (), IcePy._t_int),
        ('encoding', (), _M_Ice._t_EncodingVersion)
    ))

    _M_Ice.Current = Current
    del Current

# End of module Ice