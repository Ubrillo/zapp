//
// Created by ubril on 6/16/2026.
//

#include "bridge.h"

#include <utility>

bridge::bridge( area *fromArea,  area *toArea, const string &code):
    fromArea(fromArea),
    destinationArea(toArea),
    bridgeCode(code)
{}

string bridge::getBridgeCode() const{
    return bridgeCode;
}

area* bridge::getFromArea() const {
    return fromArea;
}

area* bridge::getDestinationArea() const {
    return destinationArea;
}

bool bridge::entryAllowed(const Card &card) const {
    return (card.getRating() >= destinationArea->getAreaRating())&&
        (destinationArea->isAvailable()) &&
        (card.enoughCredit()) &&
        (fromArea->cardInArea(card.getId()));
}

string bridge::toString() const {
    return "Bridge Code: "+bridgeCode+
        "\nSource Area: "+ fromArea->getAreaName() +"\n";
}