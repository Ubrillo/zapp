//
// Created by ubril on 6/25/2026.
//

#include "park.h"
Park::Park(string name) {

    parkName = name;

    loadAreas();
    setUpBridges();
    loadCards();

    for (Card *card : cards) {
        lobby.enter(card);
    }

    // lobby.enter(Tourist);
    // lobby.enter(Child);
    // lobby.enter(Company);
}

void Park::loadAreas() {
    areas.push_back(&lobby);
    areas.push_back(&concourse);
    areas.push_back(&waterWorld);
    areas.push_back(&wildWest);
    areas.push_back(&solitaire);
}

void Park::loadCards() {
    cards.push_back(&Lynn);
    cards.push_back(&May);
    cards.push_back(&Nils);
    cards.push_back(&Olek);
    cards.push_back(&Pan);
    cards.push_back(&Quin);
    cards.push_back(&Raj);
    cards.push_back(&Tel);
}

void Park::setUpBridges() {
    bridges.push_back(&ABC1);
    bridges.push_back(&BCD2);
    bridges.push_back(&CDE3);
    bridges.push_back(&DEF4);
    bridges.push_back(&JKL8);
    bridges.push_back(&EFG5);
    bridges.push_back(&GHJ6);
    bridges.push_back(&HJK7);
}

Card* Park::getCard(const int id) {
    for (auto *card : cards) {
        if (card->getId() == id) {
            return card;
        }
    }
    return nullptr;
}

Area *Park::getArea(const string &name) {
    for (auto &area : areas) {
        if (area->getAreaName() == name) {
            return area;
        }
    }
    return nullptr;
}

Bridge* Park::getBridge(const string &name) {
    for (auto &bridge : bridges) {
        if (bridge->getBridgeCode() == name) {
            return bridge;
        }
    }
    return nullptr;
}

/**
   * Returns all of the details of the park: its name and its areas
   * including lists of cards in each area.
   */
string Park::toString() {
    string str = "=============PARK NAME: "+parkName + "================";
    for (Area *area : areas) {
        str += "\nArea: "+ area->getAreaName() + "\n" + area->listCards();
    }
    return str;
}

/**Returns a String with details of a card
 * @param cardId - id number of the card
 * @return the details of the card as a String, or "No such card"
 */
string Park::getCardDetails(int id) {
    for (Card *card : cards) {
        if (card->getId() == id) {
            return card->toString();
        }
    }
    return "";
}

/**Returns the name of the area which contains the specified card or null
 * @param ccd - the specified card
 * @return the name of the Area which contains the card, or null
 **/
string Park::getCardLocation(int ccd) {
    for (Area *area: areas) {
        if (area->cardInArea(ccd) == ccd) {
            return area->getAreaName();
        }
    }
    return "";
}

/** Given the name of a area, returns the area id number
 * or -1 if area does not exist
 * @param name of area
 * @return id number of area
 */
int Park::getAreaNumber(string name) {
    for (Area *area : areas) {
        if (area->getAreaName() == name) {
            return area->getRefNo();
        }
    }
    return -1;
}

/**Returns a String representation of all the cards on specified area
 * @param area is the name of the area
 * @return a String representation of all cards on specified area
 **/
string Park::getAllCardsInOneArea(string areaName) {
    for (Area *area : areas) {
        if (area->getAreaName() == areaName) {
            return "Cards in area: "+area->getAreaName()+"\n"+ area->listCards();
        }
    }
    return "";
}

/**Returns a String representation of all the cards in all areas including the name of each area
 * @return a String representation of all cards on specified area
 **/
string Park::getAllCardsInAllAreas() {
    for (Area *area : areas) {
        return getAllCardsInOneArea(area->getAreaName());
    }
    return "";
}

/**Returns true if a Card is allowed to move using the bridge, false otherwise
 * A move can be made if:
 * the rating of the card  >= the rating of the destination area
 * AND the destination area is not full
 * AND the card has sufficient credits
 * AND the card is currently in the source area
 * AND the card id is for a card on the system
 * AND the bridge code is the code for a bridge on the system
 * @param cardId is the id of the card requesting the move
 * @param bridgeCode is the code of the bridge by which the card wants to move
 * @return true if the card is allowed on the bridge journey, false otherwise
**/

bool Park::canMove(int cardId, std::string bridgeCode) {
    Card *card = getCard(cardId);
    Bridge *bridge = getBridge(bridgeCode);
    if (card && bridge) {
        return bridge -> entryAllowed(*card);
    }
    return false;
}


/**Returns the result of a card requesting to move over a bridge.
 * A move will be successful if:
 * the luxury rating of the card  >= the luxury rating of the destination area
 * AND the destination area is not full
 * AND the card has sufficient credits
 * AND the card is currently in the source area
 * AND the card id is for a card in the system
 * AND the bridge code is the code for a bridge on the system
 * If the bridge crossing can be made, the card information is removed from
 * the source area, added to the destination area, card details updated and a suitable message returned.
 * a suitable message returned.
 * If bridge journey cannot be made, the state of the system remains unchanged
 * and a message specifying the reason is returned.
 * @param pCardId is the id of the card requesting the move
 * @param brCode is the code of the bridge by which the card wants to move
 * @return a String giving the result of the request
 **/

string Park::move(int cardId, string bridgeCode) {
    Card *card = getCard(cardId);
    Bridge *bridge = getBridge(bridgeCode);

    if (card == nullptr) {
        return "ACCESS DENIED !!! INVALID CARD!!!";
    }
    if (bridge == nullptr) {
        return "ACCESS DENIED!!! INVALID BRIDGE CODE!!";
    }

    Area *startArea = bridge->getFromArea();
    Area *destinationArea = bridge->getDestinationArea();
    if (canMove(cardId, bridgeCode)) {
        card -> chargeCard();
        destinationArea -> enter(card);
        startArea -> leave(cardId);

        return "ACCESS GRANTED!!!";
    }
    else if (destinationArea->getAreaRating() > card->getRating()) {
        return "ACCESS DENIED!!!  Low Rating!!!";
    }
    else if (destinationArea -> isAvailable() == false ) {
        return "ACCESS DENIED!!! CARD NOT FOUND IN SOURCE AREA!!!";
    }
    else if (card->enoughCredit()) {
        return "ACCESS DENIED!!! INSUFFICIENT CREDIT. Please, recharge or convert points to credit!!!\n";
    }
    return "";
}

void Park::topUpCredits(int cardId, int credit) {
    Card *card = getCard(cardId);
    if (card) {
        card -> pointToCredit();
    }
}

void Park::convertPoints(int cardId) {
    Card *card = getCard(cardId);
    if (card) {
        card -> pointToCredit();
    }
}





