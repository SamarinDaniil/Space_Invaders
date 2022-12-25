#include "Enemy.hpp"

Enemy::Enemy() : Object()
{
    // Связываем текстуру и спрайт
    this->obj_texture.loadFromFile(
            "resources/images/enemy/enemy_1.png", sf::IntRect(0, 0, 1280, 931));
    sf::Sprite sp;
    sp.setTexture(obj_texture);
    sp.setScale(0.05f, 0.05f);
    this->obj_sprite = sp;
    // Устанавливаем начальную позицию в пикселях
    VecX = 5;
    this->setVector(sf::Vector2f(200, 100));
}

Enemy::Enemy(float x) : Object()
{
    // Связываем текстуру и спрайт
    this->obj_texture.loadFromFile(
            "resources/images/enemy/enemy_1.png", sf::IntRect(0, 0, 1057, 931));
    sf::Sprite sp;
    sp.setTexture(obj_texture);
    sp.setScale(0.05f, 0.05f);
    this->obj_sprite = sp;
    // Устанавливаем начальную позицию в пикселях
    VecX = 5;
    this->setVector(sf::Vector2f(x, 100));
}

Enemy::~Enemy()
{
}

void Enemy::update()
{
    this->obj_sprite.setPosition(this->getVector());
    if ((this->getVector().x > (window_size_x - 100))
        || (this->getVector().x < 56))
        this->setVecX(-1 * this->getVecX());
}

void Enemy::draw()
{
    this->window->draw(this->obj_sprite);
}

void Enemy::move()
{
    this->setVector(sf::Vector2f(
            (this->getVector().x + VecX * 0.1f), this->getVector().y));
}