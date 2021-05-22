#pragma once
#include "cmake-build-debug/NumSet.h"

class Game
{
    NumSet _p1;
    NumSet _p2;
    int strategy;
public:
    Game(int strategy) {
        //this->_p1 = NumSet();
        //this->_p2 = NumSet();
        this->strategy = strategy;
    }
    void playerVScomp();
    void playerVSplayer();
    void  compVScomp();
    void winner();
    void menu();
};

