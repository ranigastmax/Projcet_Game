#include "Player.h"


void Player::initcharacters()
{

}

Player::Player()
{

    //load all textures from files
    this->loadTexture("textures/idle_down.png", breath_texture);
    this->loadTexture("textures/run_up.png", walk_up_texture);
    this->loadTexture("textures/run_down.png", walk_down_texture);
    this->loadTexture("textures/run_right.png", walk_right_texture);
    this->loadTexture("textures/run_left.png", walk_left_texture);
    this->loadTexture("textures/attack_up.png", attack_mele_up_texture);
    this->loadTexture("textures/attack_down.png", attack_mele_down_texture);
    this->loadTexture("textures/attack_right.png", attack_mele_right_texture);
    this->loadTexture("textures/attack_left.png", attack_mele_left_texture);
    this->loadTexture("textures/attack_distance_up.png", attack_distance_up_texture);
    this->loadTexture("textures/attack_distance_down.png", attack_distance_down_texture);
    this->loadTexture("textures/attack_distance_left.png", attack_distance_left_texture);
    this->loadTexture("textures/death_left.png", death_texture_left);
    this->loadTexture("textures/death_right.png", death_texture_right);
    this->loadTexture("textures/death_down.png", death_texture_down);
    this->loadTexture("textures/death_up.png", death_texture_up);
    this->loadTexture("textures/Sword01.png", sword_texture);
    this->loadTexture("textures/EnergySword01.png", fire_sword_texture);
    this->loadTexture("textures/attack_right_distance.png", attack_distance_right_texture);
    this->loadTexture("textures/HpChange.png", hp_texture);
    this->loadTexture("textures/StaminaChange.png", stamina_texture);
    this->loadTexture("textures/BloodOverlay.png", blood_teture);

    //end of loadnig all textures
    //text settings
    font.loadFromFile("textures/Augusta.ttf");
    this->text.setPosition(455, 8);
    this->text.setFont(font);
    this->text.scale(0.6,0.6);
    this->text.setFillColor(sf::Color(226, 226, 226));
    blood.setTexture(blood_teture);
    blood.setColor(sf::Color(255, 255, 255, 0));
    blood.scale(2.53, 4.15);
    

    //set init stats
    movingLeft = false;
    movingRight = false;
    movingUp = false;
    movingDown = false;
    scroll = false;

    //hp settings
    adjustHp(this->maxHP);
    this->HP.setTexture(hp_texture);
    this->HP.setPosition(497,40);

    //stamina settings
    adjustStamina(this->maxStamina+20);
    this->STAMINA.setTexture(stamina_texture);
    this->STAMINA.setPosition(497, 70);
     
    
    //sword settings
    this->sword.setTexture(sword_texture);
    this->sword.setPosition(423,8);
    this->sword.scale(1,1);
    
    //hero settings
    this->hero.setTexture(breath_texture);
    this->hero.setTextureRect(sf::IntRect(9, 9, 19, 24));
    this->hero.setPosition(300, 400);
    this->hero.setScale(2.f, 2.f);
    this->initIntRect();
    
    
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

    //attac left distance
    this->distanceAttackLEFT.emplace_back(8,8,20,24 );
    this->distanceAttackLEFT.emplace_back(51,8,17,24);
    this->distanceAttackLEFT.emplace_back(93,8,15,24);
    this->distanceAttackLEFT.emplace_back(127,6,22,26);
    this->distanceAttackLEFT.emplace_back(160,4,28,30);
    this->distanceAttackLEFT.emplace_back(201,10,27,25);
    this->distanceAttackLEFT.emplace_back(251,9,17,23);

    //attac down distance
    this->distanceAttackDOWN.emplace_back(11, 8, 17, 24);
    this->distanceAttackDOWN.emplace_back(50, 8, 18, 24);
    this->distanceAttackDOWN.emplace_back(89, 8, 19, 24);
    this->distanceAttackDOWN.emplace_back(129, 10, 20, 24);
    this->distanceAttackDOWN.emplace_back(173,12,17,24);
    this->distanceAttackDOWN.emplace_back(215,13,15,27);
    this->distanceAttackDOWN.emplace_back(255,12,15,28);
    //attac up distance
    this->distanceAttackUP.emplace_back(13, 8, 17, 24);
    this->distanceAttackUP.emplace_back(53, 8, 17, 24);
    this->distanceAttackUP.emplace_back(93, 8, 18, 24);
    this->distanceAttackUP.emplace_back(132, 4, 19, 26);
    this->distanceAttackUP.emplace_back(169, 0, 17, 32);
    this->distanceAttackUP.emplace_back(208, 0, 17, 32);
    this->distanceAttackUP.emplace_back(251, 6, 15, 26);

    //attac right distance
    this->distanceAttackRIGHT.emplace_back(11,8,17,24);
    this->distanceAttackRIGHT.emplace_back(51,8,17,24);
    this->distanceAttackRIGHT.emplace_back(88,8,20,24);
    this->distanceAttackRIGHT.emplace_back(129,8,20,24);
    this->distanceAttackRIGHT.emplace_back(176,9,25,23);
    this->distanceAttackRIGHT.emplace_back(216,11,26,23);
    this->distanceAttackRIGHT.emplace_back(256,10,16,22);
    //breath
    this->breath.emplace_back(10,9,18,23);
    this->breath.emplace_back(50,9,18,23);
    this->breath.emplace_back(90,9,18,23);
    this->breath.emplace_back(130,8,18,24);

    //death
    this->death_left.emplace_back(13,8,18,24);
    this->death_left.emplace_back(52,8,17,24);
    this->death_left.emplace_back(92,8,18, 24);
    this->death_left.emplace_back(132,8,18, 24);
    this->death_left.emplace_back(171,8,17, 24);
    this->death_left.emplace_back(209,8,18, 24);
    this->death_left.emplace_back(242,8,24, 24);
    this->death_left.emplace_back(281,8,26, 24);
    this->death_left.emplace_back(321,8,26, 24);

    this->death_right.emplace_back(10,8,18,24);
    this->death_right.emplace_back(51,8,18,24);
    this->death_right.emplace_back(91,8,18, 24);
    this->death_right.emplace_back(131,8,18, 24);
    this->death_right.emplace_back(172,8,17, 24);
    this->death_right.emplace_back(214,8,18, 24);
    this->death_right.emplace_back(255,8,24, 24);
    this->death_right.emplace_back(294,8,26, 24);
    this->death_right.emplace_back(334,8,26, 24);
   
    this->death_up.emplace_back(13,8,15,24);
    this->death_up.emplace_back(53,8,15,24);
    this->death_up.emplace_back(93,10,15,22);
    this->death_up.emplace_back(133,13,15,20);
    this->death_up.emplace_back(173,15,15,18);
    this->death_up.emplace_back(173, 15, 15, 18);
    this->death_up.emplace_back(173, 15, 15, 18);
    this->death_up.emplace_back(173, 15, 15, 18);
    this->death_up.emplace_back(173, 15, 15, 18);

    this->death_down.emplace_back(10, 8, 18, 24);
    this->death_down.emplace_back(50, 8, 18, 24);
    this->death_down.emplace_back(90,8,18,24);
    this->death_down.emplace_back(130,8,18,24);
    this->death_down.emplace_back(170,8,18,24);
    this->death_down.emplace_back(210,8,18,24);
    this->death_down.emplace_back(252,8,15,31);
    this->death_down.emplace_back(293,8,15,31);
    this->death_down.emplace_back(333,8,15,31);

}

