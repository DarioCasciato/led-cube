// =========================================
// Utils | Cube
// =========================================

#include "Cube.h"

Cube::Cube(uint8_t pin_data,
           uint8_t pin_clock,
           uint8_t pin_clear,
           uint8_t pin_sClock,
           uint8_t pin_sClear)
    : SR(pin_data, pin_clock, pin_clear, pin_sClock, pin_sClear)  // Using initializer list
{
}

void Cube::drawLayer(uint8_t layer, uint8_t data[6][6])
{
    // layer are the first 3 bits that have to be set
    writeAddress(layer);

    for (uint8_t i = 0; i < 6; i++)
    {
        for (uint8_t j = 0; j < 6; j++)
        {
            writeColor(data[i][j]);
        }
    }
    SR.set();
}

void Cube::drawCube(uint8_t layer0[6][6],
                    uint8_t layer1[6][6],
                    uint8_t layer2[6][6],
                    uint8_t layer3[6][6],
                    uint8_t layer4[6][6],
                    uint8_t layer5[6][6])
{
    drawLayer(0, layer0);
    drawLayer(1, layer1);
    drawLayer(2, layer2);
    drawLayer(3, layer3);
    drawLayer(4, layer4);
    drawLayer(5, layer5);
}

void Cube::setCubeColor(uint8_t color)
{
    // layer are the first 3 bits that have to be set
    for (uint8_t i = 0; i < 6; i++)
    {
        writeAddress(i);

        for (uint8_t j = 0; j < 36; j++)
        {
            writeColor(color);
        }
        SR.set();
    }
}

void Cube::clear()
{
    SR.clear();
}


void Cube::writeAddress(uint8_t address)
{
    SR.clearStorage();

    SR.write(1); // first bit has to be set, for G2

    // layer are the first 3 bits that have to be set
    for (uint8_t i = 2; i >= 0; i--)
    {
        SR.write((address & (1 << i)) ? 1 : 0); // reads the 3 bits individually
    }
}

void Cube::writeColor(uint8_t color)
{
    // color are the last 3 bits that have to be set
    for (uint8_t i = 2; i >= 0; i--)
    {
        SR.write((color & (1 << i)) ? 1 : 0); // reads the 3 bits individually
    }
}