#
# Copyright (c) ZeroC, Inc. All rights reserved.
#

$(project)_libraries            = IceSSLObjC

IceSSLObjC_targetdir            := $(libdir)
IceSSLObjC_cppflags             := -DICESSL_API_EXPORTS -Isrc/Ice $(ice_cpp_cppflags)
IceSSLObjC_dependencies         := IceObjC IceSSL Ice
IceSSLObjC_includedir           := $(includedir)/objc/IceSSL

IceSSLObjC_install:: $(install_includedir)/objc/IceSSL.h

projects += $(project)
