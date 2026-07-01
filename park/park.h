//
// Created by ubril on 6/25/2026.
//

#ifndef ZAPP_PARK_H
#define ZAPP_PARK_H
#include<iostream>
#include <vector>

#include "zapp.h"
using namespace std;
#include "../Bridge/Bridge.h"

class Park : public Zapp {
private:
    string parkName;
    vector <Card*> cards;
    vector <Area *> areas;
    vector<Bridge *> bridges;

    Area lobby = Area(0, "Lobby", 0, 1000);
    Area concourse = Area(1, "Concourse", 1, 100);
    Area  waterWorld = Area(2, "WaterWorld", 3, 10);
    Area wildWest = Area(3, "WildWest", 5, 2);
    Area solitaire = Area(4, "Solitaire", 1, 1);

    Bridge ABC1 =  Bridge(&lobby, &concourse, "ABC1");
    Bridge BCD2 =  Bridge(&concourse, &lobby, "BCD2");
    Bridge CDE3 =  Bridge(&concourse, &waterWorld, "CDE3");
    Bridge DEF4 =  Bridge(&waterWorld, &concourse, "DEF4");
    Bridge JKL8 =  Bridge(&waterWorld, &wildWest, "JKL8");
    Bridge EFG5 =  Bridge(&wildWest,&concourse, "EFG5");
    Bridge GHJ6 =  Bridge(&concourse, &solitaire, "GHJ6");
    Bridge HJK7 =  Bridge(&solitaire, &concourse, "HJK7");

    Card Lynn =  Card(1000, "Lynn", 5, 10);
    Card May =  Card(1001, "May", 3, 20);
    Card Nils =  Card(1002, "Nils", 10, 20);
    Card Olek =  Card(1003, "Olek", 2, 12);
    Card Pan =  Card(1004, "Pan", 3, 4);
    Card Quin =  Card(1005, "Quin", 1, 5);
    Card Raj =  Card(1006, "Raj", 10, 6);
    Card Sol =  Card(1007, "Sol", 7, 20);
    Card Tel =  Card(1008, "Tel", 6, 24);

    // Card Tourist =  TouristCard(2000, "Grandson", 10, 10);
    // Card Child =  ChildCard(3000, "Child", 1004);
    // Card Company =  CompanyCard(4000, "kompany", 10);

    void loadAreas();
    void setUpBridges();
    void loadCards();

    Card* getCard(int id);
    Area* getArea(const string &name);
    Bridge* getBridge(const string &name);

public:
    Park(string name);
    string getCardDetails(int cardId) override;

    string toString() override;

    string getCardLocation(int cd) override;

    int getAreaNumber(std::string ww) override;

    string getAllCardsInOneArea(std::string area) override;

    string getAllCardsInAllAreas() override;

    bool canMove(int trId, std::string brCode) override;

    string move(int pCardId, std::string brCode ) override;

    void topUpCredits(int id, int creds) override;

    void convertPoints(int cdId) override;

    void toUpCredit(int cardId, int credit);

};


#endif //ZAPP_PARK_H
