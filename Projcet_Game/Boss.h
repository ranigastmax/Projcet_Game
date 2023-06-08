#pragma once
#include<SFML/Graphics.hpp>
#include"Characters.h"
class Boss :
    public Characters
{
    bool animationUp;


public:
    Boss();

    void position(sf::FloatRect);

    void rangeattack();

    void initIntRect();

    void initcharacters();



};

