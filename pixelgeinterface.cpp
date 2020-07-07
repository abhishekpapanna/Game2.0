#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "pixelgeinterface.h"

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
    playerPos = objPlayer->getPos();
    return true;
}

bool PixelGEinterface::OnUserUpdate(float fElapsedTime)
{
    //Defining user inputs
    //Gets player position for the current frame
   /* if (GetKey(olc::Key::LEFT).bHeld) playerPos -= playerSpeed;
    if (GetKey(olc::Key::RIGHT).bHeld) playerPos += playerSpeed;


    if (playerPos < 11.0f) playerPos = 11.0f;
    if (playerPos + playerWidth > float(ScreenWidth()) - 10.0f) playerPos = float(ScreenWidth()) - 10.0f - playerWidth;
    //if (playerPos + playerWidth < float(ScreenWidth()) + 10.0f) playerPos = float(ScreenWidth()) + 10.0f + playerWidth; */
    playerPos = objPlayer->updatePos();

    //clear previous frame
    Clear(olc::DARK_BLUE);

    //Draw the frame
    DrawDecal({float(0),float(0)},bgdecal);
    DrawDecal({playerPos,float(ScreenHeight()-150)},playerdecal);

    return true;
}
