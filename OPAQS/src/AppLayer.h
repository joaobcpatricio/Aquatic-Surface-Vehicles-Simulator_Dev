//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
//
// The model implementation for the Herald application.
//
// @author : Asanga Udugama (adu@comnets.uni-bremen.de), Anna Förster (afoerster@uni-bremen.de)
// @date   : 15-aug-2016, updated 6-febr-2018
//
// @major changes by : João Patrício (castanheirapatricio@ua.pt)
// @date :   3-jul-2019


//NOTE:
//The size of the array of number of nodes generating messages is hardcoded as 100, you can change that here
//
#ifndef APPLAYER_H_
#define APPLAYER_H_

#include <omnetpp.h>
#include <cstdlib>
#include <ctime>
#include <list>
#include <string>
#include <iostream>
#include "OutsMsg_m.h"
#include "InternalMsg_m.h"
#include <vector>
#include <fstream>

using namespace omnetpp;
//using namespace std;


#define APPLAYER_SIMMODULEINFO        " AppLayer>!<" << simTime() << ">!<" << getParentModule()->getFullName()
#define TRUE                            1
#define FALSE                           0
#define APPLAYER_MSGTYPE_NONE         0
#define APPLAYER_MSGTYPE_IMMEDIATE    1
#define APPLAYER_MSGTYPE_PREFERENCE   2
#define APPLAYER_START_ITEM_ID        22000
#define APPLAYER_REGISTRATION_EVENT   92
#define APPLAYER_DATASEND_EVENT       93



class AppLayer : public cSimpleModule
{
    protected:
        virtual void initialize(int stage);
        virtual void handleMessage(cMessage *msg);
        virtual int numInitStages() const;
        virtual void finish();

    private:

        double totalSimulationTime;
        char prefixName[128] = "/herald";

        double ttl;
        int nodeIndex;
        int totalNumNodes;
        double dataGenerationInterval;
        int nextGenerationNotification;

        int notificationCount;
        std::vector<int> timesMessagesReceived;

        int usedRNG;

        cMessage *appRegistrationEvent;
        cMessage *dataTimeoutEvent;

        double popularityAssignmentPercentage;
        int dataSizeInBytes;

        // statistics related variable
        simsignal_t likedDataBytesReceivedSignal;
        simsignal_t nonLikedDataBytesReceivedSignal;
        simsignal_t duplicateDataBytesReceivedSignal;
        simsignal_t totalDataBytesReceivedSignal;

        simsignal_t likedDataBytesReceivableByAllNodesSignal;
        simsignal_t nonLikedDataBytesReceivableByAllNodesSignal;
        simsignal_t totalDataBytesReceivableByAllNodesSignal;

        simsignal_t dataDelaySignal;

        std::string destinationAddr;
        std::string destinationBTAddr;
        int nMsgOrder;
        bool generateMsg;
        std::string nodesGenMsg;

        std::vector<int> nodeCh;
        int nAr=0;
        bool nodesThatGen;

        bool startMultipleMsg;
        double numMultipleMsg;
        double countMultipleMsg;
        int hopsListSize;
        double endGeneratingMsg;



};

#endif /* APPLAYER_H_ */
