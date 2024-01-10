//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#pragma once

[["cpp:dll-export:ICE_API"]]
[["cpp:doxygen:include:Ice/Ice.h"]]
[["cpp:header-ext:h"]]

[["cpp:no-default-include"]]
[["cpp:include:Ice/Config.h"]]

[["ice-prefix"]]

[["js:module:ice"]]
[["js:cjs-module"]]

[["objc:dll-export:ICE_API"]]
[["objc:header-dir:objc"]]

[["python:pkgdir:Ice"]]

[["java:package:com.zeroc"]]

["objc:prefix:ICE"]
module Ice
{
    /// A simple collection of properties, represented as a dictionary of key/value pairs. Both key and value are
    /// strings.
    /// @see Properties#getPropertiesForPrefix
    dictionary<string, string> PropertyDict;
}