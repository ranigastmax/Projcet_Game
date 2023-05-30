#pragma once
#include"SFML/Graphics.hpp";
#include<SFML/Window.hpp>
class Fireball
{
	sf::Texture fireball_texture;
	sf::Sprite *fireball;
	float speed = 1.f;
	sf::Vector2f direction;
	float length;
	float centerX;
	float centerY;
public:
	Fireball();
	Fireball(sf::FloatRect hero, sf::Vector2f mouse_position);
	sf::Sprite render();
	void move();
};

