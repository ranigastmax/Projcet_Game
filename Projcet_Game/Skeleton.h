#pragma once
#include"Characters.h"
class Skeleton : public Characters
{
public:
	Skeleton();
	void initIntRect();
	void initcharacters();
	void enemymove();
	void animateWalk();
	void animateAttackMele();
	void animateAttackDistance();
	void animateDeath();
};

