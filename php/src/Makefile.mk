#
# Copyright (c) ZeroC, Inc. All rights reserved.
#

$(project)_libraries := IcePHP

IcePHP_target           := php-module
IcePHP_targetname       := ice
IcePHP_targetdir        := lib
IcePHP_installdir       := $(install_phplibdir)
IcePHP_cppflags         := -I$(project) -I$(top_srcdir)/cpp/src $(ice_cpp_cppflags) $(php_cppflags)
IcePHP_ldflags          := $(php_ldflags)
IcePHP_dependencies     := IceDiscovery IceLocatorDiscovery IceSSL Ice
IcePHP_extra_sources    := $(filter-out %Util.cpp %Ruby.cpp,\
                           $(wildcard $(top_srcdir)/cpp/src/Slice/*.cpp)) \
                           $(top_srcdir)/cpp/src/Slice/SliceUtil.cpp \
                           $(top_srcdir)/cpp/src/Slice/PHPUtil.cpp \
                           $(top_srcdir)/cpp/src/Slice/StringLiteralUtil.cpp \

projects += $(project)
srcs:: $(project)
