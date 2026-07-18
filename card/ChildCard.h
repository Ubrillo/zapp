//
// Created by ubril on 7/17/2026.
//

#ifndef ZAPP_CHILDCARD_H
#define ZAPP_CHILDCARD_H

#include "Card.h"
using namespace std;

class ChildCard :  public Card {
private:
    int zonesVisited = 0;
    int parentId;
    const int MIN_CHARGEX = 0;

public:
    /*Constructor*/
    ChildCard(int id, const string &name, int parentId);

    /**Return the detials of a card as a String object**/
    string  toString() override;

    /**Checks if a card has sufficient credit to cross a bridge.
    * return true if yes and false if no
    **/
    bool enoughCredit() const override;

    /**Deduct the minum charge amount from the card
    *increase the point by 1
    **/
    void chargeCard() override;

};

#endif //ZAPP_CHILDCARD_H
