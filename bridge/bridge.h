//
// Created by ubril on 6/16/2026.
//

#ifndef ZAPP_BRIDGE_H
#define ZAPP_BRIDGE_H
#include "../area/area.h"

class Bridge {
    Area *fromArea = nullptr;
    Area *destinationArea = nullptr;
    string bridgeCode;

    public:
    //constructor
    Bridge(Area*, Area*,   const string &);

    /**
     *return the bridge code of the specified bridge
    **/
    string getBridgeCode() const;

    /**
     *return the source area of the bridge
    **/
    Area* getFromArea() const;

    /**
     *return the destionation area of the bridge
    **/
    Area* getDestinationArea() const;

    /**Checks the eligibility of a card to cross a bridge
     @return true if a card is eligible to cross the bridge and false otherwise
     @param card - the card to be checked if eligible to cross the bridge
    **/

    bool entryAllowed(const Card *) const;

   /**Return the details of the bridge as a string item.
  *return the details of the bridge
  **/
   string toString() const;

   /*move card from source area to destination area*/
   void move(Card *card) const;
};


#endif //ZAPP_BRIDGE_H
