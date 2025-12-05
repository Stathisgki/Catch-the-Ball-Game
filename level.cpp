#include "level.h"
#include "gamestate.h"
#include <cstdlib>

void Level::update(float dt)
{
    if (m_state->getPlayer()->isActive())
        m_state->getPlayer()->update(dt);

    m_spawn_timer += dt / 1000.0f;
    if (m_spawn_timer >= m_spawn_interval)
    {
        Ball* new_ball = new Ball("Ball", 2.0f + static_cast<float>(std::rand()) / RAND_MAX * 3.0f);        //dhmioyrgia neas mpalas
        new_ball->init();
        m_dynamic_objects.push_back(new_ball);
        m_spawn_timer = 0.0f;
    }

    for (auto it = m_dynamic_objects.begin(); it != m_dynamic_objects.end();)
    {
        GameObject* obj = *it;
        obj->update(dt);

        if (!obj->isActive())
        {
            delete obj;
            it = m_dynamic_objects.erase(it);
        }
        else
        {
            ++it;
        }
    }

    GameObject::update(dt);
}

void Level::init()
{
    m_brush_background.outline_opacity = 0.0f;
    m_brush_background.texture = m_state->getFullAssetPath("background.png");

    for (auto p_gob : m_static_objects)
        if (p_gob) p_gob->init();

    for (auto p_gob : m_dynamic_objects)
        if (p_gob) p_gob->init();
}

void Level::draw()
{
    float w = m_state->getCanvasWidth();
    float h = m_state->getCanvasHeight();

    graphics::drawRect(w / 2.0f, h / 2.0f, w, h, m_brush_background);

    if (m_state->getPlayer()->isActive())
        m_state->getPlayer()->draw();

    for (auto p_gob : m_static_objects)
        if (p_gob) p_gob->draw();

    for (auto p_gob : m_dynamic_objects)
        if (p_gob) p_gob->draw();
}

Level::Level(const std::string& name) {}

Level::~Level()
{
    for (auto p_gob : m_static_objects)
        if (p_gob) delete p_gob;

    for (auto p_gob : m_dynamic_objects)
        if (p_gob) delete p_gob;
}