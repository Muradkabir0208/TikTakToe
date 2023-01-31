#ifndef TIKTAKTOE_GAMESCENE_HPP
#define TIKTAKTOE_GAMESCENE_HPP

#include "../eventhandler.h"
#include "../gameinfo.h"
#include "ui/animation.h"
#include "ui/button.h"
#include "ui/map.h"
#include "ui/textinput.h"
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <memory>
#include <pthread.h>

class GameScene : public EventHandler
{
    static constexpr float RESET_TIME = 5.0f;

    GameInfo *gameInfo;
    sf::Texture crossTex;
    sf::Texture circleTex;
    sf::Texture layoutTex;
    sf::Sprite layout;
    sf::Text title;

    Map map;
    Button mapButtons[3][3];
    char player;
    sf::Vector2i toPlace;
    bool moveMade;
    bool gameOver = false;
    float time = 0;
    // TODO: implement internal gamestate system as opposed the "figure out where
    // we are and do things"

public:
    explicit GameScene(GameInfo *gameInfo);

    void update(float delta);

    void draw(sf::RenderWindow &window);

    void handle(sf::Event &event) override;
};

#endif // TIKTAKTOE_GAMESCENE_HPP
