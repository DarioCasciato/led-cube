// =========================================
// Utils | LED_RGB
// =========================================

#include <Arduino.h>

#ifndef ARDUINO_OBJECTS_SHIFT_REGISTER_
#define ARDUINO_OBJECTS_SHIFT_REGISTER_

/// @brief ShiftRegister class
///
/// This class is used to control a shift register with a storage register.
class ShiftRegister
{

public:
    /// @brief ShiftRegister constructor
    ///
    /// @param pin_data Pin number for the data pin
    /// @param pin_clock Pin number for the output register clock pin
    /// @param pin_clear Pin number for the output register clear pin
    /// @param pin_sClock Pin number for the storage clock pin
    /// @param pin_sClear Pin number for the storage clear pin
    ShiftRegister(uint8_t pin_data,
                  uint8_t pin_clock,
                  uint8_t pin_clear,
                  uint8_t pin_sClock,
                  uint8_t pin_sClear);

    void set();

    void write(bool data);

    void clear();

    void clearStorage();

private:
    uint8_t pin_data_;
    uint8_t pin_clock_;
    uint8_t pin_clear_;
    uint8_t pin_sClock_;
    uint8_t pin_sClear_;

    const uint8_t delay = 10; // delay in microseconds
    void coolDown() { delayMicroseconds(delay); };

    void sClock();
};



#endif // ARDUINO_OBJECTS_SHIFT_REGISTER_