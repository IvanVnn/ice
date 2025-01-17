#
# Copyright (c) ZeroC, Inc. All rights reserved.
#

import Ice, Test

class IAI(Test.MA.IA):
    def iaop(self, p, current=None):
        return p

class IB1I(Test.MB.IB1, IAI):
    def ib1op(self, p, current=None):
        return p

class IB2I(Test.MB.IB2, IAI):
    def ib2op(self, p, current=None):
        return p

class ICI(Test.MA.IC, IB1I, IB2I):
    def icop(self, p, current=None):
        return p

class InitialI(Test.Initial):
    def __init__(self, adapter):
        self._ia = Test.MA.IAPrx.uncheckedCast(adapter.addWithUUID(IAI()))
        self._ib1 = Test.MB.IB1Prx.uncheckedCast(adapter.addWithUUID(IB1I()))
        self._ib2 = Test.MB.IB2Prx.uncheckedCast(adapter.addWithUUID(IB2I()))
        self._ic = Test.MA.ICPrx.uncheckedCast(adapter.addWithUUID(ICI()))

    def shutdown(self, current=None):
        current.adapter.getCommunicator().shutdown()

    def iaop(self, current=None):
        return self._ia

    def ib1op(self, current=None):
        return self._ib1

    def ib2op(self, current=None):
        return self._ib2

    def icop(self, current=None):
        return self._ic
