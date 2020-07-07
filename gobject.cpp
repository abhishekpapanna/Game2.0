#include "gobject.h"
#include "olcPixelGameEngine.h"
#include "pixelgeinterface.h"
#include <iostream>

extern PixelGEinterface * Game;

GObject::GObject()
{
    objPos = float(Game->ScreenWidth() - Game->ScreenWidth()/2 - 50);
    objSprite = new olc::Sprite("./img/player.png");
}

float GObject::updatePos()
{
    if (Game->GetKey(olc::Key::LEFT).bHeld) objPos -= objSpeed;
    if (Game->GetKey(olc::Key::RIGHT).bHeld) objPos += objSpeed;

    if (objPos < 11.0f) objPos = 11.0f;
    if (objPos + objWidth > float(Game->ScreenWidth()) - 10.0f) objPos = float(Game->ScreenWidth()) - 10.0f - objWidth;
    //if (playerPos + playerWidth > float(ScreenWidth()) - 10.0f) playerPos = float(ScreenWidth()) - 10.0f - playerWidth;

    return objPos;
}

float GObject::getPos()
{
    return objPos;
}

