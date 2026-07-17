//
// Created by ubril on 6/16/2026.
//
#pragma once

#include <iostream>
using namespace std;

#ifndef ZAPP_CARD_H
#define ZAPP_CARD_H

class Card{
private:
    int id, rating, credit, point;
    string name;

    const int MIN_CHARGE = 4;
    const  int POINT_RATE = 3;


public:
     /**
     *constructor
    **/
    Card(int id, const string &name, int rating, int credit);

    /**
     * return the ID of this card
    **/
    int getId() const;

    /**
     * return the name of this card
    **/
    string getName() const;

    /**
     *return the rating of this card
    **/
    int getRating() const;

    /**
     * return the credit of the card
     */
    int getCredit() const;

    /**
     * return the points of the card
     */
    int getPoint() const;

    /**
     * changes the point of the card to the specified point
     * @param new_point - the value to update the point by
     */
    void setPoint(int newPoint);

    /**
     * changes the credit of the card
     * @param new_credit - the amount to change the credit by
     */
    void setCredit(int newCredit);

    /**Add a new credit to this card
     @param new_credit- the amount to the current credit balance by
    **/
    void addCredit(int newCredit);

  /**Checks if a card has sufficient credit to cross a bridge.
   * return true if yes and false if no
  **/
    void chargeCard();

  /**Deduct the minum charge amount from the card
   *increase the point by 1
  **/
    bool enoughCredit() const;

   /**Convert points to credit
    *increase the credit balance by how much credits the points can make
   **/
    void pointToCredit();

  /**Return the detials of a card as a String object
    *
   **/
    string toString();
};

#endif //ZAPP_CARD_H
