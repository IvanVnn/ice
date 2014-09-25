// **********************************************************************
//
// Copyright (c) 2003-2014 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

var Ice = require("../Ice/ModuleRegistry").Ice;
Ice.__M.require(module, ["../Ice/Class", "../Ice/LocalException"]);

var Class = Ice.Class;

var RetryQueue = Class({
    __init__: function(instance)
    {
        this._instance = instance;
        this._requests = [];
    },
    add: function(outAsync, interval)
    {
        if(this._instance === null)
        {
            throw new Ice.CommunicatorDestroyedException();
        }
        var task = new RetryTask(this, outAsync);
        task.token = this._instance.timer().schedule(function()
                                                     {
                                                         task.run();
                                                     }, interval);
        this._requests.push(task);
    },
    destroy: function()
    {
        for(var i = 0; i < this._requests.length; ++i)
        {
            this._instance.timer().cancel(this._requests[i].token);
            this._requests[i].destroy();
        }
        this._requests = [];
        this._instance = null; 
    },
    remove: function(task)
    {
        var idx = this._requests.indexOf(task);
        if(idx >= 0)
        {
            this._requests.splice(idx, 1);
        }
    }
});
Ice.RetryQueue = RetryQueue;

var RetryTask = Class({
    __init__: function(queue, outAsync, interval)
    {
        this.queue = queue;
        this.outAsync = outAsync;
    },
    run: function()
    {
        try
        {
            this.outAsync.__invoke();
        }
        catch(ex)
        {
            this.outAsync.__invokeException(ex);
        }
        this.queue.remove(this);
    },
    destroy: function()
    {
        this.outAsync.__invokeException(new Ice.CommunicatorDestroyedException());
    }
});
module.exports.Ice = Ice;
