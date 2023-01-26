#ifndef TICTACTOE_EVENTHANDLER_H
#define TICTACTOE_EVENTHANDLER_H

#include <SFML/Graphics.hpp>

struct EventHandler {
  virtual void handle(sf::Event &) = 0;
};

#endif