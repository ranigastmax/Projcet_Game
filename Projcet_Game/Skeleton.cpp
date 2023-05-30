#include "Skeleton.h"

Skeleton::Skeleton()
{
    this->loadTexture("textures/zombie_walk.png", this->walk_texture);
    this->loadTexture("textures/zombie_attack.png", this->attack_texture);
    this->hero.setTexture(walk_texture);
    this->initIntRect();
    this->hero.setTextureRect(sf::IntRect(5, 4, 30, 31));

    this->hero.setPosition((std::rand() % 542+ 30), (std::rand() % 400 + 128));
    this->hero.setScale(2, 2);


}

void Skeleton::initIntRect()
{
    //walk left
    this->walkLeft.emplace_back(9,101 ,12 ,27);
    this->walkLeft.emplace_back(41,101 ,13 ,27);
    this->walkLeft.emplace_back(72,102 ,14 ,26);
    this->walkLeft.emplace_back(104,103 ,13 ,25);
    this->walkLeft.emplace_back(136,102 , 12,26);
    this->walkLeft.emplace_back(166,101 , 13,27);
    this->walkLeft.emplace_back(197,101 , 15,27);
    this->walkLeft.emplace_back(229,102 ,16 ,26);
    this->walkLeft.emplace_back(262,103 ,14 ,25);
    this->walkLeft.emplace_back(296,102 , 12,26);

 
    //walk right
    this->walkRight.emplace_back(11,69,12,27);
    this->walkRight.emplace_back(42,69,13,27);
    this->walkRight.emplace_back(74,70,15,26);
    this->walkRight.emplace_back(107,71,13,25);
    this->walkRight.emplace_back(140,69,12,27);
    this->walkRight.emplace_back(173,69,13,27);
    this->walkRight.emplace_back(204,69,15,27);
    this->walkRight.emplace_back(235,70,16,26);
    this->walkRight.emplace_back(268,71,14,25);
    this->walkRight.emplace_back(300,70,12,26);


    //walk down
    this->walkDown.emplace_back(9, 5, 12, 27);
    this->walkDown.emplace_back(40, 5, 13, 27);
    this->walkDown.emplace_back(72, 6, 13, 26);
    this->walkDown.emplace_back(105, 7, 12, 25);
    this->walkDown.emplace_back(139, 6, 11, 26);
    this->walkDown.emplace_back(172, 5, 12, 27);
    this->walkDown.emplace_back(204, 5, 13, 27);
    this->walkDown.emplace_back(236, 6, 13, 26);
    this->walkDown.emplace_back(268, 7, 12, 25);
    this->walkDown.emplace_back(299, 6, 11, 26);


    //walk up
    this->walkUp.emplace_back(10,37,12,27);
    this->walkUp.emplace_back(42,37,13,27);
    this->walkUp.emplace_back(74,38,13,26);
    this->walkUp.emplace_back(106,39,12,25);
    this->walkUp.emplace_back(137,38,11,26);
    this->walkUp.emplace_back(167,37,12,27);
    this->walkUp.emplace_back(198,37,13,27);
    this->walkUp.emplace_back(230,38,13,26);
    this->walkUp.emplace_back(263,39,12,25);
    this->walkUp.emplace_back(297,38,11,26);



    //attac left mele
    this->meleAttackLEFT.emplace_back(5,100,16,28);
    this->meleAttackLEFT.emplace_back(37,100,16,28);
    this->meleAttackLEFT.emplace_back(69,101,16,27);
    this->meleAttackLEFT.emplace_back(101,101,16,27);
    this->meleAttackLEFT.emplace_back(133,100,16,28);
    this->meleAttackLEFT.emplace_back(164,100,17,28);
    this->meleAttackLEFT.emplace_back(198,101,15,27);
    this->meleAttackLEFT.emplace_back(227,101,18,27);



    //atac right mele
    this->meleAttackRIGHT.emplace_back(11,68,16,28);
    this->meleAttackRIGHT.emplace_back(43,68,16,28);
    this->meleAttackRIGHT.emplace_back(75,69,16,27);
    this->meleAttackRIGHT.emplace_back(107,69,16,27);
    this->meleAttackRIGHT.emplace_back(139,68,16,28);
    this->meleAttackRIGHT.emplace_back(171,68,17,28);
    this->meleAttackRIGHT.emplace_back(203,69,14,27);
    this->meleAttackRIGHT.emplace_back(235,69,18,27);

  
    //attack down mele
    this->meleAttackDOWN.emplace_back(9,4,13,28);
    this->meleAttackDOWN.emplace_back(40,4,14,28);
    this->meleAttackDOWN.emplace_back(72,5,14,27);
    this->meleAttackDOWN.emplace_back(104,5,14,27);
    this->meleAttackDOWN.emplace_back(137,4,13,28);
    this->meleAttackDOWN.emplace_back(169,4,14,28);
    this->meleAttackDOWN.emplace_back(201,5,14,27);
    this->meleAttackDOWN.emplace_back(233,5,14,27);
    
    
    //attac up mele
    this->meleAttackUP.emplace_back(9,36,13,28);
    this->meleAttackUP.emplace_back(41, 36,14,28);
    this->meleAttackUP.emplace_back(73,37,14,27);
    this->meleAttackUP.emplace_back(105,37,14,27);
    this->meleAttackUP.emplace_back(137,36,13,28);
    this->meleAttackUP.emplace_back(168,36,14,28);
    this->meleAttackUP.emplace_back(200,37,14,27);
    this->meleAttackUP.emplace_back(232,37,14,27);


}

