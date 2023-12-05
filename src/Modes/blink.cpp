// =============================================================================
// Template-Project | Blink
// =============================================================================

#include <Arduino.h>
#include "Modes.h"
#include "../Cube/Cube.h"
#include "../utils/Timer/Timer.h"

constexpr uint16_t delayTime = 500;


void Mode::blink()
{
    static Timer timer;
    if(0 == timer.elapsedStart())
        timer.start();


    if(timer.elapsed(delayTime))        // Frame 1
    {
        CB::cube.setCubeColor(OFF____);
    }
    else if(timer.elapsed(delayTime*2)) // Frame 2
    {
        CB::cube.setCubeColor(GREEN__);
    }
    else if(timer.elapsed(delayTime*3)) // Frame 3
    {
        CB::cube.setCubeColor(RED____);
    }
    else if(timer.elapsed(delayTime*4)) // Frame 4
    {
        CB::cube.setCubeColor(YELLOW_);
    }
    else if(timer.elapsed(delayTime*5)) // Frame 5
    {
        CB::cube.setCubeColor(BLUE___);
    }
    else if(timer.elapsed(delayTime*6)) // Frame 6
    {
        CB::cube.setCubeColor(CYAN___);
    }
    else if(timer.elapsed(delayTime*7)) // Frame 7
    {
        CB::cube.setCubeColor(MAGENTA);
    }
    else if(timer.elapsed(delayTime*8)) // Frame 8
    {
        CB::cube.setCubeColor(WHITE__);
    }
    else if(timer.elapsed(delayTime*9)) // Reset animation
    {
        timer.start();
    }
}
