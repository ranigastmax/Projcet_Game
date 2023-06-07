#include "Fireball.h"
#include<iostream>

Fireball::Fireball()
{
}

Fireball::Fireball(sf::FloatRect hero, sf::Vector2f mousePosition)
{
    frames.emplace_back(22,6,18,17);
    frames.emplace_back(3,6,18,17);
    frames.emplace_back(3,27,18,17);
    fireball = new sf::Sprite;
    if (!fireball_texture.loadFromFile("textures/fire_ball.png"))
    {
        std::cout << ";;;;;;";
    }
    fireball->setTexture(fireball_texture);
    fireball->scale(2, 2);
    fireball->setTextureRect(sf::IntRect(1, 1, 13, 7));
    centerX = hero.left + hero.width/2;
    centerY = hero.top + hero.height/2 ;
    fireball->setPosition(centerX, centerY);
    direction = mousePosition - fireball->getPosition();
    length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
    direction /= length;
}

sf::Sprite Fireball::render()
{
    return *fireball;
}

void Fireball::movef()
{
    //::cout << "----------------------------" << fireball->getGlobalBounds().left << std::endl;
   // std::cout << "----------------------------" << fireball->getGlobalBounds().top << std::endl;
    fireball->move(direction.x * speed, direction.y * speed);
    move = true;
    
}

void Fireball::animate()
{
    if (move && clock.getElapsedTime().asSeconds() > 0.1)
    {
        if (i == 3) { i = 0; }
        fireball->setTextureRect(frames[i]);
        i++;
        clock.restart();
    }
}

bool Fireball::collision(std::vector<sf::FloatRect> &enemies, std::vector<sf::FloatRect> &walls)
{

    for (auto enemy : enemies)
    {
        if (this->fireball->getGlobalBounds().intersects(enemy))
        {
            return true;
        }
    }
    for (auto wall : walls)
    {
        if (this->fireball->getGlobalBounds().intersects(wall))
        {
            return true;
        }
    }
    return false;

}


