#pragma once
#include"SFML/Graphics.hpp";
#include<SFML/Window.hpp>
class Fireball
{
	sf::Texture fireball_texture;
	sf::Sprite *fireball;
	float speed = 3.f;
	sf::Vector2f direction;
	float length;
	float centerX;
	float centerY;
	bool move;
	sf::Clock clock;
	std::vector<sf::IntRect> frames;
	int i = 0;
public:
	Fireball();
	Fireball(sf::FloatRect hero, sf::Vector2f mouse_position);
	sf::Sprite render();
	void movef();
	void animate();
	bool collision(std::vector<sf::FloatRect> &enemies,std::vector<sf::FloatRect> &walls);
	sf::Sprite getSprite();
};

