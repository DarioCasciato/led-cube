// =============================================================================
// Template-Project | State
// =============================================================================

#include "state.h"
#include "hardware.h"
#include "configurations.h"
#include "Timer.h"
#include "Modes/Modes.h"

//------------------------------------------------------------------------------

namespace State
{
    States state = States::st_fixed;

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

            default:    // catch invalid state (implement safety backup)
            goto exception;
                break;
        }

        return;

        exception:
            for(;;) {}


        // change state on button press
        if(Hardware::modeButton.getEdgePos())
        {
            state = (State::States)((state + 1) % States::NUM_STATES);
        }
    }

} // namespace State

//------------------------------------------------------------------------------

// Other Functions