#ifndef TICTACTOE_WINDOW_HPP
#define TICTACTOE_WINDOW_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Window
{
    sf::Clock clock;
    sf::RenderWindow window;
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

    sf::RenderWindow &getWindow();
};

#endif