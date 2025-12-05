#pragma once
#include "gameobject.h"
#include "sgg/graphics.h"
#include "level.h"

//Header file gia tis mpales pou peftoun
class Ball : public GameObject
{
private:
    float m_speed;              // Taxythta pou peftei h mpala
    graphics::Brush m_brush;    
    float m_pos_x;              //Thesh ths mpalas ston orizontio ajona
    float m_pos_y;              //Thesh ths mpalas ston katheto ajona


public:
    Ball(const std::string& name, float speed); 
    void update(float dt) override;            
    void draw() override;                      
    void init() override;   
    float getPositionY() const; //Epistrefei thn thesh Y ths mpalas
    
};

