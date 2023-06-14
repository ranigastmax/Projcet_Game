#include "Upgrades.h"



Upgrades::Upgrades(int top, int left, std::string pathNotClicked, std::string pathClicked, std::string pathMouseIsOver, int scalex, int scaley)
{
	buttonTextureMouseIsOver.loadFromFile(pathMouseIsOver);
	buttonTextureNotClicked.loadFromFile(pathNotClicked);
	buttonTextureClicked.loadFromFile(pathClicked);
	buttonSprite.setTexture(buttonTextureNotClicked);
	buttonSprite.setPosition(top, left);
	buttonSprite.setScale(scalex, scaley);
}

void Upgrades::HP_boost(Player& player)
{
	player.maxHP = player.maxHP + 20;
	std::cout << "hp boost" << std::endl;
	clicked = false;
}

void Upgrades::MeleAttack_boost(Player& player)
{
	player.damage = player.damage + 5;
	std::cout << "mele attack boost" << std::endl;
	clicked = false;

}

void Upgrades::Stamina_boost(Player& player)
{
	player.maxStamina = player.maxStamina + 20;
	std::cout << "stamina boost" << std::endl;
	clicked = false;

}

void Upgrades::RangeAttack_boost(Player& player)
{
	player.rangeDamage = player.rangeDamage + 5;
	std::cout << "range dmg boost" << std::endl;
	clicked = false;

}
