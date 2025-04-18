//
// Created by administrator on 4/9/25.
//

#include "Hand.h"
#include "Card.h"
#include "Deck.h"

Hand::Hand() {}

void Hand::clearHand() {
    m_hand.clear();
}
void Hand::operator+=(Card temp) {
    m_hand.push_back(temp);
}
Card Hand::displayCard(int i) {
    return m_hand[i];
}
int Hand::getPoints() {
    int points =0, aces = 0;
    for(auto &card : m_hand) {
        int value = card.getValue();
        if(value == 11) {
            aces++;
        }
        points += value;

    }
    while(points > 21 and aces > 0) {
        points -= 10;
        aces--;
    }
    return points;
}
int Hand::cardCount() {
    return m_hand.size();
}
