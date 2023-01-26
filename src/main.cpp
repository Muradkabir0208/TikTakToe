#include <iostream>
#include "gameinfo.h"
#include "window.h"

int main(int argc, char **argv)
{
    GameInfo gameInfo;
    gameInfo.gamestate = MENU;
    Window window("Tic Tac Toe");
    while (window.isRunning())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) &&
            window.isFocused())
        {
            window.getWindow().close();
        }
        float delta = window.update();
        window.prepare();

        // render

        if (gameInfo.gamestate == MENU)
        {
            std::cout << "print menu screen";
        }

        window.display();
    }
    return 0;
}