#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "pixelgeinterface.h"
#include "bullet.h"

PixelGEinterface::PixelGEinterface()
{
    sAppName = "Game2.0";
}

bool PixelGEinterface::OnUserCreate()
{
    //creating the player sprite
    objPlayer = new GObject();
    bg = new olc::Sprite("./img/bg2.png");
    bgdecal = new olc::Decal(bg);
    player = new olc::Sprite("./img/player.png");
    playerdecal = new olc::Decal(player);
    bullet = new olc::Sprite("./img/bullet.png");
    bulletdecal = new olc::Decal(bullet);
    playerPos = objPlayer->getPos();

    for (int i = 190; i > 150; i-=0.01){
        Clear(olc::DARK_BLUE);
        DrawDecal({playerPos,float(ScreenHeight())-i},playerdecal);
    }

    return true;
}

bool PixelGEinterface::OnUserUpdate(float fElapsedTime)
{
    if (GetKey(olc::Key::SPACE).bPressed){
        bulletobj = new Bullet();
        objPlayer->createbul();
    }

    //Defining user inputs moved into the method
    //Gets player position for the current frame
    playerPos = objPlayer->updatePos();


    //clear previous frame
    Clear(olc::DARK_BLUE);

    //Draw the frame
    DrawDecal({float(0),float(0)},bgdecal);
    DrawDecal({playerPos,float(ScreenHeight()-150)},playerdecal);
    if (bulletobj != nullptr){
    //if (GetKey(olc::Key::SPACE).bHeld){
        objPlayer->spawn();
    }

    return true;
}

