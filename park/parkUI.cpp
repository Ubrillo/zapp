//
// Created by ubril on 7/3/2026.
//

#include <iostream>
#include "park.h"

using namespace std;

Park fantasia("Fantasia Pleasure Park");
Zapp &zapp = fantasia;

/**
 * display the area of a speicifed card
 * @param: card_id - the id of the card
 */
void findCardLocation(int cardId) {
    string data = zapp.getCardLocation(cardId);
    data.empty() ? cout << "card not found!!"<< endl : cout << data << endl;
}


/**
 * display and get appropriate input from terminal
 * triggers corresponding method to locate a specified card area
 */
void cardLocator() {
    cout << "Enter Card ID:" << endl;
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
    cout << "Enter Card ID:" << endl;
    int cardId;
    cin >> cardId;
    cout << "Enter  bridge code in UPPERCASE:"<< endl;
    string bridgecode;
    cin >> bridgecode;
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

void updateCredits() {
    cout << "Enter Card ID:" << endl;
    int cardId, amount;
    cin >> cardId;
    cout << "Enter credit amount:"<< endl;
    cin >> amount;
    zapp.topUpCredits(cardId, amount);
    string details = zapp.getCardDetails(cardId);
    if (details.empty()) {
        cout << "CARD NOT FOUND!!" << endl;
        return;
    }
    cout << details << endl;
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
    string data = zapp.getAllCardsInAllAreas();
    cout << data << endl;
}

/**
  * display all cards in a specified area
  */
void listOneArea() {
    cout << "Enter area name: " << endl;
    string str;
    cin >> str;
    string data = zapp.getAllCardsInOneArea(str);
    data.empty() ? cout << "Invalid Area Name!" <<endl : cout << data << endl;
}

/**
 * display true of false if a card can cross a bridge.
 */
void tryTravel() {
    cout << "Enter card ID" << endl;
    int cardId;
    cin >> cardId;
    cout << "please input Bridgecode in UPPERCASE:" << endl;
    string brCode;
    cin >> brCode;
    zapp.canMove(cardId, brCode) ? cout << "True" << endl : cout << "False" << endl;
}

/**
 * display the card details on the terminal
 */
void getCardInfo() {
    cout << "Enter Card ID:" << endl;
    int cardId;
    cin >> cardId;
    cout << zapp.getCardDetails(cardId) << endl;
}

int getOption() {
    cout << "what would you like to do?" << endl;
    cout << "0. Quit" << endl;
    cout << "1. List all area details" << endl;
    cout << "2. List all cards in each area" << endl;
    cout << "3. list cards in a specified area" << endl;
    cout << "4. find the location of card" << endl;
    cout << "5. say if card can move by bridge" << endl;
    cout << "6. move a card by brigde" << endl;
    cout <<"7. top up credits" << endl;
    cout << "8. get card details" << endl;
    cout << "9. list all cards in one area" << endl;

    cout << "Enter your choice: " << endl;
    int option;
    cin >> option;
    return option;
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
                updateCredits();
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
    runUI();
}