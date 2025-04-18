//
// Created by administrator on 4/7/25.
//

#ifndef CARD_H
#define CARD_H
using namespace std;
#include <string>


class Card {
private:
    string m_suit;
    string m_rank;
    int m_value;
public:
    Card();
    Card(string suit, string rank, int value);
    string getRank();
    int getValue();
    string getCard();

};



#endif //CARD_H
