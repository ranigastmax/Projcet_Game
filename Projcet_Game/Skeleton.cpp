#include "Skeleton.h"

Skeleton::Skeleton()
{

	this->loadTexture("textures/Skeleton_Walk_Up.png", walk_up_texture);
	this->loadTexture("textures/Skeleton_Walk_Down.png", walk_down_texture);
	this->loadTexture("textures/Skeleton_Walk_Right.png", walk_right_texture);
	this->loadTexture("textures/Skeleton_Walk_Left.png", walk_left_texture);
	this->loadTexture("textures/", death_texture);
	this->loadTexture("textures/Skeleton_Attack_Up", attack_mele_up_texture);
	this->loadTexture("textures/Skeleton_Attack_Down.png", attack_mele_down_texture);
	this->loadTexture("textures/Skeleton_Attack_Right.png", attack_mele_right_texture);
	this->loadTexture("textures/Skeleton_Attack_Left.png", attack_mele_left_texture);
	this->hero.setTexture(walk_down_texture);


}

void Skeleton::initIntRect()
{
    //walk left
    this->walkLeft.emplace_back(0, 0, 21, 38);
    this->walkLeft.emplace_back(61, 1, 33, 37);
    this->walkLeft.emplace_back(128,0, 21, 38);
    this->walkLeft.emplace_back(181, 1, 34, 39);
 
    //walk right
    this->walkRight.emplace_back(0,0,21,38);
    this->walkRight.emplace_back(51,1,33,37);
    this->walkRight.emplace_back(128,0,21,38);
    this->walkRight.emplace_back(185,1,32,38);
 
    //walk up
    this->walkDown.emplace_back(0,0,29,38);
    this->walkDown.emplace_back(64,1,26,40);
    this->walkDown.emplace_back(128,0,29,38);
    this->walkDown.emplace_back(195,1,29,41);


    //walk down

    this->walkUp.emplace_back(0,0,32,38);
    this->walkUp.emplace_back(61,1,29,40);
    this->walkUp.emplace_back(128,0,32,38);
    this->walkUp.emplace_back(194,1,29,40);

    //attac left mele
    this->meleAttackLEFT.emplace_back(0,5,21,38);
    this->meleAttackLEFT.emplace_back(61,7,48,43);
    this->meleAttackLEFT.emplace_back(110,0,55,50);
    this->meleAttackLEFT.emplace_back(174,2,50,41);
   



    //atac right mele
    this->meleAttackRIGHT.emplace_back(0, 5, 21, 38);
    this->meleAttackRIGHT.emplace_back(40,7,48,44);
    this->meleAttackRIGHT.emplace_back(110,0,55,51);
    this->meleAttackRIGHT.emplace_back(181,2,50,41);
  


    //attack down mele
    this->meleAttackDOWN.emplace_back(0,4,29,38);
    this->meleAttackDOWN.emplace_back(49,0,43,44);
    this->meleAttackDOWN.emplace_back(115,3,52,54);
    this->meleAttackDOWN.emplace_back(194,6,33,48);
   


    //attac up mele
    this->meleAttackUP.emplace_back(0,9,32,38);
    this->meleAttackUP.emplace_back(67,9,40,48);
    this->meleAttackUP.emplace_back(119,0,52,48);
    this->meleAttackUP.emplace_back(188,1,34,46);

}

void Skeleton::initcharacters()
{
}

void Skeleton::enemymove()
{
}

void Skeleton::animateWalk()
{

}

void Skeleton::animateAttackMele()
{

}

void Skeleton::animateAttackDistance()
{

}

void Skeleton::animateDeath()
{

}
