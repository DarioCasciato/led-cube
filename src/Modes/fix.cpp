// =============================================================================
// Template-Project | Fix
// =============================================================================

#include <Arduino.h>
#include "Modes.h"
#include "../Cube/Cube.h"


namespace
{
    uint8_t layer[6][6] =
    {
        {RED____, RED____, RED____, RED____, RED____, RED____},
        {GREEN__, GREEN__, GREEN__, GREEN__, GREEN__, GREEN__},
        {BLUE___, BLUE___, BLUE___, BLUE___, BLUE___, BLUE___},
        {YELLOW_, YELLOW_, YELLOW_, YELLOW_, YELLOW_, YELLOW_},
        {CYAN___, CYAN___, CYAN___, CYAN___, CYAN___, CYAN___},
        {MAGENTA, MAGENTA, MAGENTA, MAGENTA, MAGENTA, MAGENTA}
    };
}


void Mode::fix()
{
    CB::cube.drawCube(layer, layer, layer, layer, layer, layer);
}
