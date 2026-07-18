//
// Created by ubril on 7/17/2026.
//
#ifndef ZAPP_TOURISTCARD_H
#define ZAPP_TOURISTCARD_H

#include "Card.h"

class TouristCard : public Card {

    public:
    /**
     * Constructor
    */
    TouristCard(int id, string name);

    string toString() override;

};

#endif //ZAPP_TOURISTCARD_H
