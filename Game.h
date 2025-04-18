//
// Created by administrator on 4/15/25.
//

#ifndef GAME_H
#define GAME_H
#include "Deck.h"
#include "Hand.h"


class Game {
    private:
    Deck m_deck;
    Hand m_dealerhand;
    Hand m_playerhand;
    public:
    Game();
    Hand get_playerhand(Deck&, Hand);
    Hand get_dealerhand(Deck&, Hand);
    void display_Cards(Hand, string);
    void display_Round();
    void play_Game();


};



#endif //GAME_H
