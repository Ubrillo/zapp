//
// Created by ubril on 6/16/2026.
//
//
#include <iostream>
#include "Card.cpp"
 #include "TouristCard.cpp"
 #include "ChildCard.cpp"
#include "CompanyCard.cpp"


int main() {
    ChildCard Junior(1, "junior", 100);
    cout << junior.toString() << endl;

    junior.chargeCard();
    cout << junior.toString() << endl;
}
