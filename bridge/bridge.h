//
// Created by ubril on 6/16/2026.
//

#ifndef ZAPP_BRIDGE_H
#define ZAPP_BRIDGE_H
#include "../area/area.h"

class bridge {
    area *fromArea = nullptr;
    area *destinationArea = nullptr;
    string bridgeCode;

    public:
    //constructor
    bridge(area*, area*,   const string &);

    /**
     *return the bridge code of the specified bridge
    **/
    string getBridgeCode() const;

    /**
     *return the source area of the bridge
    **/
    area* getFromArea() const;

    /**
     *return the destionation area of the bridge
    **/
    area* getDestinationArea() const;

    /**Checks the eligibility of a card to cross a bridge
     @return true if a card is eligible to cross the bridge and false otherwise
     @param card - the card to be checked if eligible to cross the bridge
    **/

    bool entryAllowed(const Card&) const;

   /**Return the details of the bridge as a string item.
  *return the details of the bridge
  **/
   string toString() const;
};


#endif //ZAPP_BRIDGE_H
