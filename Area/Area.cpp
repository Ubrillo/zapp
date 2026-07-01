//
// Created by ubril on 6/16/2026.
//

#include "Area.h"
#include <algorithm>
#include <utility>

Area::Area(const int areaNo, const string &areaName, const int areaRating, int capacity) {
    this->areaNo = areaNo;
    this->areaName = areaName;
    this->areaRating = areaRating;
    this->capacity = capacity;
}

int Area::getRefNo() const {
    return areaNo;
}

string Area::getAreaName() const { return areaName; }

int Area::getAreaRating() const { return areaRating; }

int Area::getCapacity() const { return capacity; }

void Area::enter(Card *card)  {
    if (capacity) {
        cards.push_back(card);
        capacity--;
    }
}

void Area::leave(int id) {
    for (auto item = cards.begin(); item != cards.end(); ++item) {
        if ((*item)->getId() == id) {
            cards.erase(item);
            break;
        }
    }
    capacity++;
}

bool Area::isAvailable() const {
    return cards.size() < capacity ?  true : false;
}

string Area::checkCapacity() const {
    return (capacity > 0) ? "space avialable" : "area full!!";
}

string Area::listCards()  {
    string str = "";
    int count = 1;
    for (Card *card : cards) {
        str +=  to_string(count) + ". "+card->getName()+" ";
        count++;
    }
    return str;
}

string Area::findCard(const int id) const{
    for (Card *card: cards) {
        if (card->getId() == id) {
            return card->toString();
        }
    }
    return "";
}

bool Area::cardInArea(const int id) const {
    return (!findCard(id).empty()) ? true : false;
}

string Area::toString() const {
    return "Area: "+areaName+"\nReference no: "+ to_string(areaNo)
                +"\nLuxury Rating: "+
                    to_string(areaRating) + "\nCapacity: "+to_string(capacity);
}

