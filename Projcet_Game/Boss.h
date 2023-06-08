#pragma once
#include<SFML/Graphics.hpp>
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
    void getBounds(std::vector<sf::FloatRect>& enemy_bounds, std::vector<sf::FloatRect>& wall_bounds)
    void laserAttack(sf::Vector2f target);

    void position(sf::FloatRect);

    void rangeattack();

    void initIntRect();

    void initcharacters();



};

