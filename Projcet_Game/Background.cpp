#include "Background.h"


void Background::loadTexture(std::string path, sf::Texture& textureName)
{
    if (!textureName.loadFromFile(path)) {
        std::cerr << "Could not load texture" << std::endl;
    }
    this->map.setTexture(map_texture);

}

Background::Background()
{
    this->loadTexture("textures/map.png", this->map_texture);
    this->loadTexture("textures/mapBACK.png", this->mapBACK1_texture);
    this->loadTexture("textures/mapBACK2.png", this->mapBACK2_texture);

    this->menuBack1.setTexture(mapBACK2_texture);
    this->menuBack2.setTexture(mapBACK1_texture);

    this->map.setPosition(0, 0);

    this->menuBack1.setPosition(-632, 0);
    this->menuBack2.setPosition(0, 0);
    
    left.setSize(sf::Vector2f(10, 625));
    left.setFillColor(sf::Color::Red);
    left.setPosition(19, 0);

    right.setSize(sf::Vector2f(10, 625));
    right.setFillColor(sf::Color::Red);
    right.setPosition(603, 0);

    down.setSize(sf::Vector2f(620, 10));
    down.setFillColor(sf::Color::Red);
    down.setPosition(0, 85);

    up.setSize(sf::Vector2f(620, 10));
    up.setFillColor(sf::Color::Red);
    up.setPosition(0, 598);

    this->backogroundbounds();
}

Background::~Background()
{

}

void Background::render(sf::RenderTarget& target)
{
    target.draw(this->left);
    target.draw(this->right);
    target.draw(this->up);
    target.draw(this->down);
    target.draw(this->map);
}

void Background::backgroundMove(sf::RenderTarget& target)
{
    sf::Vector2f mapPos1 = menuBack1.getPosition();
    sf::Vector2f mapPos2 = menuBack2.getPosition();
    int mapWidth1 = menuBack1.getTexture()->getSize().x;
    int mapWidth2 = menuBack2.getTexture()->getSize().x;

    this->menuBack1.move(backgroundAnimationSpeed * 0.25, 0);
    this->menuBack2.move(backgroundAnimationSpeed * 0.25, 0);
    if (mapPos1.x >= 0) menuBack1.setPosition(-mapWidth1, mapPos1.y);
    if (mapPos2.x >= mapWidth2) menuBack1.setPosition(0, mapPos2.y);
    target.draw(this->menuBack1);
    target.draw(this->menuBack2);
}

void Background::backogroundbounds()
{
    this->wallbounds.emplace_back(left.getGlobalBounds().left, left.getGlobalBounds().top, left.getGlobalBounds().width, left.getGlobalBounds().height);
    this->wallbounds.emplace_back(right.getGlobalBounds().left, right.getGlobalBounds().top, right.getGlobalBounds().width, right.getGlobalBounds().height);
    this->wallbounds.emplace_back(up.getGlobalBounds().left, up.getGlobalBounds().top, up.getGlobalBounds().width, up.getGlobalBounds().height);
    this->wallbounds.emplace_back(down.getGlobalBounds().left, down.getGlobalBounds().top, down.getGlobalBounds().width, down.getGlobalBounds().height);
}


