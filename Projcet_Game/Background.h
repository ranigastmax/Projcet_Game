#pragma once
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
class Background
{

	sf::Texture map_texture;
	sf::Sprite map;
	sf::Sprite menuBack1;
	sf::Sprite menuBack2;
	float backgroundAnimationSpeed = 3;
	sf::RectangleShape left, right, down, up;
	void loadTexture(std::string path, sf::Texture& textureName);
public:
	std::vector<sf::FloatRect> wallbounds;
	Background();
	~Background();
	void render(sf::RenderTarget& target);
	void backgroundMove(sf::RenderTarget& target);
	void backogroundbounds();
};