void Skeleton::initcharacters()
{
}

void Skeleton::enemymove(sf::Sprite target)
{
    this->animateWalk();
    direction = target.getPosition() - hero.getPosition();
    float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);

    direction /= length;

    float spriteSpeed = 0.8;

    if (blockmove)
    {
        hero.move(0, 0);
    }
    else
    {
        this->hero.setTexture(walk_texture);
        hero.move(direction.x * spriteSpeed, direction.y * spriteSpeed);
    }
}

void Skeleton::animateWalk()
{
    //std::cout << direction.x <<"x" << std::endl;
    //std::cout << direction.y <<"y" << std::endl;
    if (clock.getElapsedTime().asSeconds() > 0.2 && !blockmove)
    {
        if (this->i > 9) { this->i = 0; }
        std::cout << i << std::endl;
        if (this->direction.x > this->direction.y) { this->hero.setTextureRect(walkRight[this->i]); this->moveRight = true; }
        else { this->moveRight = false; }

        if (this->direction.x < this->direction.y) { this->hero.setTextureRect(walkDown[this->i]); this->moveDown = true; }
        else { this->moveDown = false; }

        if (this->direction.x < 0) { this->hero.setTextureRect(walkLeft[this->i]); this->moveLeft = true; }
        else { this->moveLeft = false; }

        if (this->direction.y < 0) { this->hero.setTextureRect(walkUp[this->i]); this->moveUp = true;}
        else { this->moveUp = false; }

        this->i++;
        clock.restart();
    }
}

void Skeleton::animateAttackMele()
{
    if (blockmove && clock.getElapsedTime().asSeconds() > 0.15)
    {
      //  std::cout << moveRight << "right" << std::endl;
       // std::cout << moveUp << "up" << std::endl;
      //  std::cout << moveLeft << "left" << std::endl;
      //  std::cout << moveDown << "down" << std::endl;
            this->hero.setTexture(attack_texture);
        if(moveRight)
        {
            if (this->j > 7) { this->j = 0; }
            this->hero.setTextureRect(meleAttackRIGHT[this->j]);
            this->j++;
        }
        if (moveDown)
        {
            if (this->j > 7) { this->j = 0; }
            this->hero.setTextureRect(meleAttackDOWN[this->j]);
            this->j++;
        }
        if (moveUp)
        {
            if (this->j > 7) { this->j = 0; }
            this->hero.setTextureRect(meleAttackUP[this->j]);
            this->j++;
        }
        if (moveLeft)
        {
            if (this->j > 7) { this->j = 0; }
            this->hero.setTextureRect(meleAttackLEFT[this->j]);
            this->j++;
        }

        clock.restart();
    }
   
}

