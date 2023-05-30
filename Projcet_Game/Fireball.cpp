#include "Fireball.h"
#include<iostream>

Fireball::Fireball()
{
}

Fireball::Fireball(sf::FloatRect hero, sf::Vector2f mousePosition)
{
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

void Fireball::move()
{
    std::cout << "chuj----------------------------" << direction.x << std::endl;
    std::cout << "chuj----------------------------" << direction.y << std::endl;
    fireball->move(direction.x * speed, direction.y * speed);
}

