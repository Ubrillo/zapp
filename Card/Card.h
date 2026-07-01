//
// Created by ubril on 6/16/2026.
//
#pragma once

#include <iostream>
using namespace std;

#ifndef ZAPP_CARD_H
#define ZAPP_CARD_H


class Card {

    private:
    int id, rating, credit, point;
    string name;

    const int MIN_CHARGE = 4;
    const  int POINT_RATE = 3;

    public:
    Card(int id, const string &name, int rating, int credit);

    int getId() const;

    string getName() const;

    int getRating() const;

    int getCredit() const;

    int getPoint() const;

    void setPoint(int newPoint);

    void setCredit(int newCredit);

    void addCredit(int newCredit);

    void chargeCard();

    [[nodiscard]] bool enoughCredit() const;

    void pointToCredit();

    string toString();
};


#endif //ZAPP_CARD_H
