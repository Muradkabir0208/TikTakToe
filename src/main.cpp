#include "window.h"

int main(int argc, char **argv)
{
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
        window.display();
    }
    return 0;
}