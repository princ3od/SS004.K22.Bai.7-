#pragma once
#include "Library.h"
#include "GamePlay.h"
class Menu: public GamePlay
{
public:
    static int StartMenu();
    //static GameMode GamemodeMenu();
    int GameMode();
};


