#include "Object.hpp"

Object::Object(sf::Uint64 state)
{
    this->life = false;
    obj_state = state;
}
Object::Object(sf::Vector2f Vector)
{
    this->life = true;
    setVector(Vector);
}
Object::~Object()
{
}
//
bool Object::stat_life()
{
    return this->life;
}

void Object::setlife(bool l)
{
    this->life = l;
}

void Object::setVecX(float Vec)
{
    this->VecX = Vec;
}

float Object::getVecX()
{
    return this->VecX;
}

void Object::setWindow(sf::RenderWindow* game_window)
{
    this->window = game_window;
}

sf::Sprite Object::getSprite()
{
    return this->obj_sprite;
}

void Object::setSprite(sf::Sprite sprite)
{
    this->obj_sprite = sprite;
}

sf::Vector2f Object::getVector()
{
    return this->obj_position;
}

void Object::setVector(sf::Vector2f Vector)
{
    this->obj_position = Vector;
}