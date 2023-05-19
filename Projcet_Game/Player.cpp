#include "Player.h"



void Player::initPlayer()
{

}

void Player::loadTexture(std::string path, sf::Texture& textureName)
{
    if (!textureName.loadFromFile(path)) {
        std::cerr << "Could not load texture" << std::endl;
    }

}

Player::Player()
{
    //load all textures from files
    this->loadTexture("textures/idle_down_40x40.png", breath_texture);
    this->loadTexture("textures/run_up_40x40.png", walk_up_texture);
    this->loadTexture("textures/run_down_40x40.png", walk_down_texture);
    this->loadTexture("textures/run_right_40x40.png", walk_right_texture);
    this->loadTexture("textures/run_left_40x40.png", walk_left_texture);
    this->loadTexture("textures/attack_up_40x40.png", attack_mele_up_texture);
    this->loadTexture("textures/attack_down_40x40.png", attack_mele_down_texture);
    this->loadTexture("textures/attack_right_40x40.png", attack_mele_right_texture);
    this->loadTexture("textures/attack_left_40x40.png", attack_mele_left_texture);
    this->loadTexture("textures/attack_up_40x40.png", attack_distance_up_texture);
    this->loadTexture("textures/attack_down_40x40.png", attack_distance_down_texture);
    this->loadTexture("textures/attack_right_40x40.png", attack_distance_right_texture);
    this->loadTexture("textures/attack_left_40x40.png", attack_distance_left_texture);
    this->loadTexture("textures/death_right_40x40.png", death_texture);
    //end of loadnig all textures
    this->hero.setTexture(breath_texture);
    this->hero.setTextureRect(sf::IntRect(9, 9, 19, 24));
    this->hero.setPosition(300, 400);
    this->hero.setScale(2.f, 2.f);
    this->initIntRect();
    





}

Player::~Player()
{



}

void Player::render(sf::RenderTarget& target)
{
    target.draw(this->hero);

}

void Player::update()
{
    animateBreath();
    playerMove();

}



void Player::animateBreath()
{
    //breath
        if (clock.getElapsedTime().asSeconds() > 0.6)
        {
            //this->hero.setTexture(breath_texture);
            if (this->i == 3) { this->i = 0; }
            this->hero.setTextureRect(breath[i]);
            i++;
            clock.restart();
        }
  

}

void Player::animateWalk()
{
        //walk left

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {

            this->hero.setTexture(walk_left_texture);
            std::cout << "ustawiam texture w lewo" << std::endl;
            leftFLAG = true;
            rightFLAG = false;
            downFLAG = false;
            upFLAG = false;

            if ((leftFLAG) && (clock.getElapsedTime().asSeconds() > 0.3))
            {
                if (this->i == 6) { this->i = 0; }
                this->hero.setTextureRect(walkLeft[i]);
                i++;
                clock.restart();
            }
        }

        //walk right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            this->hero.setTexture(walk_right_texture);
            std::cout << "ustawiam texture w prawo" << std::endl;
            rightFLAG = true;
            leftFLAG = false;
            downFLAG = false;
            upFLAG = false;
                std::cout << clock.getElapsedTime().asSeconds() << std::endl;
               std::cout << i << std::endl;
            if ((rightFLAG) && (clock.getElapsedTime().asSeconds() > 0.3))
            {
                if (this->i == 6) { this->i = 0; }
                this->hero.setTextureRect(walkRight[i]);
                i++;
                clock.restart();
            }
        }
        else { rightFLAG = false; }


        //walk down-left-rigt
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            this->hero.setTexture(walk_down_texture);
            std::cout << "ustawiam texture w dol" << std::endl;
            downFLAG = true;
            leftFLAG = false;
            rightFLAG = false;
            upFLAG = false;
        }

        //walk up-left right
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            this->hero.setTexture(walk_up_texture);
            std::cout << "ustawiam texture w gore" << std::endl;

            upFLAG = true;
            downFLAG = false;
            leftFLAG = false;
            rightFLAG = false;
        }



}

void Player::animateAttackMele()
{
    //attack left
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left))&&(leftFLAG))
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

void Player::animateAttackDistance()
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

void Player::animateDeath()
{
    this->hero.setTexture(death_texture);
}

void Player::playerMove()
{
    //if (upFLAG) { this->hero_speedY = -1; }
    //if (downFLAG) { this->hero_speedY = 1; }
    //if (leftFLAG) { this->hero_speedX = -1; }
    //if (rightFLAG) { this->hero_speedX = 1; }

    this->hero.move(hero_speedX, hero_speedY);
}

