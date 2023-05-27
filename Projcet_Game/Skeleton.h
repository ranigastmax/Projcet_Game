#pragma once
#include"Characters.h"
#include <cstdlib>
#include <ctime>
class Skeleton : public Characters
{
public:
	Skeleton();
	void initIntRect();
	void initcharacters();
	void enemymove(sf::Sprite target);
	void animateWalk();
	void animateAttackMele();
	void animateAttackDistance();
	void animateDeath();
	void render(sf::RenderTarget& target);
	void boundsSkeleton(sf::FloatRect);
private:
	int i = 0;
	int j = 0;
	float hp;
	sf::Vector2f direction;
	bool blockmove;
};

