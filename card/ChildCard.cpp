//
// Created by ubril on 7/18/2026.
//
#include "ChildCard.h"

ChildCard::ChildCard(int id, const string &name, int parentId)
    :Card(id, name, 10, 10),
    parentId(parentId) {}

void ChildCard::chargeCard() {
    deductCredit(MIN_CHARGE);
    zonesVisited++;
}
bool ChildCard::enoughCredit() const{
    return true;
}

string ChildCard::toString() {
    return Card::toString()+"\nVisited Zones: "+ to_string(zonesVisited);
}
