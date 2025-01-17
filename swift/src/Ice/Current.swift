//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `Current.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

import Foundation

/// Information about the current method invocation for servers. Each operation on the server has a
/// Current as its implicit final parameter. Current is mostly used for Ice services. Most
/// applications ignore this parameter.
public class Current {
    /// The object adapter.
    public var adapter: ObjectAdapter? = nil
    /// Information about the connection over which the current method invocation was received. If the invocation is
    /// direct due to collocation optimization, this value is set to null.
    public var con: Connection? = nil
    /// The Ice object identity.
    public var id: Identity = Identity()
    /// The facet.
    public var facet: Swift.String = ""
    /// The operation name.
    public var operation: Swift.String = ""
    /// The mode of the operation.
    public var mode: OperationMode = .Normal
    /// The request context, as received from the client.
    public var ctx: Context = Context()
    /// The request id unless oneway (0).
    public var requestId: Swift.Int32 = 0
    /// The encoding version used to encode the input and output parameters.
    public var encoding: EncodingVersion = EncodingVersion()

    public init() {}

    public init(adapter: ObjectAdapter?, con: Connection?, id: Identity, facet: Swift.String, operation: Swift.String, mode: OperationMode, ctx: Context, requestId: Swift.Int32, encoding: EncodingVersion) {
        self.adapter = adapter
        self.con = con
        self.id = id
        self.facet = facet
        self.operation = operation
        self.mode = mode
        self.ctx = ctx
        self.requestId = requestId
        self.encoding = encoding
    }
}
