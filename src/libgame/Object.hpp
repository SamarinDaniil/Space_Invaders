#ifndef OBJECT_H
#define OBJECT_H

#include <SFML/Graphics.hpp>

class Object {
protected:
    //
    float VecX;
    //
    sf::Vector2f obj_position;
    //
    sf::Sprite obj_sprite;
    //
    sf::Texture obj_texture;
    //
    sf::RenderWindow* window;
    //
    bool life;

public:
    Object(sf::Uint64 state = player);
    Object(sf::Vector2f Vector);
    ~Object();
    //
    enum state { bullet_l, enemy, player };
    //
    bool stat_life();
    void setlife(bool l);
    void setVecX(float Vec);
    float getVecX();
    //
    void setWindow(sf::RenderWindow* game_window);
    sf::Sprite getSprite();
    void setSprite(sf::Sprite sprite);
    sf::Vector2f getVector();
    void setVector(sf::Vector2f Vector);
    //
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void move() = 0;
    //
    sf::Uint64 obj_state;
    static float constexpr window_size_x = 800;
    static float constexpr window_size_y = 800;
};

#endif