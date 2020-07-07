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
    void setSprite(olc::Sprite*);
    olc::Sprite* getSprite();

private:
    olc::Sprite* objSprite = nullptr;
    float objPos = 0.0f;
    float objWidth = 90.0f;
    float objSpeed = 0.5f;
};

#endif // GOBJECT_H
