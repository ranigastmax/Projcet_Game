#pragma once
#include<SFML/Window.hpp>
#include<iostream>
#include<vector>
#include<SFML/Graphics.hpp>

class Characters
{
protected:
	sf::Texture breath_texture;
	sf::Texture walk_up_texture;
	sf::Texture walk_down_texture;
	sf::Texture walk_right_texture;
	sf::Texture walk_left_texture;
	sf::Texture attack_mele_up_texture;
	sf::Texture attack_mele_down_texture;
	sf::Texture attack_mele_right_texture;
	sf::Texture attack_mele_left_texture;
	sf::Texture attack_distance_up_texture;
	sf::Texture attack_distance_down_texture;
	sf::Texture attack_distance_right_texture;
	sf::Texture attack_distance_left_texture;
	sf::Texture death_texture_left;
	sf::Texture death_texture_right;
	sf::Texture death_texture_up;
	sf::Texture death_texture_down;
	sf::Texture walk_texture;
	sf::Texture attack_texture;
	std::vector<sf::IntRect> breath;
	std::vector<sf::IntRect> walkUp;
	std::vector<sf::IntRect> walkDown;
	std::vector<sf::IntRect> walkRight;
	std::vector<sf::IntRect> walkLeft;
	std::vector<sf::IntRect> meleAttackUP;
	std::vector<sf::IntRect> meleAttackDOWN;
	std::vector<sf::IntRect> meleAttackRIGHT;
	std::vector<sf::IntRect> meleAttackLEFT;
	std::vector<sf::IntRect> distanceAttackUP;
	std::vector<sf::IntRect> distanceAttackDOWN;
	std::vector<sf::IntRect> distanceAttackRIGHT;
	std::vector<sf::IntRect> distanceAttackLEFT;
	std::vector<sf::IntRect> death_left;
	std::vector<sf::IntRect> death_right;
	std::vector<sf::IntRect> death_down;
	std::vector<sf::IntRect> death_up;

	sf::Clock clock;
	sf::Sprite hero;
	sf::Event ev;
	int i = 0;

	bool leftFLAG = false;
	bool rightFLAG = false;
	bool downFLAG = false;
	bool upFLAG = false;
	bool walkFLAG = false;
	bool breathFLAG = false;

	float hero_speedX = 0;
	float hero_speedY = 0;

	float hp;
	float maxHP;


	//virtual always need to call !!!!!!!!!!!!!!!
	virtual void initcharacters() = 0;
	virtual void initIntRect() = 0;
public:
	std::vector<sf::FloatRect> rect_collision;
	void loadTexture(std::string path, sf::Texture& textureName);
	//constructors-------------------------------------
	Characters();
	~Characters();
	//end-constructors---------------------------------
	
	//getters/setters
	sf::Sprite getSprite();
	void adjustHp(float);




	// render/update-----------------------------------
	void render(sf::RenderTarget& target);
	void update();
	//end render/update---------------------------------

		//public functions----------------------------------
	void animateBreath();
	virtual void animateWalk()=0;
	virtual void animateAttackMele()=0;
	virtual void animateAttackDistance()=0;
	virtual void animateDeath()=0;
	

	
};

