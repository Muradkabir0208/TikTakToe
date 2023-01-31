#ifndef TIKTAKTOE_ANIMATION_H
#define TIKTAKTOE_ANIMATION_H

#include <SFML/Graphics.hpp>
#include <list>
#include <memory>

class Animation {

  float swapTime;
  float time = 0;
  sf::Sprite sprite;
  int currentFrame = 0;
  std::vector<sf::IntRect> regions;

public:
  Animation() = default;

  Animation(float fps, sf::Texture &texture, int rows, int cols);

  void setFps(float fps);

  void setTexture(sf::Texture &texture, int rows, int cols);

  void setPosition(sf::Vector2f pos);

  void update(float delta);

  void draw(std::shared_ptr<sf::RenderWindow> &window);
};

#endif // TIKTAKTOE_ANIMATION_H
