#pragma once
#include "gamestate.h"
#include <sgg/graphics.h>
#include <vector>
#include <string>

class HomePage
{
private:
    GameState* m_state;
    graphics::Brush m_brush_background;
    int m_selected_option = 0;
    std::vector<std::string> m_options = { "Start Game", "Options", "Exit" };

public:
    HomePage(GameState* state);
    void init();
    void draw();
    void update(float dt);
    void handleSelection();
};
