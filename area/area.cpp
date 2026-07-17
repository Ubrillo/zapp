//
// Created by ubril on 6/16/2026.
//

#include "area.h"
#include <algorithm>
#include <utility>

area::area(const int areaNo, const string &areaName, const int areaRating, int capacity) {
    this->areaNo = areaNo;
    this->areaName = areaName;
    this->areaRating = areaRating;
    this->capacity = capacity;
}

int area::getRefNo() const {
    return areaNo;
}

string area::getAreaName() const { return areaName; }

int area::getAreaRating() const { return areaRating; }

int area::getCapacity() const { return capacity; }

void area::enter(Card *card)  {
    if (capacity) {
        cards.push_back(card);
        capacity--;
    }
}

void area::leave(int id) {
    for (auto item = cards.begin(); item != cards.end(); ++item) {
        if ((*item)->getId() == id) {
            cards.erase(item);
            break;
        }
    }
    capacity++;
}

bool area::isAvailable() const {
    return cards.size() < capacity ?  true : false;
}

string area::checkCapacity() const {
    return (capacity > 0) ? "space avialable" : "area full!!";
}

string area::listCards()  {
    string str = "";
    int count = 1;
    for (Card *card : cards) {
        str +=  to_string(count) + ". "+card->getName()+" ";
        count++;
    }
    return str;
}

string area::findCard(const int id) const{
    for (Card *card: cards) {
        if (card->getId() == id) {
            return card->toString();
        }
    }
    return "";
}

bool area::cardInArea(const int id) const {
    return !findCard(id).empty();
}

string area::toString() const {
    return "Area: "+areaName+"\nReference no: "+ to_string(areaNo)
                +"\nLuxury Rating: "+
                    to_string(areaRating) + "\nCapacity: "+to_string(capacity);
}

