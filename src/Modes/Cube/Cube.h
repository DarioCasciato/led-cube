// =========================================
// Utils | Cube
// =========================================

#include <Arduino.h>
#include "../Utils/ShiftRegister/ShiftRegister.h"

#ifndef ARDUINO_OBJECTS_CUBE_
#define ARDUINO_OBJECTS_CUBE_

class Cube
{

public:
    /// @brief Cube constructor
    ///
    /// @param pin_data Pin number for the data pin
    /// @param pin_clock Pin number for the output register clock pin
    /// @param pin_clear Pin number for the output register clear pin
    /// @param pin_sClock Pin number for the storage clock pin
    /// @param pin_sClear Pin number for the storage clear pin
    Cube(uint8_t pin_data,
         uint8_t pin_clock,
         uint8_t pin_clear,
         uint8_t pin_sClock,
         uint8_t pin_sClear);

    /// @brief Draw a layer of the cube
    ///
    /// @param layer Layer to draw
    /// @param data Data to draw
    void drawLayer(uint8_t layer, uint8_t data[6][6]);

    void drawCube(uint8_t layer0[6][6],
                  uint8_t layer1[6][6],
                  uint8_t layer2[6][6],
                  uint8_t layer3[6][6],
                  uint8_t layer4[6][6],
                  uint8_t layer5[6][6]);

    void setCubeColor(uint8_t color);

    /// @brief Clear the cube
    void clear();

private:
    uint8_t pin_data_;
    uint8_t pin_clock_;
    uint8_t pin_clear_;
    uint8_t pin_sClock_;
    uint8_t pin_sClear_;

    ShiftRegister SR;

    void writeAddress(uint8_t address);
    void writeColor(uint8_t color);
};

#endif // ARDUINO_OBJECTS_CUBE_