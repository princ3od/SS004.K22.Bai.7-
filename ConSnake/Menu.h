#pragma once
#include "Library.h"
#include "GamePlay.h"
class Menu 
{
public:
    static int StartMenu(bool& isLGBT_);
    static int Choices(short int& level, GameDifficult& _gd, GameMode& _gm, bool& isLGBT_);
};


