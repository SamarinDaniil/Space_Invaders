#ifndef PLAYER_H
#define PLAYER_H

#include "Object.hpp"
#include <SFML/Graphics.hpp>

class Player : public Object {
public:
    Player();
    ~Player();

    void draw() override;
    void update() override;
    void move() override;
};

#endif