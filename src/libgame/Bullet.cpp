#include "Bullet.hpp"

Bullet::Bullet() : Object(bullet_l)
{
    this->bullet.setSize(sf::Vector2f(3, 15));
    this->bullet.setFillColor(sf::Color::White);
    this->setVecX(-1);
}

Bullet::Bullet(float VecY) : Object(bullet_l)
{
    this->bullet.setSize(sf::Vector2f(3, 15));
    this->bullet.setFillColor(sf::Color::White);
    this->setVecX(VecY);
}

Bullet::~Bullet()
{
}

bool Bullet::object_interaction(Object* obj)
{
    switch (obj->obj_state) {
    case player: {
        if (((obj->getVector().x + 53) >= this->bullet.getPosition().x)
            && ((obj->getVector().x) <= this->bullet.getPosition().x)
            && ((obj->getVector().y + 57) >= this->bullet.getPosition().y)
            && ((obj->getVector().y) <= this->bullet.getPosition().y)) {
            return true;
        }
        break;
    }
    case enemy: {
        if (((obj->getVector().x + 64) >= this->bullet.getPosition().x)
            && ((obj->getVector().x) <= this->bullet.getPosition().x)
            && ((obj->getVector().y + 46.6f) >= this->bullet.getPosition().y)
            && ((obj->getVector().y) <= this->bullet.getPosition().y)) {
            return true;
        }
        break;
    }
    default:
        break;
    }
    return false;
}

void Bullet::draw()
{
    if (this->life == true)
        this->window->draw(this->bullet);
}

void Bullet::update()
{
    if (this->life == true)
        this->bullet.setPosition(this->getVector());
    if (this->getVector().y < 0) {
        this->life = false;
    }
    if (this->getVector().y > window_size_y) {
        this->life = false;
    }
}

void Bullet::move()
{
    if (this->life == true)
        this->setVector(sf::Vector2f(
                this->getVector().x, (this->getVector().y + this->getVecX())));
}