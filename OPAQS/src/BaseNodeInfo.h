// @major changes by : Joao Patricio (castanheirapatricio@ua.pt)
// @date :   3-jul-2019

#ifndef BASENODEINFO_H_
#define BASENODEINFO_H_
#include "inet/mobility/contract/IMobility.h"

#include <omnetpp.h>
#include <cstdlib>
#include <string>

#include "WirelessInterface.h"
#include "BluetoothInterface.h"

using namespace omnetpp;

class WirelessInterface;

class BaseNodeInfo
{
    public:
        std::string nodeAddress;
        cModule *nodeModule;
		inet::IMobility *nodeMobilityModule;
		WirelessInterface *nodeWirelessIfcModule;
		BluetoothInterface *nodeBluetoothIfcModule;
};

#endif /* BASENODEINFO_H_ */
