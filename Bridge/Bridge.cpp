//
// Created by ubril on 6/16/2026.
//

#include "Bridge.h"

#include <utility>

Bridge::Bridge( Area *fromArea,  Area *toArea, const string &code):
    fromArea(fromArea),
    destinationArea(toArea),
    bridgeCode(code)
{}

string Bridge::getBridgeCode() const{
    return bridgeCode;
}

Area* Bridge::getFromArea() const {
    return fromArea;
}

Area* Bridge::getDestinationArea() const {
    return destinationArea;
}

bool Bridge::entryAllowed(const Card &card) const {
    return (card.getRating() >= destinationArea->getAreaRating())&&
        (destinationArea->isAvailable()) &&
        (card.enoughCredit()) &&
        (fromArea->cardInArea(card.getId()));
}

string Bridge::toString() const {
    return "Bridge Code: "+bridgeCode+
        "\nSource Area: "+ fromArea->getAreaName() +"\n";
}