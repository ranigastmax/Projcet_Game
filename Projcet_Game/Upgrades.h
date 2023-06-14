#pragma once
#include"Player.h"
#include "Button.h"
class Upgrades :
    public Button
{
public:
    Upgrades(int top, int left, std::string pathNotClicked, std::string pathClicked, std::string pathMouseIsOver, int scalex, int scaley);
    void HP_boost(Player &player);
    void MeleAttack_boost(Player& player);
    void Stamina_boost(Player& player);
    void RangeAttack_boost(Player& player);
   
};

