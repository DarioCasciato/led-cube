// =============================================================================
// Template-Project | Blink
// =============================================================================

#include <Arduino.h>
#include "Modes.h"
#include "../Cube/Cube.h"
#include "../utils/Timer/Timer.h"

constexpr uint16_t delayTime = 500;


void Mode::blink(){
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
        CB::cube.setCubeColor(RED____);
        break;
        case 1:
        CB::cube.setCubeColor(GREEN__);
        break;
        case 2:             
        CB::cube.setCubeColor(YELLOW_);             
        break;         
        case 3:             
        CB::cube.setCubeColor(WHITE__);             
        break;         
        case 4:             
        CB::cube.setCubeColor(CYAN___);             
        break;         
        case 5:             
        CB::cube.setCubeColor(BLUE___);             
        break;         
        case 6:             
        CB::cube.setCubeColor(MAGENTA);             
        break;         
        /*case 7:             
        CB::cube.setCubeColor(OFF____);             
        break;       */  
        default:             
        frame = 0; // Reset the frame counter after the last known frame            
        break;     
    } 
}
