#pragma once
#include "gameobject.h"
#include "sgg/graphics.h"
#include <list>
#include "player.h"
#include "ball.h"

class Level : public GameObject
{
    graphics::Brush m_brush_background;

    std::vector<GameObject*> m_static_objects; //Lista me statika antikeimena
    std::list<GameObject*> m_dynamic_objects; //Lista me dynamika antikeimena p.x mpales

    float m_spawn_timer = 0.0f; 
    float m_spawn_interval = 1.0f; //Xrosnos se seconds anamesa se kainourgia antikeimena

public:
    void update(float dt) override;
    void init() override;
    void draw() override;

    Level(const std::string& name = "Level0");
    ~Level();
};
