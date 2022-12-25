#include "player.hpp"

Player::Player() : Object(player)
{
    // Связываем текстуру и спрайт
    this->obj_texture.loadFromFile(
            "resources/images/player/player.png",
            sf::IntRect(0, 0, 1057, 1161));
    sf::Sprite sp;
    sp.setTexture(obj_texture);
    sp.setScale(0.05f, 0.05f);
    this->obj_sprite = sp;
    // Устанавливаем начальную позицию в пикселях
    VecX = 0;
    this->setVector(sf::Vector2f(200, 700));
}

Player::~Player()
{
}

void Player::update()
{
    if (this->getVector().x > (window_size_x - 100))
        this->setVector(sf::Vector2f(54,this->getVector().y));
    if (this->getVector().x < 53)
        this->setVector(sf::Vector2f((window_size_x - 100),this->getVector().y));
    this->obj_sprite.setPosition(this->getVector());
}

void Player::draw()
{
    this->window->draw(this->obj_sprite);
}

void Player::move()
{
    this->setVector(sf::Vector2f(
            (this->getVector().x + VecX * 0.1f), this->getVector().y));
}