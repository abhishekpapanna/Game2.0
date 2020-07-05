#include "olcPixelGameEngine.h"
#include "pixelgeinterface.h"

int main()
{
    PixelGEinterface game;
    if (game.Construct(800,600,2,2))
        game.Start();
    return 0;
}
