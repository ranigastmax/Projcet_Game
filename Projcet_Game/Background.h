#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
class Background
{
	sf::Texture map_texture;
	sf::Sprite map;
	float backgroundAnimationSpeed = 1;

	void loadTexture(std::string path, sf::Texture& textureName);
public:
	Background();
	~Background();
	void render(sf::RenderTarget& target);
	void backgroundMove(sf::RenderTarget& target);
};

