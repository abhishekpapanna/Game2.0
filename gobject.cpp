#include "gobject.h"
#include "olcPixelGameEngine.h"
#include "pixelgeinterface.h"
#include <iostream>
#include <string>

extern PixelGEinterface * Game;

GObject::GObject()
{
    objPos = float(Game->ScreenWidth() - Game->ScreenWidth()/2 - 50);
    objSprite = new olc::Sprite("./img/player.png");
    bullet2 = new olc::Sprite("./img/bullet.png");
    bulletdecal2 = new olc::Decal(bullet2);
    moveval = float(Game->ScreenHeight()-150);
}

float GObject::updatePos()
{
    //Grab inputs and adjust position accordingly
    if (Game->GetKey(olc::Key::LEFT).bHeld) objPos -= objSpeed;
    if (Game->GetKey(olc::Key::RIGHT).bHeld) objPos += objSpeed;

    //Ensure player is bound to the screen size
    if (objPos < 11.0f) objPos = 11.0f;
    if (objPos + objWidth > float(Game->ScreenWidth()) - 10.0f) objPos = float(Game->ScreenWidth()) - 10.0f - objWidth;

    return objPos;
}

float GObject::getPos()
{
    return objPos;
}

void GObject::spawn()
{
    if (bulletdecal2 != nullptr)
        Game->DrawDecal({objPos + 43.0f,moveval},bulletdecal2);
    moveval --;
    if (moveval < 0){
        delete bulletdecal2;
        bulletdecal2 = nullptr;
        moveval = float(Game->ScreenHeight()-150);
    }
}

void GObject::createbul()
{
    bulletdecal2 = new olc::Decal(bullet2);
    moveval = float(Game->ScreenHeight()-150);
}





