#ifndef ENGINE_H
#define ENGINE_H

#include "Bullet.hpp"
#include "Enemy.hpp"
#include "Object.hpp"
#include "player.hpp"
#include <SFML/Graphics.hpp>

class Engine {
private:
    //
    sf::RenderWindow game_window;
    //
    sf::Sprite game_background;
    //
    sf::Texture game_texture;
    //
    Object* obj[6];
    //
    void input();
    void update(Object* obj);
    void draw();
    void info(sf::Uint64 game_s);
    enum state_g
    {
        lose,
        win,
        menu,
        play
    };
    sf::Uint64 game_state;
public:
    Engine();
    ~Engine();

    //
    void start();
};

#endif