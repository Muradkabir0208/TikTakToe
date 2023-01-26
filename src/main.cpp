#include <iostream>
#include "gameinfo.h"
#include "window.h"

int main(int argc, char **argv)
{
    GameInfo gameInfo;
    gameInfo.gamestate = MENU;

    Window window("Tic Tac Toe");
    
    MenuScene menuScene(&gameInfo);

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
            menuScene.draw(window.getWindow());
        }

        window.display();
    }
    return 0;
}