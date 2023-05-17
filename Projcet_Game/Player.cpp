#include "Player.h"



void Player::initPlayer()
{

}

void Player::loadTexture(std::string path, sf::Texture& textureName)
{
    if (!textureName.loadFromFile(path)) {
        std::cerr << "Could not load texture" << std::endl;
    }
}

Player::Player()
{
    //load all textures from files
    this->loadTexture("textures/idle_down_40x40.png", breath_texture);
    this->loadTexture("textures/run_up_40x40.png", walk_up_texture);
    this->loadTexture("textures/run_down_40x40.png", walk_down_texture);
    this->loadTexture("textures/run_right_40x40.png", walk_right_texture);
    this->loadTexture("textures/run_left_40x40.png", walk_left_texture);
    this->loadTexture("textures/attack_up_40x40.png", attack_mele_up_texture);
    this->loadTexture("textures/attack_down_40x40.png", attack_mele_down_texture);
    this->loadTexture("textures/attack_right_40x40.png", attack_mele_right_texture);
    this->loadTexture("textures/attack_left_40x40.png", attack_mele_left_texture);
    this->loadTexture("textures/attack_up_40x40.png", attack_distance_up_texture);
    this->loadTexture("textures/attack_down_40x40.png", attack_distance_down_texture);
    this->loadTexture("textures/attack_right_40x40.png", attack_distance_right_texture);
    this->loadTexture("textures/attack_left_40x40.png", attack_distance_left_texture);
    this->loadTexture("textures/death_right_40x40.png", death_texture);
    //end of loadnig all textures
    





}

Player::~Player()
{



}

void Player::render(sf::RenderTarget& target)
{


}

void Player::update()
{


}

void Player::animateBreath()
{
    //breath


}

void Player::animateWalk()
{
    //walk left
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {

        this->hero.setTexture(walk_left_texture);
        std::cout << "ustawiam texture w lewo" << std::endl;
        leftFLAG = true;
        rightFLAG = false;
        downFLAG = false;
        upFLAG = false;
    }

    //walk right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        this->hero.setTexture(walk_right_texture);
        std::cout << "ustawiam texture w prawo" << std::endl;
        rightFLAG = true;
        leftFLAG = false;
        downFLAG = false;
        upFLAG = false;
    }

    //walk down-left-rigt
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        this->hero.setTexture(walk_down_texture);
        std::cout << "ustawiam texture w dol" << std::endl;

        downFLAG = true;
        leftFLAG = false;
        rightFLAG = false;
        upFLAG = false;
    }

    //walk up-left right
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        this->hero.setTexture(walk_up_texture);
        std::cout << "ustawiam texture w gore" << std::endl;

        upFLAG = true;
        downFLAG = false;
        leftFLAG = false;
        rightFLAG = false;
       
    }

}

void Player::animateAttackMele()
{
    //attack left
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left))&&(leftFLAG))
    {
        std::cout << "ustawiam texture na atak w lewo" << std::endl;
        this->hero.setTexture(attack_mele_left_texture);
    }

    //attack right
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (rightFLAG))
    {
        std::cout << "ustawiam texture na atak w prawo" << std::endl;
        this->hero.setTexture(attack_mele_right_texture);
    }

    //attack down-left-rigt
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (downFLAG))
    {
        std::cout << "ustawiam texture na atak w dol" << std::endl;
        this->hero.setTexture(attack_mele_down_texture);
    }

    //attack up-left-rigt
    if ((sf::Mouse::isButtonPressed(sf::Mouse::Left)) && (upFLAG))
    {
        std::cout << "ustawiam texture na atak w gore" << std::endl;
        this->hero.setTexture(attack_mele_up_texture);
    }

}

void Player::animateAttackDistance()
{
    //attack left
    this->hero.setTexture(attack_distance_left_texture);


    //attack right
    this->hero.setTexture(attack_distance_right_texture);


    //attack down-left-rigt
    this->hero.setTexture(attack_distance_down_texture);


    //attack up-left-rigt
    this->hero.setTexture(attack_distance_up_texture);


}

void Player::animateDeath()
{
    this->hero.setTexture(death_texture);
}

void Player::initIntRect()
{



}
