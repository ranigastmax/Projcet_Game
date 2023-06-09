#include "Characters.h"

void Characters::loadTexture(std::string path, sf::Texture& textureName)
{
    if (!textureName.loadFromFile(path)) {
        std::cerr << "Could not load texture" << std::endl;
    }
}


Characters::~Characters()
{
}

sf::Sprite Characters::getSprite()
{
    return this->hero;
}

void Characters::adjustHp(float amount)
{
    std::cout << hp << std::endl;
    this->hp += amount;
}

void Characters::render(sf::RenderTarget& target)
{
	target.draw(this->hero);
}

void Characters::update()
{
	this->hero.move(hero_speedX, hero_speedY);
}

void Characters::animateBreath()
{
    if ((!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) && (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)))
    {
        if (clock.getElapsedTime().asSeconds() > 0.6)
        {
            this->hero.setTexture(breath_texture);
            if (this->i >= 4) { this->i = 0; }
            this->hero.setTextureRect(breath[i]);
            i++;
            clock.restart();
        }
        this->hero_speedX = 0;
        this->hero_speedY = 0;
        this->leftFLAG = false;
        this->rightFLAG = false;
        this->downFLAG = false;
        this->upFLAG = false;
    }
}

int Characters::getHP()
{
    return this->hp;
}



