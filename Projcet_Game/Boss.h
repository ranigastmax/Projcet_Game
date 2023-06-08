#pragma once
#include<SFML/Graphics.hpp>
#include "iostream"
#include"Characters.h"
#include"Laser.h"
class Boss :
    public Characters
{
    bool animationUp;
    int i = 11;
    sf::Clock clock2;
    Laser* laser1;
    Laser* laser2;
    bool isShootingOne;
    bool isShootingTwo;
   
public:
    Boss();

    void laserAttack(sf::FloatRect target, std::vector<sf::FloatRect>& walls, sf::RenderWindow&);

    void position(sf::FloatRect);

    void rangeattack();

    void initIntRect();

    void initcharacters();

    void render(sf::RenderWindow&);

    void* getPointer1();
    void* getPointer2();

};

