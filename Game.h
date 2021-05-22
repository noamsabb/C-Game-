//
// Created by Noam Sabban on 30/12/2019.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


#include "NumSet.h"

class Game {

private:
    NumSet** _tab;

public:

    Game();
    ~Game();

    int findCard(int player, int num);
    static int tirage();
    void chooseWinner();

    void gameMenu();
    void playerVsPlayer();
    void playerVsComp();
    void compVsComp();


    void print(int player);
};


#endif //UNTITLED_GAME_H
