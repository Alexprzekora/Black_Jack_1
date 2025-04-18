//
// Created by administrator on 4/7/25.
//

#include "Card.h"

Card :: Card() {
    m_suit = "";
    m_rank = "";
    m_value = 0;
}
Card :: Card(string suit, string rank, int value) {
    m_suit = suit;
    m_rank = rank;
    m_value = value;
}
string Card :: getRank() {
    return m_rank;
}
int Card :: getValue() {
    return m_value;
}
string Card :: getCard() {
    return m_rank + " of " + m_suit;
}
