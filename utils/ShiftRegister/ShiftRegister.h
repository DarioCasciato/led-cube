// =========================================
// Utils | ShiftRegister
// =========================================

#include <Arduino.h>
#include "../../src/configurations.h"

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

    /// @brief Set the output register
    void set();

    /// @brief Write a bit to the shift register
    ///
    /// @param data_ Bit to write
    void write(bool data_);

    /// @brief Clear the output register
    void clear();

    /// @brief Clear the storage register
    void clearStorage();

private:
    uint8_t pin_data_;
    uint8_t pin_clock_;
    uint8_t pin_clear_;
    uint8_t pin_sClock_;
    uint8_t pin_sClear_;

    const uint16_t delay = SR_DELAY; // delay in microseconds

    /// @brief Cool down the shift register
    //void coolDown() { delayMicroseconds(delay); };
    void coolDown() { return; };

    /// @brief Set the storage clock
    void sClock();
};



#endif // ARDUINO_OBJECTS_SHIFT_REGISTER_