//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `ImplicitContext.ice'
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
    public partial interface ImplicitContext
    {
        #region Slice operations


        /// <summary>
        /// Get a copy of the underlying context.
        /// </summary>
        /// <returns>A copy of the underlying context.</returns>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        global::System.Collections.Generic.Dictionary<string, string> getContext();


        /// <summary>
        /// Set the underlying context.
        /// </summary>
        /// <param name="newContext">The new context.</param>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        void setContext(global::System.Collections.Generic.Dictionary<string, string> newContext);


        /// <summary>
        /// Check if this key has an associated value in the underlying context.
        /// </summary>
        /// <param name="key">The key.
        ///  </param>
        /// <returns>True if the key has an associated value, False otherwise.</returns>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        bool containsKey(string key);


        /// <summary>
        /// Get the value associated with the given key in the underlying context.
        /// Returns an empty string if no value is
        ///  associated with the key. containsKey allows you to distinguish between an empty-string value and no
        ///  value at all.
        /// </summary>
        ///  <param name="key">The key.
        ///  </param>
        /// <returns>The value associated with the key.</returns>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        string get(string key);


        /// <summary>
        /// Create or update a key/value entry in the underlying context.
        /// </summary>
        /// <param name="key">The key.
        ///  </param>
        /// <param name="value">The value.
        ///  </param>
        /// <returns>The previous value associated with the key, if any.</returns>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        string put(string key, string value);


        /// <summary>
        /// Remove the entry for the given key in the underlying context.
        /// </summary>
        /// <param name="key">The key.
        ///  </param>
        /// <returns>The value associated with the key, if any.</returns>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        string remove(string key);

        #endregion
    }
}

namespace Ice
{
}