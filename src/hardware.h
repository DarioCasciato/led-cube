// =============================================================================
// Template-Project | Hardware
// =============================================================================

#ifndef _TEMPLATE_PROJECT_HARDWARE_
#define _TEMPLATE_PROJECT_HARDWARE_

#include "configurations.h"
#include "gpio.h"
#include "EdgeDetection.h"
//#include <BluetoothSerial.h>


namespace Hardware
{
    // Port definitions
    /*enum class Port : uint8_t
    {
        // Buttons and LEDs
        modeButton =    9,
        btn1 =          7,
        stateLED =      5,

        // Shift register pins
        nSRCLR =        2,  // Storage register clear
        SRCLK =         4, // Storage register clock
        RCLK =          6, // Register clock
        nRCLR =         8,  // Register clear
        SER =           10,  // Serial input
        OE =            20, // Output enable
    };*/
    enum class Port : uint8_t
    {
        // Buttons and LEDs
        modeButton =    (uint8_t)myGPIO::Port::D34,
        btn1 =          (uint8_t)myGPIO::Port::D35,
        stateLED =      (uint8_t)myGPIO::Port::D25,

        // Shift register pins
        nSRCLR =        (uint8_t)myGPIO::Port::D5,  // Storage register clear
        SRCLK =         (uint8_t)myGPIO::Port::D17, // Storage register clock
        RCLK =          (uint8_t)myGPIO::Port::D16, // Register clock
        nRCLR =         (uint8_t)myGPIO::Port::D4,  // Register clear
        SER =           (uint8_t)myGPIO::Port::D2,  // Serial input
        OE =            (uint8_t)myGPIO::Port::D15, // Output enable
    };

    //extern BluetoothSerial SerialBT;

    extern EdgeDetection modeButton;
    extern EdgeDetection btn1;

    /// @brief Initializes hardware
    void init();

    /// @brief Fetches hardware values
    void updateHardware();
} // namespace Hardware


#endif // _TEMPLATE_PROJECT_HARDWARE_