#pragma once
#include "ball.h"
#include <string>
#include <sgg/graphics.h>
#include <vector>

class GameState 
{
private:
	std::string m_asset_path = "assets\\";

	float m_canvas_width = 6.0f;
	float m_canvas_height = 6.0f;

	static GameState* m_unique_instance;

	float m_elapsed_time = 0.0f; //Synolikos xronos apo tote pou jekinhse to paixnidi

	int m_fallen_balls = 0; //Metrhths gia to poses mpales peftoun
	bool m_game_over = false; //Elegxei an eimaste sto game over

	GameState();

	class Player* m_player = 0;
	class Level* m_current_level = 0;
	float m_time_since_last_ball = 0.0f;
	float m_ball_spawn_interval = 2000.0f; 
	std::vector<Ball*> m_balls; //Lista me tis energer mpales 

public:
	typedef enum { STATUS_START, STATUS_PLAYING } status_t;
	status_t status = STATUS_START;
	void updateStartScreen();
	void drawStartScreen();
	float m_global_offset_x = 0.0f;
	float m_global_offset_y = 0.0f;
	bool m_debugging = false;
	float m_score = 0.0f;

	bool init();
	void draw();
	void update(float dt);
	void incrementScore();
	static GameState* getInstance();
	~GameState();

	float getCanvasWidth() { return m_canvas_width; }
	float getCanvasHeight() { return m_canvas_height; }

	std::string getAssetDir();
	std::string getFullAssetPath(const std::string& asset);

	class Player* getPlayer() { return m_player; }

};