void Skeleton::animateAttackDistance()
{

}
void Skeleton::animateDeath()
{

}
void Skeleton::attackMele(Characters* object)
{
    if (this->hero.getGlobalBounds().intersects(object->getSprite().getGlobalBounds()))
    {
        if (this->blockmove)
        {
            this->hitboxSet();
            this->animateAttackMele();
            if (this->hitBox.getGlobalBounds().intersects(object->getSprite().getGlobalBounds()))
            {
                if(delay.getElapsedTime().asSeconds()>1)
                { 
                    object->adjustHp(-5);
                    std::cout << "hit//////////////////////////////////////////////////////////////" << std::endl;
                    delay.restart();
                }
                
            }

        }
    }

}

sf::FloatRect Skeleton::enemyFloatRect()
{
    return sf::FloatRect(hero.getGlobalBounds().left, hero.getGlobalBounds().top, hero.getGlobalBounds().width, hero.getGlobalBounds().height);
}

void Skeleton::render(sf::RenderTarget& target)
{
    target.draw(this->hero);
}
void Skeleton::boundsSkeleton(sf::FloatRect herobounds)
{
    if (this->hero.getGlobalBounds().intersects(herobounds))
    {
        float heroDown = hero.getGlobalBounds().top + hero.getGlobalBounds().height;
        float heroTop = hero.getGlobalBounds().top;
        float heroLeft = hero.getGlobalBounds().left;
        float heroRight = hero.getGlobalBounds().left + hero.getGlobalBounds().width;
        
        
        float colliderBottomEdge = herobounds.top + herobounds.height;
        float colliderRightEdge = herobounds.left + herobounds.width;
        float colliderLeftEdge = herobounds.left;
        float colliderTopEdge = herobounds.top;
            //Bottom Collision
            if (heroTop < colliderTopEdge
                && heroDown < colliderBottomEdge
                && heroLeft < colliderRightEdge
                && heroRight > colliderLeftEdge)
            {
                blockmove = true;
            
            }
            //Top Collision
            if (heroTop > colliderTopEdge
                && heroDown > colliderBottomEdge
                && heroLeft < colliderRightEdge
                && heroRight > colliderLeftEdge)
            {
                blockmove = true;
            }
            //Right Collision
            if (heroLeft < colliderLeftEdge
                && heroRight < colliderRightEdge
                && heroTop < colliderBottomEdge
                && heroDown > colliderTopEdge)
            {
                blockmove = true;
           
            }
            //Left Collision
            if (heroLeft > colliderLeftEdge
                && heroRight > colliderRightEdge
                && colliderTopEdge < colliderBottomEdge
                && heroDown > colliderTopEdge)
            {
                blockmove = true;
          
            }
    }
    else
    {
        blockmove = false;
    }


}

void Skeleton::hitboxSet()
{
    float heroDown = hero.getGlobalBounds().top + hero.getGlobalBounds().height;
    float heroTop = hero.getGlobalBounds().top;
    float heroLeft = hero.getGlobalBounds().left;
    float heroRight = hero.getGlobalBounds().left + hero.getGlobalBounds().width;
    if (moveDown) 
    { 
        this->hitBox.setSize(sf::Vector2f(24,15));
        this->hitBox.setPosition(heroLeft,heroDown); 
    }
    if (moveUp)
    {
        this->hitBox.setSize(sf::Vector2f(24, 15));
        this->hitBox.setPosition(heroLeft, heroTop-20);
    }
    if (moveRight)
    {
        this->hitBox.setSize(sf::Vector2f(15, 34));
        this->hitBox.setPosition(heroRight, heroTop);
    }
    if (moveLeft)
    {
        this->hitBox.setSize(sf::Vector2f(15, 34));
        this->hitBox.setPosition(heroLeft-20, heroTop);
    }

}


