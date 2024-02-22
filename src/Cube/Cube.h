// =========================================
// Utils | Cube
// =========================================

#include <Arduino.h>
#include "../Utils/ShiftRegister/ShiftRegister.h"

#ifndef ARDUINO_OBJECTS_CUBE_
#define ARDUINO_OBJECTS_CUBE_


/*These defines are using binary literals (0bXXX) where XXX represents the state of the Blue, Red, and Green LEDs.
You can use these defines in your code to set the color of your LED by controlling the appropriate digital pins
connected to each color of the LED.*/

#define OFF____     0b000
#define BLUE___     0b001
#define RED____     0b010
#define MAGENTA     0b011
#define GREEN__     0b100
#define CYAN___     0b101
#define YELLOW_     0b110
#define WHITE__     0b111

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

    /// @brief Draw the whole cube
    ///
    /// @param layern Layer n
    void drawCube(uint8_t layer0[6][6],
                  uint8_t layer1[6][6],
                  uint8_t layer2[6][6],
                  uint8_t layer3[6][6],
                  uint8_t layer4[6][6],
                  uint8_t layer5[6][6]);

    /// @brief Set the color of the whole cube
    ///
    /// @param color Color to set
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

    /// @brief Write the address to the shift register
    ///
    /// @param address Address to write
    void writeAddress(uint8_t address);

    /// @brief Write the color to the shift register
    ///
    /// @param color Color to write
    void writeColor(uint8_t color);
};

namespace CB
{
    extern Cube cube; // Cube object
} // namespace CB

#endif // ARDUINO_OBJECTS_CUBE_