//
// Created by administrator on 4/15/25.
//

#include "Game.h"

#include <iostream>

Game:: Game(){}

Hand Game::get_playerhand(Deck& deck, Hand hand) {
    hand += deck.dealCard();
    //hand += deck.dealCard();
    return hand;
}

Hand Game::get_dealerhand(Deck& deck, Hand hand) {
    hand += deck.dealCard();
    //hand += deck.dealCard();
    return hand;
}

void Game::display_Cards(Hand hand, string player_or_dealer) {
    cout << player_or_dealer << "'s Cards:\n";
    for(int i =0; i < hand.cardCount(); i++) {
        cout << hand.displayCard(i).getCard() << endl;
    }
    cout << "'s Points: " << hand.getPoints() << endl;
}

void Game::display_Round() {
    m_playerhand.clearHand();
    m_dealerhand.clearHand();

    m_playerhand += m_deck.dealCard();
    m_dealerhand += m_deck.dealCard();

    m_playerhand = get_playerhand(m_deck, m_playerhand);
    m_dealerhand = get_dealerhand(m_deck, m_dealerhand);

    cout << "\n###########################\n";
    cout << "#  The Game of Blackjack  #\n";
    cout << "##########################\n\n";
    cout << "Dealer's Show Card:\n" << m_dealerhand.displayCard(0).getCard() << "\n\n";

    cout << "Your Cards:\n";
    for(int i = 0; i < m_playerhand.cardCount(); i++) {
        cout << m_playerhand.displayCard(i).getCard() << endl;
    }
}

void Game::play_Game() {
    char again = 'y';
    while(again == 'y') {
        display_Round();

        char choice;
        while(true) {
            cout << "hit or stand? (h/s):";
           // cout << m_deck.getCount(); //testing !!!!
            cin >> choice;
            if(choice == 'h') {
                m_playerhand += m_deck.dealCard();
                cout << "\nYour Cards:\n";
                for(int i = 0; i < m_playerhand.cardCount(); i++) {
                    cout << m_playerhand.displayCard(i).getCard() << endl;
                }
                if(m_playerhand.getPoints() > 21) {
                    cout << "\nYour Points:\n" << m_playerhand.getPoints() << endl;
                    cout << "Sorry. You busted. You lose." << endl;
                    break;
                }
            }
            else if(choice == 's') {
                break;
            }

        }
        if(m_playerhand.getPoints() <= 21) {
            while(m_dealerhand.getPoints() < 17 || m_dealerhand.getPoints() == 17 ) {
                m_dealerhand += m_deck.dealCard();
            }
            cout << "\nDealer's Cards:\n";
            for(int i = 0; i < m_dealerhand.cardCount(); i++) {
                cout << m_dealerhand.displayCard(i).getCard() << endl;
            }
            int player_points = m_playerhand.getPoints();
            int dealer_points = m_dealerhand.getPoints();

            cout << "\nYour Points:     " << player_points << endl;
            cout << "Dealer's Points: " << dealer_points << endl;

            if(player_points == 21 and m_playerhand.cardCount() == 2 and dealer_points == 21 and m_playerhand.cardCount() == 2) {
                cout << "Dang, dealer has blackjack too. You push.\n";
            }else if(player_points == 21 and m_playerhand.cardCount() == 2) {
                cout << "Blackjack! You win!\n";
            }else if(dealer_points == 21 and m_dealerhand.cardCount() == 2 and m_playerhand.cardCount() == 21) {
                cout << "Dealer has Blackjack. You lose.\n";
            }else if(dealer_points > 21) {
                cout << "Yay! The dealer busted. You win!\n";
            }else if(player_points > dealer_points) {
                cout << "Hooray! You win!\n";
            }else if(dealer_points == player_points) {
                cout<< "It's a tie! You push.\n";
            }else{
                cout << "Sorry. You lose.\n";
            }
        }
        cout << "\nplay another round? (y/n): ";
        cin >> again;
    }
    cout << "\nThanks for playing!\n";
}



