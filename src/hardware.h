// =============================================================================
// Template-Project | Hardware
// =============================================================================

#ifndef _TEMPLATE_PROJECT_HARDWARE_
#define _TEMPLATE_PROJECT_HARDWARE_

#include "configurations.h"
#include "gpio.h"
#include "EdgeDetection.h"
#include <BluetoothSerial.h>


namespace Hardware
{
    // Port definitions
    enum class Port : uint8_t
    {
        // Buttons and LEDs
        btn0 =      (uint8_t)myGPIO::Port::D34,
        btn1 =      (uint8_t)myGPIO::Port::D35,
        stateLED =  (uint8_t)myGPIO::Port::D25,

        // Shift register pins
        nSRCLR =    (uint8_t)myGPIO::Port::D5,
        SRCLK =     (uint8_t)myGPIO::Port::D17,
        RCLK =      (uint8_t)myGPIO::Port::D16,
        nRCLR =     (uint8_t)myGPIO::Port::D4,
        SER =       (uint8_t)myGPIO::Port::D2,
        OE =        (uint8_t)myGPIO::Port::D15,
    };

    extern BluetoothSerial SerialBT;

    extern EdgeDetection btn0;
    extern EdgeDetection btn1;

    /// @brief Initializes hardware
    void init();

    /// @brief Fetches hardware values
    void updateHardware();
} // namespace Hardware


#endif // _TEMPLATE_PROJECT_HARDWARE_