#ifndef TIKTAKTOE_MENUSCENE_H
#define TIKTAKTOE_MENUSCENE_H

#include "../eventhandler.h"
#include "../gameinfo.h"
#include "ui/button.h"
#include <memory>

class MenuScene : public EventHandler
{

  GameInfo *gameInfo;
  sf::Texture buttonTex;
  Button playHostButton;
  Button playClientButton;

public:
  explicit MenuScene(GameInfo *gameInfo);

  void draw(sf::RenderWindow &window);

  void handle(sf::Event &event) override;
};

#endif // TIKTAKTOE_MENUSCENE_H