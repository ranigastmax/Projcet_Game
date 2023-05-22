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

void Characters::animateWalk()
{
    //walk left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {

        this->hero.setTexture(walk_left_texture);
        this->hero_speedX = -1;
        //std::cout << "ustawiam texture w lewo" << std::endl;
        leftFLAG = true;
        rightFLAG = false;
        downFLAG = false;
        upFLAG = false;

        if ((leftFLAG) && (clock.getElapsedTime().asSeconds() > 0.3))
        {
            if (this->i >= 6) { this->i = 0; }
            this->hero.setTextureRect(walkLeft[i]);
            i++;
            clock.restart();
        }
    }

    //walk right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->hero.setTexture(walk_right_texture);
        this->hero_speedX = 1;
        //std::cout << "ustawiam texture w prawo" << std::endl;
        rightFLAG = true;
        leftFLAG = false;
        downFLAG = false;
        upFLAG = false;

        if ((rightFLAG) && (clock.getElapsedTime().asSeconds() > 0.3))
        {
            if (this->i >= 6) { this->i = 0; }
            this->hero.setTextureRect(walkRight[i]);
            i++;
            clock.restart();
        }
    }

    //walk down-left-rigt
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->hero.setTexture(walk_down_texture);
        this->hero_speedY = 1;
        //std::cout << "ustawiam texture w dol" << std::endl;
        downFLAG = true;
        leftFLAG = false;
        rightFLAG = false;
        upFLAG = false;

        if (downFLAG && clock.getElapsedTime().asSeconds() > 0.3)
        {
            if (this->i >= 6) { this->i = 0; }
            this->hero.setTextureRect(walkDown[i]);
            i++;
            clock.restart();
        }
    }

    //walk up-left right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->hero.setTexture(walk_up_texture);
        this->hero_speedY = -1;
        // std::cout << "ustawiam texture w gore" << std::endl;

        upFLAG = true;
        downFLAG = false;
        leftFLAG = false;
        rightFLAG = false;

        if (upFLAG && clock.getElapsedTime().asSeconds() > 0.3)
        {
            if (this->i >= 6) { this->i = 0; }
            this->hero.setTextureRect(walkUp[i]);
            i++;
            clock.restart();
        }
    }
}

void Characters::animateAttackMele()
{
    //attack left
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (leftFLAG))
    {
        std::cout << "ustawiam texture na atak w lewo" << std::endl;
        this->hero.setTexture(attack_mele_left_texture);

    }

    //attack right
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (rightFLAG))
    {
        std::cout << "ustawiam texture na atak w prawo" << std::endl;
        this->hero.setTexture(attack_mele_right_texture);
    }

    //attack down-left-rigt
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (downFLAG))
    {
        std::cout << "ustawiam texture na atak w dol" << std::endl;
        this->hero.setTexture(attack_mele_down_texture);

    }

    //attack up-left-rigt
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (upFLAG))
    {
        std::cout << "ustawiam texture na atak w gore" << std::endl;
        this->hero.setTexture(attack_mele_up_texture);
    }

}

void Characters::animateAttackDistance()
{
    //attack left
    this->hero.setTexture(attack_distance_left_texture);


    //attack right
    this->hero.setTexture(attack_distance_right_texture);


    //attack down-left-rigt
    this->hero.setTexture(attack_distance_down_texture);


    //attack up-left-rigt
    this->hero.setTexture(attack_distance_up_texture);

}

void Characters::animateDeath()
{
    this->hero.setTexture(death_texture);
}
