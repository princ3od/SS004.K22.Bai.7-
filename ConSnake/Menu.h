#pragma once
#include "Library.h"
#include "GamePlay.h"
class Menu 
{
public:
    static int StartMenu(bool& isLGBT_);
    static void Choices(short int& level, GameDifficult& _gd, GameMode& _gm, unsigned short int _unlock, bool& isLGBT_);
};


