//
// Created by ubril on 6/16/2026.
//

#ifndef ZAPP_AREA_H
#define ZAPP_AREA_H

#include <iostream>
#include "../card/Card.h"
#include <vector>
using namespace std;

class area {

private:
    int areaNo{};
    string areaName;
    int areaRating{};
    int capacity{};
    vector<Card *> cards;

public:
    //constructor
    area(int areaNo, const string &areaName, int areaRating, int capacity);

    /**
     return the bridge code of this area
    **/
    int getRefNo() const;

   /**
    *return this area name  as String
   **/
   string getAreaName() const;

   /**
    *return this area name  as String
   **/
   int getAreaRating() const;

  /**
   *return the rating of this area
  **/
    int getCapacity() const;

  /**Adds a new_card to this area card list
   *@param card - the card to be added to the destionation area list
  **/
   void enter( Card *card);

  /**Remove a card from this area list
   *@param id - the id of the card to be removed
  **/
    void leave(int id);

  /**Checks if the  area has an available space
   *return true if there is space and false otherwise in this area.
  **/
    bool isAvailable() const;

    /** Check the capacity status of the area
     *return as a String if the area is full or not
    **/
    string checkCapacity() const;

    /**Return all cards in this area as a string
    **/
    string listCards();

    /**Find a card in this area
     * @return null if card not found otherwise the detail of the card as  a string
     * @param id - the id of the card to be looked for
    **/
    string findCard(int id) const;

    /**Check if a card belong to this area
     @ return true if a card belongs to this area and false otherwise
     @param id - the id of the card to find
    **/
    bool cardInArea(int id) const;

    /**Return the details of this area as a string object
     *
    **/
    string toString() const;
};



#endif //ZAPP_AREA_H
