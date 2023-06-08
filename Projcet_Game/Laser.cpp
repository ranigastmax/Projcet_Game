#include "Laser.h"

#include<iostream>



Laser::Laser(sf::FloatRect hero, sf::Vector2f target)
{
    laser = new sf::Sprite;
    if (!laser_texture.loadFromFile("textures/Laser.png"))
    {
        std::cout << ";;;;;;";
    }
    laser->setTexture(laser_texture);
    laser->scale(2, 2);
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
   
    this->laser->move(direction.x * speed, direction.y * speed);
    //move = true;

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

void Laser::render(sf::RenderWindow& window)
{
    window.draw(*this->laser);
}

bool Laser::collision(sf::FloatRect& enemy, std::vector<sf::FloatRect>& walls)
{

   
    if (this->laser->getGlobalBounds().intersects(enemy))
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






