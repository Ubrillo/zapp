//
// Created by ubril on 7/18/2026.
//
#include "TouristCard.h"

/*define and init... the constructor*/
TouristCard::TouristCard(int id, string name)
    :Card(id, name, 900, 900) {}


string TouristCard::toString() {
    return Card::toString();
}