// =============================================================================
// Template-Project | Random
// =============================================================================

#include <Arduino.h>
#include "Modes.h"
#include "../Cube/Cube.h"
#include "../utils/Timer/Timer.h"

constexpr uint16_t delayTime = 500;

namespace
{
    uint8_t off[6][6] =
    {
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____}
    };
    uint8_t tinycube[6][6] =
    {
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, CYAN___, CYAN___, OFF____, OFF____},
        {OFF____, OFF____, CYAN___, CYAN___, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____}
    };
    uint8_t tinycubet[6][6] =
    {
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, CYAN___, OFF____, OFF____, CYAN___, OFF____},
        {OFF____, OFF____, CYAN___, CYAN___, OFF____, OFF____},
        {OFF____, OFF____, CYAN___, CYAN___, OFF____, OFF____},
        {OFF____, CYAN___, OFF____, OFF____, CYAN___, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____}
    };
    uint8_t middelcube1[6][6] =
    {
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, CYAN___, CYAN___, CYAN___, CYAN___, OFF____},
        {OFF____, CYAN___, OFF____, OFF____, CYAN___, OFF____},
        {OFF____, CYAN___, OFF____, OFF____, CYAN___, OFF____},
        {OFF____, CYAN___, CYAN___, CYAN___, CYAN___, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____}
    };
    uint8_t middelcube2[6][6] =
    {
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, CYAN___, OFF____, OFF____, CYAN___, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, CYAN___, OFF____, OFF____, CYAN___, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____}
    };
    uint8_t middelcube1t[6][6] =
    {
        {CYAN___, OFF____, OFF____, OFF____, OFF____, CYAN___},
        {OFF____, CYAN___, CYAN___, CYAN___, CYAN___, OFF____},
        {OFF____, CYAN___, OFF____, OFF____, CYAN___, OFF____},
        {OFF____, CYAN___, OFF____, OFF____, CYAN___, OFF____},
        {OFF____, CYAN___, CYAN___, CYAN___, CYAN___, OFF____},
        {CYAN___, OFF____, OFF____, OFF____, OFF____, CYAN___}
    };
    uint8_t middelcube2t[6][6] =
    {
        {CYAN___, OFF____, OFF____, OFF____, OFF____, CYAN___},
        {OFF____, CYAN___, OFF____, OFF____, CYAN___, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, CYAN___, OFF____, OFF____, CYAN___, OFF____},
        {CYAN___, OFF____, OFF____, OFF____, OFF____, CYAN___}
    };
    uint8_t bigcube1[6][6] =
    {
        {CYAN___, CYAN___, CYAN___, CYAN___, CYAN___, CYAN___},
        {CYAN___, OFF____, OFF____, OFF____, OFF____, CYAN___},
        {CYAN___, OFF____, OFF____, OFF____, OFF____, CYAN___},
        {CYAN___, OFF____, OFF____, OFF____, OFF____, CYAN___},
        {CYAN___, OFF____, OFF____, OFF____, OFF____, CYAN___},
        {CYAN___, CYAN___, CYAN___, CYAN___, CYAN___, CYAN___}
    };
    uint8_t bigcube2[6][6] =
    {
        {CYAN___, OFF____, OFF____, OFF____, OFF____, CYAN___},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {OFF____, OFF____, OFF____, OFF____, OFF____, OFF____},
        {CYAN___, OFF____, OFF____, OFF____, OFF____, CYAN___}
    };
}

void Mode::rgb()
{
    static Timer timer;
    static int frame = 0; // Frame counter
    if (0 == timer.elapsedStart()) {
         timer.start();
    }
    if (timer.elapsed(delayTime)) {
        frame++; // Move to the next frame
        timer.start(); // Reset the timer for the next frame
    }
    switch(frame) {
        case 0:                                                              
        CB::cube.drawCube(off,off,tinycube,tinycube,off,off);        
        break;
        case 1:                                                              
        CB::cube.drawCube(off,middelcube1,tinycubet,tinycubet,middelcube1,off);
        frame++;       
        break;
        case 2:
        CB::cube.drawCube(off,middelcube1,middelcube2,middelcube2,middelcube1,off);
        break;
        case 3:
        CB::cube.drawCube(bigcube1,middelcube1t,middelcube2t,middelcube2t,middelcube1t,bigcube1);
        frame++;
        break;
        case 4:             
        CB::cube.drawCube(bigcube1,bigcube2,bigcube2,bigcube2,bigcube2,bigcube1);             
        break;         
        case 5:             
        CB::cube.drawCube(bigcube1,bigcube2,bigcube2,bigcube2,bigcube2,bigcube1);            
        break;
        case 6:
        CB::cube.drawCube(bigcube1,middelcube1t,middelcube2t,middelcube2t,middelcube1t,bigcube1);
        frame++;
        break;         
        case 7:             
        CB::cube.drawCube(off,middelcube1,middelcube2,middelcube2,middelcube1,off);             
        break;
        case 8:                                                              
        CB::cube.drawCube(off,middelcube1,tinycubet,tinycubet,middelcube1,off);
        frame++;       
        break;         
        case 9:             
        CB::cube.drawCube(off,off,tinycube,tinycube,off,off);
        //CB::cube.setCubeColor(OFF____);            
        break;                
        default:             
        frame = 0; // Reset the frame counter after the last known frame            
        break;     
    } 
}
