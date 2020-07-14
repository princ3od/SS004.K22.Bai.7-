#pragma once
#include "Library.h"
#include "GamePlay.h"
static bool _lgbt;
class Menu 
{
public:
    static int StartMenu(bool& isLGBT_);
    static int Choices(GameDifficult& _gd, GameMode& _gm, bool& isLGBT_);
};