bool Player::herodeath()
{
    if (this->hp <= 0)
    {
        return true;
        i = 0;
    }
    else return false;
}

void Player::update()
{
    this->acctualBounds();

    //hp bar changes
    
    this->hpDisplay = (this->hp / this->maxHP) * 92;
    float hpDisplayAlpha = (1.0f - (this->hp / this->maxHP)) * 255;
    blood.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(hpDisplayAlpha)));
    if (hpDisplay >= 0)
    {
        this->HP.setTextureRect(sf::IntRect(0, 0, hpDisplay, 18));
    }
    //stamina bar changes
    this->staminaDisplay = (this->stamina / this->maxStamina) * 92;
    this->STAMINA.setTextureRect(sf::IntRect(0, 0, staminaDisplay, 18));

    
    //stamina recovery
    if (staminaClock.getElapsedTime().asSeconds() > 0.1)
    {
        //std::cout << stamina << std::endl;
        adjustStamina(0.5);
        if (stamina >= this->maxStamina) { this->stamina = this->maxStamina; }
        if (stamina <= 0) { this->stamina = 0; }
        staminaClock.restart();
    }
    

    //weapon info change
    if (scroll)
    {
        this->sword.setTexture(fire_sword_texture);
        this->text.setFillColor(sf::Color(255, 33, 33));
        this->text.setString("FIRE BALL SWORD");
    }
    else
    {
        
        this->sword.setTexture(sword_texture);
        this->text.setFillColor(sf::Color(226,226,226));
        this->text.setString("IRON SWORD");
        this->hitboxSet(2);
        
    }

    //smooth move
    if (blockRight)
    {
        movingRight = false;
    }
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
            //std::cout << i << std::endl;
            
            this->hero.setTexture(walk_left_texture);   
            if (this->i >= 6) { this->i = 0; }
            this->hero.setTextureRect(walkLeft[i]);
            i++;
            clock.restart();
        }
        if (movingRight && clock.getElapsedTime().asSeconds() > 0.2)
        {
            //std::cout << i << std::endl;
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

void Player::adjustStamina(float amount)
{
    this->stamina += amount;
}

void Player::animateAttackMele()
    {
    if (!scroll&&stamina>=10)
    {
        
        

        //stamina adjust
        if(!attack)
        adjustStamina(-10);

        //attack left
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (hero.getTexture() == &walk_left_texture) || (hero.getTexture() == &attack_mele_left_texture))
        {
            std::cout << "ustawiam texture na atak w lewo" << std::endl;
            this->hero.setTexture(attack_mele_left_texture);
            this->attack = true;
            this->hitboxSet(1);
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
}

void Player::animateAttackDistance()
    {
    if (scroll&&stamina >= 20)
    {
        //stamina adjust
        if(!attack)
        adjustStamina(-20);

        //attack left
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (hero.getTexture() == &walk_left_texture) || (hero.getTexture() == &attack_distance_left_texture))
        {
            this->hero.setTexture(attack_distance_left_texture);
            this->attack = true;
        }
        //attack right
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (hero.getTexture() == &walk_right_texture) || (hero.getTexture() == &attack_distance_right_texture))
        {
            this->hero.setTexture(attack_distance_right_texture);
            this->attack = true;
        }
        //attack down-left-rigt
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (hero.getTexture() == &walk_down_texture) || (hero.getTexture() == &attack_distance_down_texture))
        {
            this->hero.setTexture(attack_distance_down_texture);
            this->attack = true;
        }
        //attack up-left-rigt
        if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (hero.getTexture() == &walk_up_texture) || (hero.getTexture() == &attack_distance_up_texture))
        {
            this->hero.setTexture(attack_distance_up_texture);
            this->attack = true;
        }
    }
}

