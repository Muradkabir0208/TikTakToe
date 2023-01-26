#ifndef TIKTAKTOE_BUTTON_HPP
#define TIKTAKTOE_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <functional>
#include <memory>

class Button
{

    static constexpr float DOWN_SCALE = 0.94f;

    sf::Sprite sprite;

    std::function<void()> onclick;
    sf::Text text;
    bool down = false;

public:
    Button() = default;

    Button(std::string text, sf::Texture texture, sf::Vector2f position,
           std::function<void()> onclick);

    void draw(sf::RenderWindow &window);

    void mouseDown(int x, int y);

    void mouseUp(int x, int y);

    void setFont(const sf::Font &font);

    void setText(const std::string &text);

    void setTexture(const sf::Texture &texture);

    void setPosition(const sf::Vector2f &position);

    const sf::FloatRect getBounds() const;

    void setOnclick(const std::function<void()> &onclick);
};

#endif // TIKTAKTOE_BUTTON_HPP
