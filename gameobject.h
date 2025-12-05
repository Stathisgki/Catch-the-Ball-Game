#pragma once
#include <string>

class GameObject
{
	static int m_next_id; //metrhths gia anathesi monadikwn id se game objects
protected:
	class GameState* m_state;
	std::string m_name;
	int m_id = 0; //monadiko id gia to game object
	bool m_active = true; //elegxei an to object einai energo

public:
	GameObject(const std::string& name = "");
	virtual void update(float dt) {}
	virtual void init() {}
	virtual void draw() {}
	virtual ~GameObject() {}
	bool isActive() { return m_active; }
	void setActive(bool a) { m_active = a; }
};