void Player::animateDeath()
{
    if (!isdead)
    {
            if (i == 8) { isdead = true; }
        if (clock.getElapsedTime().asSeconds() > 0.3 && ((hero.getTexture() == &walk_left_texture) ||
            (hero.getTexture() == &attack_mele_left_texture) || (hero.getTexture() == &attack_distance_left_texture) ||
            (hero.getTexture() == &death_texture_left)))
        {
            this->hero.setTexture(death_texture_left);
            this->hero.setTextureRect(death_left[i]);
            i++;
            clock.restart();
        }
        if (clock.getElapsedTime().asSeconds() > 0.3 && ((hero.getTexture() == &walk_right_texture)
            || (hero.getTexture() == &attack_mele_right_texture) ||
            (hero.getTexture() == &attack_distance_right_texture)
            || (hero.getTexture() == &death_texture_right)))
        {
            this->hero.setTexture(death_texture_right);
           
            this->hero.setTextureRect(death_right[i]);
            i++;
            clock.restart();
        }
        if (clock.getElapsedTime().asSeconds() > 0.3 && ((hero.getTexture() == &walk_down_texture) ||
            (hero.getTexture() == &attack_mele_down_texture) || (hero.getTexture() == &attack_distance_down_texture) ||
            (hero.getTexture() == &death_texture_down)))
        {
            this->hero.setTexture(death_texture_down);
           
            this->hero.setTextureRect(death_down[i]);
            i++;
            clock.restart();
        }
        if (clock.getElapsedTime().asSeconds() > 0.3 && ((hero.getTexture() == &walk_up_texture) ||
            (hero.getTexture() == &attack_mele_up_texture) || (hero.getTexture() == &attack_distance_up_texture) ||
            (hero.getTexture() == &death_texture_up)))
        {
            this->hero.setTexture(death_texture_up);
        
            this->hero.setTextureRect(death_up[i]);
            i++;
            clock.restart();
        }
    }
}

