#include "Player.h"


void Player::initcharacters()
{

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
    movingLeft = false;
    movingRight = false;
    movingUp = false;
    movingDown = false;
}
Player::~Player()
{
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
    this->walkRight.emplace_back(91,8,17,24);
    this->walkRight.emplace_back(132,8,16,24);
    this->walkRight.emplace_back(172,8,16,24);
    this->walkRight.emplace_back(211,8,17,24);

    //walk down
    this->walkDown.emplace_back(9,8,19,24);
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
void Player::update()
{
    if (movingLeft && !blockLeft)
    {
        this->targetX = -1;
    }
    else if (movingRight && !blockRight)
    {
        this->targetX = 1;
    }
    else
    {
        this->targetX = 0;
    }

    if (movingUp && !blockUp)
    {
        this->targetY = -1;
    }
    else if (movingDown &&  !blockDown)
    {
        this->targetY = 1;
    }
    else
    {
        this->targetY = 0;
    }
    if (this->x < this->targetX)
    {
        this->x += 0.02f;
        if (this->x > this->targetX)
            this->x = this->targetX;
    }
    else if (this->x > this->targetX)
    {
        this->x -= 0.02f;
        if (this->x < this->targetX)
            this->x = this->targetX;
    }
    if (this->y < this->targetY)
    {
        this->y += 0.02f;
        if (this->y > this->targetY)
            this->y = this->targetY;
    }
    else if (this->y > this->targetY)
    {
        this->y -= 0.02f;
        if (this->y < this->targetY)
            this->y = this->targetY;
    }

    this->hero.move(x, y);
}
void Player::move()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)&&!movingRight&&!blockLeft)
    {
        movingLeft = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)&&!movingLeft && !blockRight)
    {
        movingRight = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)&&!movingUp && !blockDown)
    {
        movingDown = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)&&!movingDown && !blockUp)
    {
        movingUp = true;
    }


}
void Player::animateWalk()
{
    if (walking)
    {
        if (movingLeft && clock.getElapsedTime().asSeconds() > 0.2)
        {
            std::cout << i << std::endl;
            
            this->hero.setTexture(walk_left_texture);   
            if (this->i >= 6) { this->i = 0; }
            this->hero.setTextureRect(walkLeft[i]);
            i++;
            clock.restart();
        }
        if (movingRight && clock.getElapsedTime().asSeconds() > 0.2)
        {
            std::cout << i << std::endl;
            this->hero.setTexture(walk_right_texture);
            if (this->i >= 6) { this->i = 0; }
            this->hero.setTextureRect(walkRight[i]);
            i++;
            clock.restart();
        }
        if (movingDown && clock.getElapsedTime().asSeconds() > 0.2)
        {
            this->hero.setTexture(walk_down_texture);
            if (this->i >= 6) { this->i = 0; }
            this->hero.setTextureRect(walkDown[i]);
            i++;
            clock.restart();
        }
        if (movingUp && clock.getElapsedTime().asSeconds() > 0.2)
        {
            this->hero.setTexture(walk_up_texture);
            if (this->i >= 6) { this->i = 0; }
            this->hero.setTextureRect(walkUp[i]);
            i++;
            clock.restart();
        }

 }

        
}
    void Player::animateAttackMele()
    {
        //attack left
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (hero.getTexture() == &walk_left_texture) || (hero.getTexture() == &attack_mele_left_texture))
        {
            std::cout << "ustawiam texture na atak w lewo" << std::endl;
            this->hero.setTexture(attack_mele_left_texture);
            this->attack = true;
        }

        //attack right
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (hero.getTexture() == &walk_right_texture) || (hero.getTexture() == &attack_mele_right_texture))
        {
            std::cout << "ustawiam texture na atak w prawo" << std::endl;
            this->hero.setTexture(attack_mele_right_texture);
            this->attack = true;
        }

        //attack down-left-rigt
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (hero.getTexture() == &walk_down_texture) || (hero.getTexture() == &attack_mele_down_texture))
        {
            std::cout << "ustawiam texture na atak w dol" << std::endl;
            this->hero.setTexture(attack_mele_down_texture);
            this->attack = true;
        }

        //attack up-left-rigt
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (hero.getTexture() == &walk_up_texture) || (hero.getTexture() == &attack_mele_up_texture))
        {
            std::cout << "ustawiam texture na atak w gore" << std::endl;
            this->hero.setTexture(attack_mele_up_texture);
            this->attack = true;
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
    void Player::releasedAD()
    {
        movingLeft = false;
        movingRight = false;
    }
    void Player::releasedWS()
    {
        movingUp = false;
        movingDown = false;
    }

    void Player::animationattack()
    {

        if (attack)
        {
            
            if (clock.getElapsedTime().asSeconds() > 0.07)
            {
                if (this->j > 6) { this->j = 0; attack = false; }
                this->hero.setTextureRect(meleAttackLEFT[this->j]);
                this->j++;

                clock.restart();
            }
           
        }

    }
    void Player::bounds(std::vector<sf::FloatRect> wall_bounds)
    {



        for (auto obj : wall_bounds)
        {
            if (this->hero.getGlobalBounds().intersects(obj))
            {
               // std::cout << "collision" << std::endl;
                rect_collision.push_back(obj);
            }
            else
            {
                blockLeft = false;
                blockRight = false;
                blockUp = false;
                blockDown = false;
            }
        }
        std::cout << rect_collision.size() << std::endl;
        if (!rect_collision.empty())
        {
    heroDown = hero.getGlobalBounds().top + hero.getGlobalBounds().height;
    heroTop = hero.getGlobalBounds().top;
    heroLeft = hero.getGlobalBounds().left;
    heroRight = hero.getGlobalBounds().left + hero.getGlobalBounds().width;
   // std::cout << " --left--" << heroLeft << "--top--" << heroTop << "--right--" << heroRight << "--down--" << heroDown << std::endl;
            for (auto& obj : rect_collision)
            {
             
               // std::cout << " --left--" << obj.left << "--top--" << obj.top << "--right--" << obj.left + obj.width << "--down--" << obj.top + obj.height << std::endl;
                if (heroRight > obj.left && heroLeft < obj.left + obj.width && heroTop > obj.top && heroDown < obj.top + obj.height)
                {
                    blockRight = true;







                   /* if (heroRight > obj.left && heroRight < obj.left + obj.width)
                    {
                        std::cout << "prawo" << std::endl;
                        blockRight = true;
                    }
                    else if (heroLeft < obj.left + obj.width && heroLeft > obj.left)
                    {
                        blockLeft = true;
                        std::cout << "lewo" << std::endl;
                    }*/
                }
                if (heroTop<obj.top + obj.height && heroDown > obj.top && heroLeft > obj.left && heroRight < obj.left + obj.width)
                {
                    blockUp = true;
                    /*
                    if (heroTop < obj.top + obj.height && heroTop > obj.top)
                    {
                        std::cout << "gora" << std::endl;
                        blockUp = true;
                    }
                    else if (heroDown > obj.top && heroDown < obj.top + obj.height)
                    {
                        std::cout << "dol" << std::endl;
                        blockDown = true;
                    }
                    */
                }
            }
        }
    }
