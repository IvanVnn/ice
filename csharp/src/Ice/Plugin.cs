//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `Plugin.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//


using _System = global::System;

#pragma warning disable 1591

namespace Ice
{
    [global::System.Runtime.InteropServices.ComVisible(false)]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1704")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1707")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1709")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1710")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1711")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1715")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1716")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1720")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1722")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1724")]
    public partial interface Plugin
    {
        #region Slice operations


        /// <summary>
        /// Perform any necessary initialization steps.
        /// </summary>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        void initialize();


        /// <summary>
        /// Called when the communicator is being destroyed.
        /// </summary>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        void destroy();

        #endregion
    }

    [global::System.Runtime.InteropServices.ComVisible(false)]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1704")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1707")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1709")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1710")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1711")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1715")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1716")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1720")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1722")]
    [global::System.Diagnostics.CodeAnalysis.SuppressMessage("Microsoft.Naming", "CA1724")]
    public partial interface PluginManager
    {
        #region Slice operations


        /// <summary>
        /// Initialize the configured plug-ins.
        /// The communicator automatically initializes the plug-ins by default, but an
        ///  application may need to interact directly with a plug-in prior to initialization. In this case, the application
        ///  must set Ice.InitPlugins=0 and then invoke initializePlugins manually. The plug-ins are
        ///  initialized in the order in which they are loaded. If a plug-in raises an exception during initialization, the
        ///  communicator invokes destroy on the plug-ins that have already been initialized.
        /// </summary>
        ///  <exception name="InitializationException">Raised if the plug-ins have already been initialized.</exception>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        void initializePlugins();


        /// <summary>
        /// Get a list of plugins installed.
        /// </summary>
        /// <returns>The names of the plugins installed.
        ///  </returns>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        string[] getPlugins();


        /// <summary>
        /// Obtain a plug-in by name.
        /// </summary>
        /// <param name="name">The plug-in's name.
        ///  </param>
        /// <returns>The plug-in.
        ///  </returns>
        /// <exception name="NotRegisteredException">Raised if no plug-in is found with the given name.</exception>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        Plugin getPlugin(string name);


        /// <summary>
        /// Install a new plug-in.
        /// </summary>
        /// <param name="name">The plug-in's name.
        ///  </param>
        /// <param name="pi">The plug-in.
        ///  </param>
        /// <exception name="AlreadyRegisteredException">Raised if a plug-in already exists with the given name.</exception>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        void addPlugin(string name, Plugin pi);


        /// <summary>
        /// Called when the communicator is being destroyed.
        /// </summary>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        void destroy();

        #endregion
    }
}

namespace Ice
{
}