void Player::acctualBounds()
{
    this->heroDown = this->hero.getGlobalBounds().top + this->hero.getGlobalBounds().height;
    this->heroTop = this->hero.getGlobalBounds().top;
    this->heroRight = this->hero.getGlobalBounds().left + this->hero.getGlobalBounds().width;
    this->heroLeft = this->hero.getGlobalBounds().left;
}

void Player::hitboxSet(int side)
{

    swordHitBox.setFillColor(sf::Color::Transparent);
    if (this->hero.getTexture() == &this->attack_mele_left_texture)
    {
        swordHitBox.setSize(sf::Vector2f(16, 40));
        swordHitBox.setPosition(this->heroLeft - 8, this->heroTop- 6);
    }
    else if (this->hero.getTexture() == &this->attack_mele_right_texture)
    {
        swordHitBox.setSize(sf::Vector2f(16, 40));
        swordHitBox.setPosition(this->heroRight + 8, this->heroTop - 6);
    }
    else if (this->hero.getTexture() == &this->attack_mele_down_texture)
    {
        swordHitBox.setSize(sf::Vector2f(40, 16));
        swordHitBox.setPosition(this->heroLeft, this->heroDown + 5);
    }
    else if (this->hero.getTexture() == &this->attack_mele_up_texture)
    {
        swordHitBox.setSize(sf::Vector2f(40, 16));
        swordHitBox.setPosition(this->heroLeft, this->heroTop - 5);
    }
    else { resetHitbox(); }
}

void Player::swordDamage(Characters& target)
{
    if (this->swordHitBox.getGlobalBounds().intersects(target.getSprite().getGlobalBounds()))
    {
        if (delay.getElapsedTime().asSeconds() > 0.5)
        {
            target.adjustHp(-1*this->damage);
            delay.restart();
            std::cout << target.getHP() << std::endl;
        }
    }
}

void Player::fireballDamage(Characters& target)
{
    if (fireball_fly)
    {
        if (this->fireball->getSprite().getGlobalBounds().intersects(target.getSprite().getGlobalBounds()))
        {
            fireballHit = true;
            std::cout << "uderzam" << std::endl;
            target.adjustHp(-1*this->rangeDamage);
        }
    }
}

void Player::resetHitbox()
{
    swordHitBox.setPosition(-1000, -1000);
}

