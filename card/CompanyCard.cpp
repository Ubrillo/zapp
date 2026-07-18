//
// Created by ubril on 7/18/2026.
//

#include "CompanyCard.h"

string CompanyCard::toString() {
    return Card::toString();
}

void CompanyCard::chargeCard() {
    deductCredit(MIN_CHARGE);
    addPoint(3);
}
