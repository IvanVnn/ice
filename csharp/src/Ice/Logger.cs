//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `Logger.ice'
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
    public partial interface Logger
    {
        #region Slice operations


        /// <summary>
        /// Print a message.
        /// The message is printed literally, without any decorations such as executable name or time
        ///  stamp.
        /// </summary>
        ///  <param name="message">The message to log.</param>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        void print(string message);


        /// <summary>
        /// Log a trace message.
        /// </summary>
        /// <param name="category">The trace category.
        ///  </param>
        /// <param name="message">The trace message to log.</param>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        void trace(string category, string message);


        /// <summary>
        /// Log a warning message.
        /// </summary>
        /// <param name="message">The warning message to log.
        ///  </param>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        void warning(string message);


        /// <summary>
        /// Log an error message.
        /// </summary>
        /// <param name="message">The error message to log.
        ///  </param>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        void error(string message);


        /// <summary>
        /// Returns this logger's prefix.
        /// </summary>
        /// <returns>The prefix.</returns>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        string getPrefix();


        /// <summary>
        /// Returns a clone of the logger with a new prefix.
        /// </summary>
        /// <param name="prefix">The new prefix for the logger.
        ///  </param>
        /// <returns>A logger instance.</returns>

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("slice2cs", "3.7.10")]
        Logger cloneWithPrefix(string prefix);

        #endregion
    }
}

namespace Ice
{
}