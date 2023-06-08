#include "Boss.h"

Boss::Boss()
{
	this->loadTexture("textures/Boss.png", walk_right_texture);
	hero.setPosition(150, 150);
	hero.setTexture(walk_right_texture);
	hero.setTextureRect(sf::IntRect(25, 624, 48, 46));
	maxHP = 200;
}

void Boss::position(sf::FloatRect player)
{
	if (i==11)
	{
		clock.restart();
		int NewX = std::rand() % 581 + 20;
		int NewY = std::rand() % 675 + 85;
		hero.setPosition(NewX, NewY);
		
		animationUp = false;
	}
}

void Boss::rangeattack()
{
	if (!animationUp)
	{
		if (clock.getElapsedTime().asSeconds() > 0.1)
		{
			this->hero.setTextureRect(distanceAttackRIGHT[i]);
			i--;
			if (i == 0) { animationUp = true; }
		}
	}
	else
	{

		if (clock.getElapsedTime().asSeconds() > 0.1)
		{
			this->hero.setTextureRect(distanceAttackRIGHT[i]);
			i++;
			if (i == 11) { animationUp = false; }
		}
	}
}

void Boss::initIntRect()
{
	distanceAttackRIGHT.emplace_back(25,224,48,46);
	distanceAttackRIGHT.emplace_back(125,224,51,46);
	distanceAttackRIGHT.emplace_back(225,224,57,46);
	distanceAttackRIGHT.emplace_back(325,224,66,46);
	distanceAttackRIGHT.emplace_back(425,224,66,46);
	distanceAttackRIGHT.emplace_back(525,224,68,46);
	distanceAttackRIGHT.emplace_back(625,224,68,46); //tu atakuj
	distanceAttackRIGHT.emplace_back(824,224,49,46);
	distanceAttackRIGHT.emplace_back(25,324,48,46);
	distanceAttackRIGHT.emplace_back(229,326,40,44);
	distanceAttackRIGHT.emplace_back(432,327,34,43);
	distanceAttackRIGHT.emplace_back(632,327,34,43); // tu siê teleportuj

	death_down.emplace_back(627,730,44,50);
	death_down.emplace_back(25,834,47,59);
	death_down.emplace_back(126, 834,46, 59);
	death_down.emplace_back(227, 834,45, 59);
	death_down.emplace_back(327, 834,45, 59);
	
}

void Boss::initcharacters()
{

}



