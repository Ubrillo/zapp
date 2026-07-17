//
// Created by ubril on 7/17/2026.
//

#ifndef ZAPP_CHILDCARD_H
#define ZAPP_CHILDCARD_H
#include "Card.h"
using namespace std;

class Child :  public Card {
    int zones = 0;
    int parentId;
    const int MIN_CHARGE = 0;

public:
    Child(int id, const string& name, int parentId):
        Card(id, name, 10, 0), parentId(parentId) {
    }

    string  toString();

    bool enoughCredit();

    void chargeCard();
};

#endif //ZAPP_CHILDCARD_H
