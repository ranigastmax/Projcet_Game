#include "Skeleton.h"

Skeleton::Skeleton()
{

	/*this->loadTexture("textures/Skeleton_Walk_Up.png", walk_up_texture);
	this->loadTexture("textures/Skeleton_Walk_Down.png", walk_down_texture);
	this->loadTexture("textures/Skeleton_Walk_Right.png", walk_right_texture);
	this->loadTexture("textures/Skeleton_Walk_Left.png", walk_left_texture);
	this->loadTexture("textures/", death_texture);
	this->loadTexture("textures/Skeleton_Attack_up", attack_mele_up_texture);
	this->loadTexture("textures/Skeleton_Attack_Down.png", attack_mele_down_texture);
	this->loadTexture("textures/Skeleton_Attack_Right.png", attack_mele_right_texture);
	this->loadTexture("textures/Skeleton_Attack_Left.png", attack_mele_left_texture);*/
	//this->hero.setTexture(walk_down_texture);
    this->loadTexture("textures/zombie_walk.png", this->texture);
    this->hero.setTexture(texture);
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
    this->meleAttackLEFT.emplace_back(0,5,21,38);
    this->meleAttackLEFT.emplace_back(61,7,48,43);
    this->meleAttackLEFT.emplace_back(110,0,55,50);
    this->meleAttackLEFT.emplace_back(174,2,50,41);
   



    //atac right mele
    this->meleAttackRIGHT.emplace_back(0, 5, 22, 44);
    this->meleAttackRIGHT.emplace_back(40,7,51,45);
    this->meleAttackRIGHT.emplace_back(110,0,55,51);
    this->meleAttackRIGHT.emplace_back(181,2,50,41);
  


    //attack down mele
    this->meleAttackDOWN.emplace_back(0,4,30,44);
    this->meleAttackDOWN.emplace_back(49,0,43,44);
    this->meleAttackDOWN.emplace_back(115,3,52,54);
    this->meleAttackDOWN.emplace_back(194,6,33,48);
   


    //attac up mele
    this->meleAttackUP.emplace_back(0,8,32,40);
    this->meleAttackUP.emplace_back(67,9,50,48);
    this->meleAttackUP.emplace_back(119,0,56,48);
    this->meleAttackUP.emplace_back(188,1,34,46);

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
        hero.move(direction.x * spriteSpeed, direction.y * spriteSpeed);
    }
}

void Skeleton::animateWalk()
{
    std::cout << direction.x <<"x" << std::endl;
    std::cout << direction.y <<"y" << std::endl;



    if (clock.getElapsedTime().asSeconds() > 0.2 && !blockmove)
    {
        if (this->i > 9) { this->i = 0; }
        std::cout << i << std::endl;
        if (this->direction.x > this->direction.y) { this->hero.setTextureRect(walkRight[this->i]); }
        if(this->direction.x< this->direction.y) { this->hero.setTextureRect(walkDown[this->i]); }
        if (this->direction.x < 0) { this->hero.setTextureRect(walkLeft[this->i]); }
        if (this->direction.y < 0) { this->hero.setTextureRect(walkUp[this->i]); }

        this->i++;

        clock.restart();
    }



   /* if (this->direction.y > 0) { this->hero.setTexture(walk_down_texture); }  
    if (this->direction.x > 0) { this->hero.setTexture(walk_right_texture); }
    if (this->direction.y < 0) { this->hero.setTexture(walk_up_texture); }
    if (this->direction.x < 0) { this->hero.setTexture(walk_left_texture); }



    if (clock.getElapsedTime().asSeconds() > 0.3&& !blockmove)
    {
        if (this->i > 3) { this->i = 0; }
        if(this->hero.getTexture() == &walk_right_texture) { this->hero.setTextureRect(walkRight[this->i]); }
        if (this->hero.getTexture() == &walk_left_texture) { this->hero.setTextureRect(walkLeft[this->i]); }
        if(this->hero.getTexture() == &walk_down_texture) { this->hero.setTextureRect(walkDown[this->i]); }
        if(this->hero.getTexture() == &walk_up_texture) { this->hero.setTextureRect(walkUp[this->i]); }
        this->i++;

        clock.restart();
    }*/

}

void Skeleton::animateAttackMele()
{
    //if (blockmove&& clock.getElapsedTime().asSeconds() > 0.3)
    //{
    //    //attack left
    //    if ((hero.getTexture() == &walk_left_texture) || (hero.getTexture() == &attack_mele_left_texture))
    //    {
    //        this->hero.setTexture(attack_mele_left_texture);
    //        if (this->j > 3) { this->j = 0; }
    //        this->hero.setTextureRect(meleAttackLEFT[this->j]);
    //        this->j++;
    //    }
    //    //attack right
    //    if ((hero.getTexture() == &walk_right_texture) || (hero.getTexture() == &attack_mele_right_texture))
    //    {
    //        this->hero.setTexture(attack_mele_right_texture);
    //        if (this->j > 3) { this->j = 0; }
    //        this->hero.setTextureRect(meleAttackRIGHT[this->j]);
    //        this->j++;
    //    }
    //    //attack down-left-rigt
    //    if ((hero.getTexture() == &walk_down_texture) || (hero.getTexture() == &attack_mele_down_texture))
    //    {
    //        this->hero.setTexture(attack_mele_down_texture);
    //        if (this->j > 3) { this->j = 0; }
    //        this->hero.setTextureRect(meleAttackDOWN[this->j]);
    //        this->j++;
    //    }
    //    
    //     //attack up-left-rigt
    //    if ((hero.getTexture() == &walk_up_texture) || (hero.getTexture() == &attack_mele_up_texture))
    //    {
    //        std::cout << "gora" << std::endl;
    //        this->hero.setTexture(attack_mele_up_texture);
    //        if (this->j > 3) { this->j = 0; }
    //        this->hero.setTextureRect(meleAttackUP[this->j]);
    //        this->j++;
    //    }
    //    clock.restart();
    //}
}

void Skeleton::animateAttackDistance()
{

}

void Skeleton::animateDeath()
{

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


