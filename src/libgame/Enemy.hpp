#ifndef ENEMY_H
#define ENEMY_H

#include "Object.hpp"
#include <SFML/Graphics.hpp>

class Enemy : public Object {
public:
    Enemy();
    Enemy(float x);
    ~Enemy();

    void draw() override;
    void update() override;
    void move() override;
};

#endif