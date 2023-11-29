// =============================================================================
// Template-Project | Hardware
// =============================================================================

#include <Arduino.h>
#include "hardware.h"
#include "gpioHandler.h"

namespace Hardware
{
    BluetoothSerial SerialBT;

    uint8_t btn0State = false;
    EdgeDetection btn0(&btn0State);

    uint8_t btn1State = false;
    EdgeDetection btn1(&btn1State);


    void init()
    {
        pinMode((uint8_t)Port::btn0, INPUT);
        pinMode((uint8_t)Port::btn1, INPUT);
        pinMode((uint8_t)Port::stateLED, OUTPUT);

        myGPIO::setPort(Port::stateLED, false);
    }

    void updateHardware()
    {
        btn0State = myGPIO::getPort(Port::btn0);
        btn1State = myGPIO::getPort(Port::btn1);
    }
} // namespace Hardware