//
// Created by ubril on 7/3/2026.
//

#include <iostream>
#include "park.h"

using namespace std;

Park fantasia("Fantasia Pleasure Park");
Zapp &zapp = fantasia;

int getOption() {
    cout << "what would you like to do?" << endl;
    cout << "0. Quit" << endl;
    cout << "1. List all area details" << endl;
    cout << "2. List all cards in each area" << endl;
    cout << "3. find card location" << endl;
    cout << "4. say if card can move by bridge" << endl;
    cout << "5. move a card by brigde" << endl;
    cout <<"6. top up credits" << endl;
    cout << "7. get card details" << endl;
    cout << "8. list all cards in one area" << endl;

    cout << "Enter your choice: " << endl;
    int option;
    cin >> option;
    return option;
}

/**
 * display the area of a speicifed card
 * @param: card_id - the id of the card
 */
void findCardLocation(int cardId) {
    cout << zapp.getCardLocation(cardId) << endl;
}


/**
 * display and get appropriate input from terminal
 * triggers corresponding method to locate a specified card area
 */
void cardLocator() {
    cout << "please enter card id" << endl;
    int id;
    cin >> id;
    findCardLocation(id);
}


/**
 * @param cardId -  the ID of the card trying to move
 * @param  brCode - the bridge code the card is trying move on.
 * display appropriate response message if a card is trying to use a bridge.
 */
void moveNow(int cardId, string brCode) {
    cout << zapp.move(cardId, brCode) << endl;
}


/**
 * display and get appropriate input from terminal
 * triggers corresponding method to move a card
 */
void moveCard() {
    cout << "please enter card id" << endl;
    int cardId;
    cin >> cardId;
    cout << "please input bridgecode in UPPERCASE:"<< endl;
    string bridgecode;
    moveNow(cardId, bridgecode);
}

/**
 * convert points to credit
 * @param: cdId - the card id used for the conversion
 */

void convertPoints(int cardId) {
    zapp.convertPoints(cardId);
    string details = zapp.getCardDetails(cardId);
    if (details.empty()) {
        cout << "card not found!!" << endl;
        return;
    }
    cout << "recharge successful!!" << endl;
    cout << details << endl;
}


/**Update the credit of a card and display the updated details of the card
 * @param: id - the card id to update
 * @param: creds - the amount of credit to update the card with.
 * display successful if update was successful.
 */

void updateCredits(int cardId, int credit) {
    zapp.topUpCredits(cardId, credit);
    string details = zapp.getCardDetails(cardId);
    if (details.empty()) {
        cout << "card not found!!" << endl;
        return;
    }
    cout << details << endl;

}


/**
 * @param: option - the option for credit card update method
 * display appropriate ouput text on the terminal
 * triggers corresponding credit card update methods of the paramater
 */

void creditCard(int option) {
    cout << "please enter card id" << endl;
    int cardId;
    cin >> cardId;

    if (option == 1) {
        cout << "please enter credit amount" << endl;
        int credit;
        cin >> credit;
        updateCredits(cardId, credit);
    }
    else if (option == 2) {
        convertPoints(cardId);
    }
}

/**
 * display the credit card update options
 * gets  input from terminal
 */
int creditOption() {
    cout << "0. Main menu" << endl;
    cout << "1. recharge card" << endl;
    cout << "2. convert point to credit" << endl;

    int choice;
    cin >> choice;
    return choice;
}


/**
 * triggers credit card update on the corresponding input from the terminal
 */
void creditSelect() {
    int option = creditOption();
    while (option != 0) {
        if (option == 0) {
            break;
        }
        else if (option == 1) {
            creditCard(option);
            break;
        }
        else if (option == 2) {
            creditCard(option);
            break;
        }
    }
}

/**
 * display all areas of the park on the screen
 */
void listAllAreas() {
    cout << zapp.toString();
}

/**
 * display all cards in all areas of the park on the screen
 */
void listAllCards() {
    string store = zapp.getAllCardsInAllAreas();
    cout << store << endl;
}

/**
  * display all cards in a specified area
  */
void listOneArea() {
    cout << "Enter area name: " << endl;
    string str;
    cin >> str;
    cout << zapp.getAllCardsInOneArea(str);
    cout<< endl;
}



/**
 * display true of false if a card can cross a bridge.
 */
void tryTravel() {
    cout << "please enter card id" << endl;
    int cardId;
    cin >> cardId;
    cout << "please input bridgecode in UPPERCASE:" << endl;
    string bridgecode;
    cin >> bridgecode;
    cout << zapp.canMove(cardId, bridgecode) << endl;
}

/**
 * display the card details on the terminal
 */
void getCardInfo() {
    cout << "enter card id" << endl;
    int cardId;
    cin >> cardId;
    cout << zapp.getCardDetails(cardId) << endl;
}

void runUI() {
    int choice = getOption();
    while (choice != 0) {
        switch (choice) {
            case 1:
                listAllAreas();
                break;
            case 2:
                listAllCards();
                break;
            case 3:
                listOneArea();
                break;
            case 4:
                cardLocator();
                break;
            case 5:
                tryTravel();
                break;
            case 6:
                moveCard();
                break;
            case 7:
                creditSelect();
                break;
            case 8:
                getCardInfo();
                break;

            default:
                cout << "enter  a valid choice" << endl;

        }
        choice = getOption();
    }
}

int main() {
    ParkUI UI =
}