cmake_minimum_required(VERSION 3.29)
project(Black_Jack_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Black_Jack_2 main.cpp
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h
        Hand.cpp
        Hand.h
        Game.cpp
        Game.h)
