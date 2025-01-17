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

import Foundation

/// The Ice message logger. Applications can provide their own logger by implementing this interface and installing it
/// in a communicator.
public protocol Logger:  Swift.AnyObject {
    /// Print a message. The message is printed literally, without any decorations such as executable name or time
    /// stamp.
    ///
    /// - parameter _: `Swift.String` The message to log.
    func print(_ message: Swift.String)

    /// Log a trace message.
    ///
    /// - parameter category: `Swift.String` The trace category.
    ///
    /// - parameter message: `Swift.String` The trace message to log.
    func trace(category: Swift.String, message: Swift.String)

    /// Log a warning message.
    ///
    /// - parameter _: `Swift.String` The warning message to log.
    func warning(_ message: Swift.String)

    /// Log an error message.
    ///
    /// - parameter _: `Swift.String` The error message to log.
    func error(_ message: Swift.String)

    /// Returns this logger's prefix.
    ///
    /// - returns: `Swift.String` - The prefix.
    func getPrefix() -> Swift.String

    /// Returns a clone of the logger with a new prefix.
    ///
    /// - parameter _: `Swift.String` The new prefix for the logger.
    ///
    /// - returns: `Logger` - A logger instance.
    func cloneWithPrefix(_ prefix: Swift.String) -> Logger
}
