#pragma once
#include "gameobject.h"
#include "box.h"
#include "sgg/graphics.h"

class Player : public GameObject, public Box
{

	graphics::Brush m_brush_player;

	const float m_gravity = 10.0f;
	const float m_accel_horizontal = 20.0f;
	const float m_max_velocity = 10.0f;

	void movePlayer(float dt);


public:
	float  m_vx = 0.0f;

	void update(float dt) override;
	void init() override;
	void draw() override;
	float getPositionX() const;
	float getPositionY() const;
    Player(std::string name) : GameObject(name) {};


protected:
	void debugDraw();

};