#include "gamestate.h"
#include "level.h"
#include "player.h"
#include <thread>
#include <chrono>
#include "ball.h"

void GameState::updateStartScreen()
{
    if (graphics::getKeyState(graphics::SCANCODE_RETURN))
    {
        status = STATUS_PLAYING;
        graphics::stopMusic();
    }
}

void GameState::drawStartScreen()
{
    graphics::Brush bg;
    bg.outline_opacity = 0.0f;
    bg.texture = getFullAssetPath("homepage.png");      //fonto paixnidiou

    float w = getCanvasWidth();
    float h = getCanvasHeight();

    graphics::drawRect(w / 2, h / 2, w, h, bg);
}

GameState::GameState()
{
    status = STATUS_START;
}

bool GameState::init()
{
    m_current_level = new Level();
    m_current_level->init();

    m_player = new Player("Player");        //dhmiourgia paikth
    m_player->init();

    graphics::preloadBitmaps(getAssetDir());
    graphics::playMusic(getFullAssetPath("Mind_Storm.mp3"), 0.5f, true);            //hxos arxhs paixnidiou

    return true;
}

void GameState::draw()
{
    if (m_game_over)
    {
        graphics::Brush go;
        go.outline_opacity = 0.0f;
        go.texture = getFullAssetPath("game_over.png");

        float w = getCanvasWidth();
        float h = getCanvasHeight();

        graphics::drawRect(w / 2, h / 2, w, h, go);

        return;
    }

    if (status == STATUS_PLAYING)
    {
        if (m_current_level)
        {
            m_current_level->draw();
        }

        for (Ball* ball : m_balls)
        {
            ball->draw();       //sxediasmos neas mpalas
        }

        m_player->draw();
    }
    else if (status == STATUS_START)
    {
        drawStartScreen();
    }
}

void GameState::update(float dt)
{
    if (m_game_over)
    {
        if (graphics::getKeyState(graphics::SCANCODE_RETURN))       //molis paththei to enter jekiname 
        {
            m_game_over = false;
            m_fallen_balls = 0;

            for (Ball* ball : m_balls)
            {
                delete ball;
            }
            m_balls.clear();        

            m_player->init();       //arxikopoihsh paikth 

            status = STATUS_PLAYING;
        }
        return;
    }

    if (status == STATUS_PLAYING)
    {
        m_time_since_last_ball += dt;

        if (m_time_since_last_ball >= m_ball_spawn_interval)
        {
            float dynamic_speed = 100.0f + (m_elapsed_time / 10000.0f * 10.0f);     //elegxoume thn taxythta pou peftoun oi mpales 
            Ball* new_ball = new Ball("Ball", dynamic_speed);
            new_ball->init();
            m_balls.push_back(new_ball);

            m_time_since_last_ball = 0.0f;
        }


        for (auto it = m_balls.begin(); it != m_balls.end();)
        {
            Ball* ball = *it;
            ball->update(dt);

            if (!ball->isActive())
            {
                if (ball->getPositionY() > getCanvasHeight())       //molis fygei h mpala apo thn othoni diagrafetai
                {
                    m_fallen_balls++;
                    if (m_fallen_balls >= 7)            //an pesoun pesoun 7 mpales termatizei 
                    {
                        m_game_over = true;
                        graphics::playSound(getFullAssetPath("game_over_sound.mp3"), 1.0f);     //hxos gameover
                        break;
                    }
                }

                delete ball;
                it = m_balls.erase(it);
            }
            else
            {
                ++it;
            }
        }

        m_player->update(dt);

        if (m_current_level)
        {
            m_current_level->update(dt);
        }
    }
    else if (status == STATUS_START)
    {
        updateStartScreen();
    }
}







GameState* GameState::getInstance()
{
    if (m_unique_instance == nullptr)
        m_unique_instance = new GameState();

    return m_unique_instance;
}

GameState::~GameState()
{
    if (m_player)
        delete m_player;

    for (Ball* ball : m_balls)
        delete ball;

    if (m_current_level)
        delete m_current_level;
}


std::string GameState::getAssetDir()
{
    return m_asset_path;
}

std::string GameState::getFullAssetPath(const std::string& asset)
{
    return m_asset_path + asset;
}

void GameState::incrementScore()
{
    m_score++; // Increment score or handle catching logic
}


GameState* GameState::m_unique_instance = nullptr;