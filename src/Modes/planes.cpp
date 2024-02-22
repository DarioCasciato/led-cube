



#include <Arduino.h>
#include "Modes.h"
#include "../Cube/Cube.h"
#include "../utils/Timer/Timer.h"

namespace
{
    static uint8_t cubeState[6][6][6] = {{{0}}};
}

void Mode::movingLayers()
{
    static Timer timer;
    static uint8_t horizontalLayer = 0;
    static uint8_t verticalLayer = 0;
    static bool movingUp = true;
    static bool movingRight = true;

    if (0 == timer.elapsedStart())
        timer.start();

    if (timer.elapsed(500)) // Adjust the delay as needed for the speed of movement
    {
        // Reset the cubeState to zero (turn off all LEDs)
        memset(cubeState, 0, sizeof(cubeState));

        // Set the LEDs in the horizontal layer to CYAN___
        for (uint8_t x = 0; x < 6; ++x)
        {
            for (uint8_t y = 0; y < 6; ++y)
            {
                cubeState[horizontalLayer][x][y] = CYAN___;
            }
        }

        // Set the LEDs in the vertical layer to CYAN___
        for (uint8_t z = 0; z < 6; ++z)
        {
            cubeState[z][verticalLayer][horizontalLayer] = GREEN__; // This sets the intersecting vertical line
            for (uint8_t x = 0; x < 6; ++x)
            {
                cubeState[z][verticalLayer][x] = CYAN___;
            }
        }

        // Update the horizontal layer position
        if (movingUp)
        {
            if (horizontalLayer < 5)
                horizontalLayer++;
            else
            {
                horizontalLayer--;
                movingUp = false;
            }
        }
        else
        {
            if (horizontalLayer > 0)
                horizontalLayer--;
            else
            {
                horizontalLayer++;
                movingUp = true;
            }
        }

        // Update the vertical layer position
        if (movingRight)
        {
            if (verticalLayer < 5)
                verticalLayer++;
            else
            {
                verticalLayer--;
                movingRight = false;
            }
        }
        else
        {
            if (verticalLayer > 0)
                verticalLayer--;
            else
            {
                verticalLayer++;
                movingRight = true;
            }
        }



        // Reset the timer
        timer.start();
    }

    // Draw the cube with the current state of each layer
    CB::cube.drawCube(cubeState[0], cubeState[1], cubeState[2], cubeState[3], cubeState[4], cubeState[5]);
}