#ifndef TICTACTOE_GAMEINFO_H
#define TICTACTOE_GAMEINFO_H

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

//states of game 
enum State { MENU };

struct GameInfo {
  State gamestate;
};

#endif