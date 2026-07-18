//
// Created by ubril on 7/18/2026.
//

#ifndef ZAPP_COMPANYCARD_H
#define ZAPP_COMPANYCARD_H
#include "Card.h"


class CompanyCard : public Card{
private:
    const int MIN_CHARGE = 3;

public:
    /*constructor*/
    using Card::Card;

    /*to string override*/
    string toString() override;

    void chargeCard() override;
};

#endif //ZAPP_COMPANYCARD_H
