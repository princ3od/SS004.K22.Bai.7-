#pragma once
#include "Library.h"
#include "GamePlay.h"
static bool isLGBT_;
class Menu 
{
public:
    static int StartMenu(bool& _islgbt);
    static void Choices(short int& level, GameDifficult& _gd, GameMode& _gm, unsigned short int _unlock, bool& _islgbt);
};


