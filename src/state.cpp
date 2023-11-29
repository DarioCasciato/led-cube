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
    States state = States::st_white;

    void stateDriver()
    {
        switch (State::state)
        {
            case State::st_white:
                Mode::blink();
                break;

            case State::st_animation:
                Mode::random();
                break;

            case State::st_random:
                Mode::test();
                break;

            default:    // catch invalid state (implement safety backup)
            goto exception;
                break;
        }

        return;

        exception:
            for(;;) {}


        // change state on button press
        if(Hardware::btn0.getEdgePos())
        {
            state = static_cast<States>((static_cast<uint8_t>(state) + 1) % static_cast<uint8_t>(States::NUM_STATES));
        }
    }

} // namespace State

//------------------------------------------------------------------------------

// Other Functions