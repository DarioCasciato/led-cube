// =============================================================================
// Template-Project | State
// =============================================================================

#include "state.h"
#include "hardware.h"
#include "configurations.h"
#include "Timer.h"
#include "Modes/Modes.h"
#include "Logging.h"

//------------------------------------------------------------------------------

namespace State
{
    States state = States::st_rgb;

    void stateDriver()
    {
        switch (State::state)
        {
            case State::st_fixed:
                Mode::fix();
                break;

            case State::st_blink:
                Mode::blink();
                break;

            case State::st_random:
                Mode::mRandom();
                break;

            case State::st_rgb:
                Mode::rgb();
                break;
                
            case State::st_planes:
                Mode::movingLayers();
                break;

            default:    // catch invalid state (implement safety backup)
                break;
        }


        // change state on button press
        if(Hardware::modeButton.getEdgePos())
        {
            state = (State::States)((state + 1) % States::NUM_STATES);
        }
    }

} // namespace State

//------------------------------------------------------------------------------

// Other Functions