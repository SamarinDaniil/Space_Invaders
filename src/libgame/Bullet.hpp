#ifndef BULLET_H
#define BULLET_H

#include "Object.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class Bullet : public Object {
private:
    sf::RectangleShape bullet;

public:
    Bullet();
    Bullet(float VecY);
    ~Bullet();

    bool object_interaction(Object* obj);

    void draw() override;
    void update() override;
    void move() override;
};

#endif