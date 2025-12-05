#include "ball.h"
#include "gamestate.h"
#include "player.h"
#include <cstdlib>
#include "sgg/graphics.h"

Ball::Ball(const std::string& name, float speed)
    : GameObject(name), m_speed(speed)
{
    m_pos_x = static_cast<float>(std::rand()) / RAND_MAX * GameState::getInstance()->getCanvasWidth();      //thesh mpalas ston axona x
    m_pos_y = 0.5f;
}

void Ball::init()
{
    m_brush.texture = GameState::getInstance()->getFullAssetPath("ball.png");       //eikona mpalas
    m_brush.outline_opacity = 0.0f;
    m_brush.fill_opacity = 1.0f;
}

void Ball::update(float dt)
{
    m_pos_y += m_speed * dt / 1000.0f;

    if (m_pos_y > GameState::getInstance()->getCanvasHeight())
    {
        m_active = false;       //false otan oi mpales feugoun apo thn othoni
        return;
    }

    Player* player = GameState::getInstance()->getPlayer();     //ginetai elegxos gia sygkrousi
    if (player)                                         
    {
        float player_x = player->getPositionX();        
        float player_y = player->getPositionY();
        float net_width = 1.5f; 
        float net_height = 0.5f; 

        if (m_pos_x > player_x - net_width / 2.0f &&
            m_pos_x < player_x + net_width / 2.0f &&
            m_pos_y > player_y - net_height / 2.0f &&
            m_pos_y < player_y + net_height / 2.0f)
        {
            m_active = false;               //piasame thn mpala
            GameState::getInstance()->incrementScore();         //aujhsh toy skor??
        }
    }
}

void Ball::draw()
{
    graphics::drawRect(m_pos_x, m_pos_y, 0.6f, 0.6f, m_brush);
}
float Ball::getPositionY() const
{
    return m_pos_y;
}

