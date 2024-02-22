// =============================================================================
// Template-Project | Random
// =============================================================================

#include <Arduino.h>
#include "Modes.h"
#include "../Cube/Cube.h"
#include "../utils/Timer/Timer.h"

namespace
{
    uint8_t randomLayer[6][6][6] = {0};
}

void Mode::mRandom()
{
    static Timer timer;
    if(0 == timer.elapsedStart())
        timer.start();

    if(timer.elapsed(500))
    {
        for(uint8_t i = 0; i < 6; ++i)
        {
            for(uint8_t j = 0; j < 6; ++j)
            {
                for(uint8_t k = 0; k < 6; ++k)
                {
                    randomLayer[i][j][k] = random(0, 8);
                }
            }
        }

        timer.start();
    }
    CB::cube.drawCube(randomLayer[0], randomLayer[1], randomLayer[2], randomLayer[3], randomLayer[4], randomLayer[5]);
}
