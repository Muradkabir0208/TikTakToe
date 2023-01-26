#ifndef TICTACTOE_WINDOW_HPP
#define TICTACTOE_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <list>
#include <memory>

#include "eventhandler.h"

class Window
{
    sf::Clock clock;
    sf::RenderWindow window;
    std::list<EventHandler *> eventHandlers;
    bool focused = true;

public:
    static constexpr unsigned int VWIDTH = 500;
    static constexpr unsigned int VHEIGHT = 500;

    explicit Window(std::string title);

    ~Window();

    float update();
    void prepare();

    void display();

    bool isRunning();

    bool isFocused() const;

    void addEventHandler(EventHandler *handler);

    sf::RenderWindow &getWindow();
};

#endif