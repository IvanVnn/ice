//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#ifndef ICEGRID_NODE_SESSION_H
#define ICEGRID_NODE_SESSION_H

#include <IceGrid/Internal.h>
#include <set>

namespace IceGrid
{

class Database;
class TraceLevels;

class PatcherFeedbackAggregator
{
public:

    PatcherFeedbackAggregator(
        Ice::Identity,
        const std::shared_ptr<TraceLevels>&,
        const std::string&,
        const std::string&,
        int);
    virtual ~PatcherFeedbackAggregator();

    void finished(const std::string&);
    void failed(std::string, const std::string&);

protected:

    virtual void exception(std::exception_ptr) = 0;
    virtual void response() = 0;

private:

    void checkIfDone();

    const Ice::Identity _id;
    const std::shared_ptr<TraceLevels> _traceLevels;
    const std::string _type;
    const std::string _name;
    const int _count;
    std::set<std::string> _successes;
    std::set<std::string> _failures;
    Ice::StringSeq _reasons;
    std::mutex _mutex;
};

class NodeSessionI : public NodeSession, public std::enable_shared_from_this<NodeSessionI>
{
public:

    static std::shared_ptr<NodeSessionI> create(const std::shared_ptr<Database>&, const std::shared_ptr<NodePrx>&,
                                                const std::shared_ptr<InternalNodeInfo>&,
                                                std::chrono::seconds, const LoadInfo&);

    void keepAlive(LoadInfo, const Ice::Current&) override;
    void setReplicaObserver(std::shared_ptr<ReplicaObserverPrx>, const Ice::Current&) override;
    int getTimeout(const Ice::Current&) const override;
    std::shared_ptr<NodeObserverPrx> getObserver(const Ice::Current&) const override;
    void loadServersAsync(std::function<void()>, std::function<void(std::exception_ptr)>,
                          const Ice::Current&) const override;
    Ice::StringSeq getServers(const Ice::Current&) const override;
    void waitForApplicationUpdateAsync(std::string, int, std::function<void()>, std::function<void(std::exception_ptr)>,
                                       const Ice::Current&) const override;
    void destroy(const Ice::Current&) override;

    std::chrono::steady_clock::time_point timestamp() const;
    void shutdown();
    void patch(
        const std::shared_ptr<PatcherFeedbackAggregator>&,
        const std::string&,
        const std::string&,
        const std::shared_ptr<InternalDistributionDescriptor>&, bool);

    const std::shared_ptr<NodePrx>& getNode() const;
    const std::shared_ptr<InternalNodeInfo>& getInfo() const;
    const LoadInfo& getLoadInfo() const;
    std::shared_ptr<NodeSessionPrx> getProxy() const;

    bool isDestroyed() const;
    void removeFeedback(const std::shared_ptr<PatcherFeedback>&, const Ice::Identity&);

private:

    NodeSessionI(const std::shared_ptr<Database>&, const std::shared_ptr<NodePrx>&,
                 const std::shared_ptr<InternalNodeInfo>&, std::chrono::seconds, const LoadInfo&);

    void destroyImpl(bool);

    const std::shared_ptr<Database> _database;
    const std::shared_ptr<TraceLevels> _traceLevels;
    const std::string _name;
    const std::shared_ptr<NodePrx> _node;
    const std::shared_ptr<InternalNodeInfo> _info;
    const std::chrono::seconds _timeout;
    std::shared_ptr<NodeSessionPrx> _proxy;
    std::shared_ptr<ReplicaObserverPrx> _replicaObserver;
    std::chrono::steady_clock::time_point _timestamp;
    LoadInfo _load;
    bool _destroy;
    std::set<std::shared_ptr<PatcherFeedback>> _feedbacks;

    mutable std::mutex _mutex;
};

};

#endif
