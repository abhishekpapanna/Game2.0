#ifndef PIXELGEINTERFACE_H
#define PIXELGEINTERFACE_H

#include "olcPixelGameEngine.h"
#include "gobject.h"
#include "bullet.h"

class PixelGEinterface : public olc::PixelGameEngine
{
public:
    PixelGEinterface();
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
    olc::Sprite* player = nullptr;
    olc::Decal* playerdecal = nullptr;
    olc::Sprite* bg = nullptr;
    olc::Decal* bgdecal = nullptr;
    olc::Sprite* bullet = nullptr;
    olc::Decal* bulletdecal = nullptr;

private:
    float playerPos = 0.0f;
    float playerWidth = 90.0f;
    float playerSpeed = 1.0f;
    GObject * objPlayer = nullptr;
    Bullet * bulletobj = nullptr;
};

#endif // PIXELGEINTERFACE_H
