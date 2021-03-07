//
// This program is free software: you can redistribute it and/or modify
//
// Wireless interface used in Keetchi with functionality
// to handle sending of packets considering wireless range
// and broadcast of packets. It should have access to the
// mobility management components.
//
// @date: 08-11-2015
// @author: Asanga Udugama (adu@comnets.uni-bremen.de)
//
//
// @major changes by : João Patrício (castanheirapatricio@ua.pt)
// @date :   3-jul-2019
//

#ifndef BLUETOOTHINTERFACE_H_
#define BLUETOOTHINTERFACE_H_

#define TRUE                            1
#define FALSE                           0

#include "inet/mobility/contract/IMobility.h"

#include <omnetpp.h>
#include <cstdlib>
#include <string>
#include <queue>
#include <sstream>

#include "OutsMsg_m.h"
#include "InternalMsg_m.h"

using namespace omnetpp;

class BaseNodeInfo;

class BluetoothInterface : public cSimpleModule
{
protected:
    virtual void initialize(int stage);
    virtual void handleMessage(cMessage *msg);
    virtual int numInitStages() const;
    virtual void finish();

private:
    std::string ownBTMACAddress;
    double wirelessRange;
    std::string expectedNodeTypes;
    double neighbourScanInterval;
    double bandwidthBitRate;
    int wirelessHeaderSize;
    int minSSI;
    int valSSI;
    double calculateSSI(double x);

    std::string broadcastMACAddress;
    BaseNodeInfo *ownNodeInfo;
    std::list<BaseNodeInfo*> allNodeInfoList;
    std::queue<cMessage*> packetQueue;
    cMessage *sendPacketTimeoutEvent = NULL;

    std::list<BaseNodeInfo*> currentNeighbourNodeInfoList;
    std::list<BaseNodeInfo*> atTxNeighbourNodeInfoList;
    cMessage *currentPendingMsg = NULL;

    void setupSendingMsg(cMessage *msg);
    void sendPendingMsg();
    std::string getDestinationAddress(cMessage *msg);

    // statistics related variable
    simsignal_t neighbourhoodSizeSignal;

};


#define BLUETOOTHINTERFACE_SIMMODULEINFO       " BluetoothInterface>!<" << simTime() << ">!<" << getParentModule()->getFullName()
#define BLUETOOTHINTERFACE_BIT_RATE_10Mbps     10000000
#define BLUETOOTHINTERFACE_NEIGH_EVENT_CODE    112
#define BLUETOOTHINTERFACE_PKTSEND_EVENT_CODE  114


#endif /* BLUETOOTHINTERFACE_H_ */
