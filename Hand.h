//
// Created by administrator on 4/9/25.
//

#ifndef HAND_H
#define HAND_H
#include "Card.h"
#include <vector>


class Hand {
private:
    vector<Card> m_hand;
    public:
    Hand();
    void clearHand();
    void operator+=(Card);
    Card displayCard(int);
    int getPoints ();
    int cardCount();

};



#endif //HAND_H
