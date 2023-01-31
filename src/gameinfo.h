#ifndef TIKTAKTOE_GAMEINFO_H
#define TIKTAKTOE_GAMEINFO_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

// states of game
enum State
{
  MENU,
  NETWORK,
  GAME
};

enum NetworkType
{
  HOST,
  CLIENT
};

struct GameInfo
{
  State gamestate;
  NetworkType networkType;
  sf::TcpSocket *socket;
  sf::Font font;
  char me;
};

#endif