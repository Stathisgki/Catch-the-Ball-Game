#include "player.h"
#include "sgg/graphics.h"
#include "gamestate.h"

void Player::movePlayer(float dt)
{
    float delta_time = dt / 100.0f;

    float move = 0.0f;

    if (graphics::getKeyState(graphics::SCANCODE_LEFT))     //kinhsh dejia aristera analoga me poio koympi patame
        move -= 1.0f;

    if (graphics::getKeyState(graphics::SCANCODE_RIGHT))
        move += 1.0f;

    m_vx = delta_time * move * (m_accel_horizontal * 0.2f);             //taxythta kalathiou
    m_vx = std::min(m_max_velocity, std::max(-m_max_velocity, m_vx));
    m_vx -= 0.05f * m_vx;
    m_pos_x += delta_time * m_vx;

    float canvas_width = m_state->getCanvasWidth();         //o paikths kineitai mexri ta oria tou kamva
    m_pos_x = std::max(0.0f, std::min(canvas_width, m_pos_x)); 
}




void Player::update(float dt)
{
	
	movePlayer(dt);

	GameObject::update(dt);
}

void Player::init()
{
	m_pos_x = 3.0f;
	m_pos_y = 5.2f;
	

	m_brush_player.fill_opacity = 1.0f;
	m_brush_player.outline_opacity = 0.0f;
	m_brush_player.texture = m_state->getFullAssetPath("net.png");

}

void Player::draw()
{

	graphics::drawRect(m_pos_x,m_pos_y, 1.5f, 1.5f, m_brush_player);        //kaleitai h draw gia sxediash neoy paikth

}
float Player::getPositionX() const
{
    return m_pos_x;
}

float Player::getPositionY() const
{
    return m_pos_y;
}
