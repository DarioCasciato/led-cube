// =============================================================================
// Template-Project | State
// =============================================================================

#ifndef _TEMPLATE_PROJECT_STATE_
#define _TEMPLATE_PROJECT_STATE_

#include "hardware.h"

namespace State
{
    enum States : uint8_t
    {
        st_blink,
        st_random,
        st_test,

        NUM_STATES
    };

    /// @brief State driver function
    void stateDriver();
} // namespace State

#endif // _TEMPLATE_PROJECT_STATE_