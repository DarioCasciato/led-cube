// =============================================================================
// Template-Project | Blink
// =============================================================================

#include <Arduino.h>
#include "Modes.h"

#define RED 0
#define GREEN 1
#define BLUE 2
#define WHITE 3

constexpr uint8_t redLayer[6][6] = {
    {RED, RED, RED, RED, RED, RED},
    {RED, RED, RED, RED, RED, RED},
    {RED, RED, RED, RED, RED, RED},
    {RED, RED, RED, RED, RED, RED},
    {RED, RED, RED, RED, RED, RED},
    {RED, RED, RED, RED, RED, RED}
};

constexpr uint8_t greenLayer[6][6] = {
    {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN},
    {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN},
    {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN},
    {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN},
    {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN},
    {GREEN, GREEN, GREEN, GREEN, GREEN, GREEN}
};

void drawLayer(uint8_t layerNumber, uint8_t array[6][6]);



void Mode::blink()
{
    drawLayer(0, redLayer);
    drawLayer(1, greenLayer);
    drawLayer(2, redLayer);
    drawLayer(3, greenLayer);
    drawLayer(4, redLayer);
    drawLayer(5, greenLayer);
}



if(color == GREEN)
{

}