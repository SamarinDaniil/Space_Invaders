#include "Engine.hpp"

sf::Font font;//шрифт 

Engine::Engine()
{
    this->game_state = menu;
    // создаем окно SFML
    game_window.create(sf::VideoMode(800, 800), "Space Invaders");

    // Загружаем фон в текстуру
    // Подготовьте изображение под ваш размер экрана в редакторе
    game_texture.loadFromFile("resources/images/background/bg_1.png");

    // Связываем спрайт и текстуру
    game_background.setTexture(game_texture);
    //
    obj[0] = new Player();
    obj[1] = new Bullet();
    obj[2] = new Enemy();
    obj[3] = new Bullet();
    //
    obj[3]->setVecX(1);
    //
    for (int i = 0; i < 4; i++)
        obj[i]->setWindow(&game_window);
}
Engine::~Engine()
{
}
//
void Engine::start()
{
    font.loadFromFile("resources/text-style/Opel_Sans_Bold.ttf");//передаем нашему шрифту файл шрифта
    obj[1]->setVector(sf::Vector2f(obj[0]->getVector().x + 30, 695));
    while (game_window.isOpen()) {
        info(game_state);
    }
}
//
void Engine::info(sf::Uint64 game_s)
{
    if (game_s != play)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            game_window.close();
        // Обрабатываем нажатие клавиш 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            obj[0]->setVector(sf::Vector2f(200, 700));
            obj[1]->setVector(sf::Vector2f(obj[0]->getVector().x + 30, 695));
            obj[1]->setlife(false);
            obj[2]->setVector(sf::Vector2f(200, 100));
            obj[3]->setVector(sf::Vector2f(obj[2]->getVector().x + 30, 155));
            obj[3]->setlife(false);
            game_state = play;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
            game_window.close();
        }
        std::string text_s[3];
        text_s[1] = "[1] Start";
        text_s[2] = "[2] Exit";
        sf::Text text("", font, 40);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
        text.setStyle(sf::Text::Bold);
        game_window.clear(sf::Color::White);
        // Отрисовываем фон
        game_window.draw(game_background);
        //
        for(int i = 1; i < 3; i++)
        {
            text.setString(text_s[i]);
            text.setPosition(sf::Vector2f(300,300 + 60*i));
            game_window.draw(text);
        }
        //
        switch (game_s)
        {
        case menu:
            {
                text_s[0] = "Space Invaders";
                text.setString(text_s[0]);
                text.setPosition(sf::Vector2f(300,300));
                game_window.draw(text);
            }
            break;
        case lose:
            {
                text_s[0] = "You Lose";
                text.setString(text_s[0]);
                text.setPosition(sf::Vector2f(300,300));
                game_window.draw(text);            
            }
            break;
        case win:
            {
                text_s[0] = "You Win";
                text.setString(text_s[0]);
                text.setPosition(sf::Vector2f(300,300));
                game_window.draw(text);            
            }
            break;
        default:
            break;
        }
        //
        game_window.display();        
    } else {
            input();
            if(obj[3]->stat_life() == false)
            {   
                obj[3]->setlife(true);
                obj[3]->setVector(sf::Vector2f(obj[2]->getVector().x + 30, 155));
            }
            if (obj[1]->stat_life() == false) {
                obj[1]->setVector(sf::Vector2f((obj[0]->getVector().x + 30), 695));
            }
            if (static_cast<Bullet*>(obj[1])->object_interaction(obj[2])) {
                game_state = win;
            }
            if (static_cast<Bullet*>(obj[3])->object_interaction(obj[0])) {
                game_state = lose;
            }
            for (int i = 0; i < 4; i++) {
                update(obj[i]);
            }
            draw();
    }
    
}

//
void Engine::input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        game_window.close();
    // Обрабатываем нажатие клавиш движения
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        obj[0]->setVecX(-5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        obj[0]->setVecX(5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        obj[0]->setVecX(0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        obj[1]->setlife(true);
    }
}

void Engine::update(Object* obj)
{
    obj->update();
    obj->move();
}

void Engine::draw()
{
    // Стираем предыдущий кадр
    game_window.clear(sf::Color::White);

    // Отрисовываем фон
    game_window.draw(game_background);
    // И
    for (int i = 0; i < 4; i++)
        obj[i]->draw();

    // Отображаем все, что нарисовали
    game_window.display();
}
//
