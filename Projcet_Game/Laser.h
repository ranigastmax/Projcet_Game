#pragma once
#include"SFML/Graphics.hpp";
class Laser
{
sf::Texture laser_texture;
	sf::Sprite *laser;
	float speed = 2.f;
	sf::Vector2f direction;
	float length;
	float centerX;
	float centerY;
	bool move;
	sf::Clock clock;
	std::vector<sf::IntRect> frames;
	int i = 0;
public:
	
	Laser(sf::FloatRect hero, sf::Vector2f target);
	sf::Sprite render();
	void movef();
	void animate();
	void render(sf::RenderWindow&);
	bool collisionPlayer(sf::FloatRect &target);
	bool collisionWalls(std::vector<sf::FloatRect>& walls);
	sf::Sprite getSprite();

	
};
