//
// Created by ubril on 6/26/2026.
//

#ifndef ZAPP_ZAPP_H
#define ZAPP_ZAPP_H
#include <string>


class Zapp {
public:
 
    /**
     * Returns all of the details of the park: its name and its areas
     * including lists of cards in each area.
     */
    virtual std::string toString() = 0;

    /**Returns a String with details of a card
     * @param cardId - id number of the card
     * @return the details of the card as a String, or "No such card"
     */
    virtual std::string getCardDetails(int cardId) = 0;

    /**Returns the name of the area which contains the specified card or null
     * @param ccd - the specified card
     * @return the name of the Area which contains the card, or null
     **/
    virtual std::string getCardLocation(int cd) = 0;


    /** Given the name of a area, returns the area id number
     * or -1 if area does not exist
     * @param name of area
     * @return id number of area
     */
    virtual int getAreaNumber(std::string ww) = 0;


    /**Returns a string representation of all the cards on specified area
     * @param area is the name of the area
     * @return a string representation of all cards on specified area
     **/
    virtual std::string getAllCardsInOneArea(std::string area) = 0;


    /**Returns a string representation of all the cards in all areas including the name of each area
     * @return a string representation of all cards on specified area
     **/
    virtual std::string getAllCardsInAllAreas() = 0;


    /**Returns true if a Card is allowed to move using the bridge, false otherwise
     * A move can be made if:
     * the rating of the card  >= the rating of the destination area
     * AND the destination area is not full
     * AND the card has sufficient credits
     * AND the card is currently in the source area
     * AND the card id is for a card on the system
     * AND the bridge code is the code for a bridge on the system
     * @param trId is the id of the card requesting the move
     * @param brCode is the code of the bridge by which the card wants to move
     * @return true if the card is allowed on the bridge journey, false otherwise
    **/
    virtual bool canMove(int trId, std::string brCode) = 0;


    /**Returns the result of a card requesting to move over a bridge.
     * A move will be successful if:
     * the luxury rating of the card  >= the luxury rating of the destination area
     * AND the destination area is not full
     * AND the card has sufficient credits
     * AND the card is currently in the source area
     * AND the card id is for a card in the system
     * AND the bridge code is the code for a bridge on the system
     * If the bridge crossing can be made, the card information is removed from
     * the source area, added to the destination area, card details updated and a suitable message returned.
     * a suitable message returned.
     * If bridge journey cannot be made, the state of the system remains unchanged
     * and a message specifying the reason is returned.
     * @param pCardId is the id of the card requesting the move
     * @param brCode is the code of the bridge by which the card wants to move
     * @return a string giving the result of the request
     **/
    virtual std::string move(int pCardId, std::string brCode ) = 0;


    /** Allows a card to top up their credits.This method is not concerned with
     *  the cost of a credit as currency and prices may vary between resorts.
     *  @param id the id of the card toping up their credits
     *  @param creds the number of credits purchased to be added to cards information
     */
    virtual void topUpCredits(int id, int creds) = 0;

    /** Allows a card to convert points to credits
     *  @param cdId the id of the card toping up their credits
     */
    virtual void convertPoints(int cdId) = 0;

};
#endif //ZAPP_ZAPP_H