void Player::initIntRect()
{
    //walk left
    this->walkLeft.emplace_back(13,8,16,24);
    this->walkLeft.emplace_back(53,8,16,24);
    this->walkLeft.emplace_back(93,9,17,23);
    this->walkLeft.emplace_back(133,8,18,24);
    this->walkLeft.emplace_back(173,8,18,24);
    this->walkLeft.emplace_back(213,9,17,23);
    //walk right
    this->walkRight.emplace_back(10,8,18,24);
    this->walkRight.emplace_back(50,8,18,24);
    this->walkRight.emplace_back(91,8,17,23);
    this->walkRight.emplace_back(132,8,16,24);
    this->walkRight.emplace_back(172,8,16,24);
    this->walkRight.emplace_back(211,9,17,23);

    //walk down
    this->walkDown.emplace_back(9,18,19,24);
    this->walkDown.emplace_back(49,8,19,24);
    this->walkDown.emplace_back(90,9,18,23);
    this->walkDown.emplace_back(131,8,17,24);
    this->walkDown.emplace_back(171,8,17,24);
    this->walkDown.emplace_back(210,9,18,23);

    //walk up
    this->walkUp.emplace_back(13,8,16,24);
    this->walkUp.emplace_back(53,8,16,24);
    this->walkUp.emplace_back(93,9,15,23);
    this->walkUp.emplace_back(133,8,15,24);
    this->walkUp.emplace_back(173,8,15,24);
    this->walkUp.emplace_back(213,9,15,23);

    //attac left mele
    this->meleAttackLEFT.emplace_back(8,8,20,24 );
    this->meleAttackLEFT.emplace_back(51,8,17,24);
    this->meleAttackLEFT.emplace_back(93,8,15,24);
    this->meleAttackLEFT.emplace_back(127,6,22,26);
    this->meleAttackLEFT.emplace_back(163,4,25,29);
    this->meleAttackLEFT.emplace_back(203,10,25,25);
    this->meleAttackLEFT.emplace_back(250,9,18,23);


    //atac right mele
    this->meleAttackRIGHT.emplace_back(11,8,17,24);
    this->meleAttackRIGHT.emplace_back(51,8,17,24);
    this->meleAttackRIGHT.emplace_back(88,8,20,24);
    this->meleAttackRIGHT.emplace_back(129,8,20,24);
    this->meleAttackRIGHT.emplace_back(176,9,21,23);
    this->meleAttackRIGHT.emplace_back(216,11,22,25);
    this->meleAttackRIGHT.emplace_back(256,10,16,22);

    //attack down mele
    this->meleAttackDOWN.emplace_back(11,8,17,24);
    this->meleAttackDOWN.emplace_back(50,8,18,24);
    this->meleAttackDOWN.emplace_back(89,8,19,24);
    this->meleAttackDOWN.emplace_back(129,10,20,24);
    this->meleAttackDOWN.emplace_back(172,12,18,26);
    this->meleAttackDOWN.emplace_back(215,13,15,27);
    this->meleAttackDOWN.emplace_back(255,12,15,23);

    //attac up mele
    this->meleAttackUP.emplace_back(13,8,17,24);
    this->meleAttackUP.emplace_back(53,8,17,24);
    this->meleAttackUP.emplace_back(93,8,18,24);
    this->meleAttackUP.emplace_back(132,7,19,25);
    this->meleAttackUP.emplace_back(169,0,19,32);
    this->meleAttackUP.emplace_back(208,0,17,32);
    this->meleAttackUP.emplace_back(251,6,15,26);

    //attac right distance
    this->distanceAttackRIGHT.emplace_back();
    this->distanceAttackRIGHT.emplace_back();
    this->distanceAttackRIGHT.emplace_back();
    this->distanceAttackRIGHT.emplace_back();
    this->distanceAttackRIGHT.emplace_back();
    this->distanceAttackRIGHT.emplace_back();

    //attac left distance
   /* this->distanceAttackLEFT.emplace_back();
    this->distanceAttackLEFT.emplace_back();
    this->distanceAttackLEFT.emplace_back();
    this->distanceAttackLEFT.emplace_back();
    this->distanceAttackLEFT.emplace_back();
    this->distanceAttackLEFT.emplace_back();

    //attac down distance
    this->distanceAttackDOWN.emplace_back();
    this->distanceAttackDOWN.emplace_back();
    this->distanceAttackDOWN.emplace_back();
    this->distanceAttackDOWN.emplace_back();
    this->distanceAttackDOWN.emplace_back();
    this->distanceAttackDOWN.emplace_back();

    //attac right distance
    this->distanceAttackRIGHT.emplace_back();
    this->distanceAttackRIGHT.emplace_back();
    this->distanceAttackRIGHT.emplace_back();
    this->distanceAttackRIGHT.emplace_back();
    this->distanceAttackRIGHT.emplace_back();
    this->distanceAttackRIGHT.emplace_back();
  */  
    //breath
    this->breath.emplace_back(10,9,18,23);
    this->breath.emplace_back(50,9,18,23);
    this->breath.emplace_back(90,9,18,23);
    this->breath.emplace_back(130,8,18,24);

    //death
    this->death.emplace_back(10,8,18,24);
    this->death.emplace_back(50,9,18,23);
    this->death.emplace_back(90,10,18,22);
    this->death.emplace_back(130,12,18,20);
    this->death.emplace_back(170,15,18,17);
    this->death.emplace_back(210,18,18,14);
    this->death.emplace_back(252,20,15,20);
    this->death.emplace_back(253,18,15,22);
    this->death.emplace_back(333,18,15,22);




}

