#ifndef GOBJECT_H
#define GOBJECT_H
#include "olcPixelGameEngine.h"

class GObject
{
public:
    GObject();
    float updatePos();
    float getPos();
    void setPos(float*);
    //void setSprite(std::string*);
    olc::Sprite* getSprite();
    void spawn();
    void createbul();

private:
    olc::Sprite* objSprite = nullptr;
    float objPos = 0.0f;
    float objWidth = 90.0f;
    float objSpeed = 0.5f;
    float moveval = 1.0f;
    olc::Sprite* bullet2 = nullptr;
    olc::Decal* bulletdecal2 = nullptr;
};

#endif // GOBJECT_H
