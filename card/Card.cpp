//
// Created by ubril on 6/16/2026.
//
#include "Card.h"

Card::Card(const int id, const string &name, const int rating, const int credit) {
        this->id = id;
        this->rating = rating;
        this->credit = credit;
        this->point = 0;
        this->name = name;
    }

    int Card::getId() const {
        return id;
    }

    string Card::getName() const {
        return name;
    }

    int Card::getRating() const {
        return rating;
    }

    int Card::getCredit() const {
        return credit;
    }

    int Card::getPoint() const {
        return point;
    }

    void Card::setPoint(const int newPoint) {
        point = newPoint;
    }

    void Card::setCredit(const int newCredit){credit = newCredit;}

    void Card::addCredit(const int newCredit) {
        credit += newCredit;
    }

    bool Card::enoughCredit() const {
        if (credit >= MIN_CHARGE) {
           return true;
        }

        return false;
    }

    void Card::chargeCard() {
        if (enoughCredit()) {
            credit -= MIN_CHARGE;
            point++;
        }
    }

void  Card::pointToCredit() {
        if (const int value = point/POINT_RATE; value > 0) {
            credit += value;
            point = point % POINT_RATE;
        }
    }

void Card::deductCredit(int amount) {
    if (enoughCredit()) {
        this->credit -= amount;
    }
}

void Card::addPoint(int amount) {
    this->point += amount;
}

    string Card::toString() {
        string str = "Card ID: "+to_string(id) +
            "\nGuest Name: "+name+
                "\nLuxury rating: " + to_string(rating)+
                    "\nCredit : "+to_string(credit)+
                        "\nPoint: "+ to_string(point);

        return str;
    }
