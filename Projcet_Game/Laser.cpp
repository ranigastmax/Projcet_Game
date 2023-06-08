#include "Laser.h"

#include<iostream>



Laser::Laser(sf::FloatRect hero, sf::Vector2f target)
{
   // frames.emplace_back(22, 6, 18, 17);
   // frames.emplace_back(3, 6, 18, 17);
//frames.emplace_back(3, 27, 18, 17);
    laser = new sf::Sprite;
    if (!laser_texture.loadFromFile("textures/Laser.png"))
    {
        std::cout << ";;;;;;";
    }
    laser->setTexture(laser_texture);
    laser->scale(2, 2);
  //  laser->setTextureRect(sf::IntRect(1, 1, 13, 7));
    centerX = hero.left + hero.width / 2;
    centerY = hero.top + hero.height / 2;
    laser->setPosition(centerX, centerY);
    direction = target - laser->getPosition();
    length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;
}

sf::Sprite Laser::render()
{
    return *laser;
}

void Laser::movef()
{
   
    laser->move(direction.x * speed, direction.y * speed);
    move = true;

}

void Laser::animate()
{
    if (move && clock.getElapsedTime().asSeconds() > 0.1)
    {
        if (i == 2) { i = 0; }
        laser->setTextureRect(frames[i]);
        i++;
        clock.restart();
    }
}

bool Laser::collision(sf::FloatRect& enemies, std::vector<sf::FloatRect>& walls)
{

   
    if (this->laser->getGlobalBounds().intersects(enemies))
    {
        return true;
    }
    
    for (auto wall : walls)
    {
        if (this->laser->getGlobalBounds().intersects(wall))
        {
            return true;
        }
    }
    return false;

}

sf::Sprite Laser::getSprite()
{
    return *this->laser;
}


