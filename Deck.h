//
// Created by administrator on 4/7/25.
//

#ifndef DECK_H
#define DECK_H
#include <vector>

#include "Card.h"


class Deck {
    private:
    vector <Card> m_cardDeck;
    void shuffleDeck();
    public:
    Deck();
    Card dealCard();
    int getCount();


};



#endif //DECK_H