void Player::newlevel()
{
    adjustHp(maxHP * 0.5);
    if (this->hp > this->maxHP) { this->hp = this->maxHP; }
    adjustStamina(maxStamina);
    hero.setPosition(315, 500);
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

sf::FloatRect Player::herobounds()
    {
        return sf::FloatRect(this->hero.getGlobalBounds().left,
            this->hero.getGlobalBounds().top,
            this->hero.getGlobalBounds().width,
            this->hero.getGlobalBounds().height);
    }

void Player::animationattack(sf::Vector2f mouse_position)
    {
        //setting texture rect
        if (attack&&!scroll)
        {
            if (clock.getElapsedTime().asSeconds() > 0.07)
            {
                if (this->j > 6) { this->j = 0; attack = false; }
                if (hero.getTexture() == &attack_mele_right_texture)
                {
                    this->hero.setTextureRect(meleAttackRIGHT[this->j]);
                }

                if (hero.getTexture() == &attack_mele_left_texture)
                {
                    this->hero.setTextureRect(meleAttackLEFT[this->j]);
                }

                if (hero.getTexture() == &attack_mele_up_texture)
                {
                    this->hero.setTextureRect(meleAttackUP[this->j]);
                }

                if (hero.getTexture() == &attack_mele_down_texture)
                {
                    this->hero.setTextureRect(meleAttackDOWN[this->j]);
                }
                this->j++;
                clock.restart();
            }
        }
        else if (attack && scroll)
        {
            if (clock.getElapsedTime().asSeconds() > 0.07)
            {
                if (this->j > 6) { this->j = 0; attack = false; }
                if (hero.getTexture() == &attack_distance_right_texture)
                {
                    this->hero.setTextureRect(distanceAttackRIGHT[this->j]);
                }

                if (hero.getTexture() == &attack_distance_left_texture)
                {
                    this->hero.setTextureRect(distanceAttackLEFT[this->j]);
                }

                if (hero.getTexture() == &attack_distance_up_texture)
                {
                    this->hero.setTextureRect(distanceAttackUP[this->j]);
                }

                if (hero.getTexture() == &attack_distance_down_texture)
                {
                    this->hero.setTextureRect(distanceAttackDOWN[this->j]);
                }
                this->j++;
                clock.restart();
                if (j == 4)
                {
                   
                    this->fireball = new Fireball(sf::FloatRect(hero.getGlobalBounds().left,
                        hero.getGlobalBounds().top,
                        hero.getGlobalBounds().width,
                        hero.getGlobalBounds().height), mouse_position);
                        fireball_fly = true;
                }
            }
        }
}

void Player::render(sf::RenderTarget& target)
{
    if (fireball_fly)
    {
        target.draw(fireball->render());
    }
    target.draw(this->hero);
    target.draw(this->HP);
    target.draw(this->STAMINA);
    target.draw(this->swordHitBox);
    target.draw(this->blood);
}

void Player::getBounds(std::vector<sf::FloatRect> &enemy_bounds,std::vector<sf::FloatRect> &wall_bounds)
{
        if (fireball_fly)
        {
            fireball->movef();
            fireball->animate();
            if (fireball->collision(enemy_bounds,wall_bounds)&&fireballHit)
            {

               delete this->fireball;
               std::cout << "usuwam" << std::endl;
               fireball_fly = false;
               fireballHit = false;

            }
        }
}

void Player::weponChange()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
    {
        scroll = false;
        resetHitbox();
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
    {
        scroll = true;
        resetHitbox();
    }
}

bool Player::getFireball()
{
    return fireball_fly;
}



sf::Sprite Player::getSprite()
    {
        return this->hero;
    }

void Player::rendertext(sf::RenderTarget& target)
{
    target.draw(this->text);
    target.draw(this->sword);

}

void Player::scrollChange()
{ 
    resetHitbox();
   if (scroll) { scroll = false; }
   else { scroll = true; }
   std::cout << "zmiana broni" << std::endl;   
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
        //std::cout << rect_collision.size() << std::endl;
        if (!rect_collision.empty())
        {
            heroDown = hero.getGlobalBounds().top + hero.getGlobalBounds().height;
            heroTop = hero.getGlobalBounds().top;
            heroLeft = hero.getGlobalBounds().left;
            heroRight = hero.getGlobalBounds().left + hero.getGlobalBounds().width;
            // std::cout << " --left--" << heroLeft << "--top--" << heroTop << "--right--" << heroRight << "--down--" << heroDown << std::endl;
            for (auto& obj : rect_collision)
            {        
                    float colliderBottomEdge = obj.top + obj.height;
                    float colliderRightEdge = obj.left + obj.width;
                    float colliderLeftEdge = obj.left;
                    float colliderTopEdge = obj.top;
                   
                    if (heroTop < colliderTopEdge
                        && heroDown < colliderBottomEdge
                        && heroLeft < colliderRightEdge
                        && heroRight > colliderLeftEdge)
                    {
                        blockDown = true;
                        hero.setPosition(heroLeft, colliderTopEdge - hero.getGlobalBounds().height);
                    }

                    //Top Collision
                    if (heroTop > colliderTopEdge
                        && heroDown > colliderBottomEdge
                        && heroLeft < colliderRightEdge
                        && heroRight > colliderLeftEdge)
                    {
                        blockUp = true;
                        hero.setPosition(heroLeft, colliderBottomEdge);
                    }
                    
                    //Right Collision
                    if (heroLeft < colliderLeftEdge
                        && heroRight < colliderRightEdge
                        && heroTop < colliderBottomEdge
                        && heroDown > colliderTopEdge)
                    {
                        blockRight = true;
                        hero.setPosition(colliderLeftEdge - hero.getGlobalBounds().width, hero.getPosition().y);
                    }

                    //Left Collision
                    if (heroLeft > colliderLeftEdge
                        && heroRight > colliderRightEdge
                        && colliderTopEdge < colliderBottomEdge
                        && heroDown > colliderTopEdge)
                    {
                        blockLeft = true;
                        hero.setPosition(colliderRightEdge, heroTop);
                    }
            }
        }
      
    }

