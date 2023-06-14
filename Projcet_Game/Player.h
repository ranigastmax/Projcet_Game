#pragma once
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>
#include"Characters.h"
#include"Fireball.h"

class Player : public Characters
{
	//init functions
	void initcharacters();
	void initIntRect();
	int j = 0;
	
	//move 
	float targetY, targetX;
	float x, y;
	bool movingLeft;
	bool movingRight;
	bool movingUp;
	bool movingDown;
	bool  blockLeft;
	bool  blockRight;
	bool  blockUp;
	bool  blockDown;
	
	//attack 
	bool attack;
	bool scroll;
	sf::Texture sword_texture;
	sf::Texture fire_sword_texture;
	sf::Sprite sword;
	sf::RectangleShape swordHitBox;
	Fireball* fireball;
	bool fireball_fly;
	//player bounds
	int heroDown;
	int	heroTop;
	int	heroLeft;
	int	heroRight;

	//hp and stamina 
	sf::Clock staminaClock;
	float hpDisplay;
	float staminaDisplay;
	float stamina;
	float staminaRecovery = 1;
	sf::Texture stamina_texture;
	sf::Sprite STAMINA;
	
	//other
	sf::Font font;
	sf::Text text;
	sf::Sprite blood;
	sf::Texture blood_teture;
	bool isdead;
public:

	float damage = 11;
	float rangeDamage = 9;
	float maxStamina = 100;
	float maxHP = 50;
	//constructors-------------------------------------
	Player();
	~Player();
	//end-constructors---------------------------------

	bool walking;
	bool fireballHit = false;

	//public functions----------------------------------
	bool herodeath();
	bool getFireball();
	void move();
	void animateWalk();
	void animateAttackMele();
	void animateAttackDistance();
	void animateDeath();
	void update();
	void releasedAD();
	void releasedWS();
	sf::FloatRect herobounds();
	sf::Sprite getSprite();
	void rendertext(sf::RenderTarget& target);
	void scrollChange();
	void bounds(std::vector<sf::FloatRect>);
	void animationattack(sf::Vector2f mouse_position);
	void render(sf::RenderTarget& target);
	void getBounds(std::vector<sf::FloatRect> &enemy_bounds, std::vector<sf::FloatRect> &wall_bounds);
	void acctualBounds();
	void weponChange();
	void adjustStamina(float);
	void hitboxSet(int);
	void resetHitbox();
	void swordDamage(Characters& targer);
	void fireballDamage(Characters& targer);
	void newlevel();
};

