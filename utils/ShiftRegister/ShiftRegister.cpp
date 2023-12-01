// =========================================
// Utils | LED_RGB
// =========================================

#include "ShiftRegister.h"


ShiftRegister::ShiftRegister(uint8_t pin_data,
                             uint8_t pin_clock,
                             uint8_t pin_clear,
                             uint8_t pin_sClock,
                             uint8_t pin_sClear)
{
    pin_data_ = pin_data;
    pin_clock_ = pin_clock;
    pin_clear_ = pin_clear;
    pin_sClock_ = pin_sClock;
    pin_sClear_ = pin_sClear;

    pinMode(pin_data_, OUTPUT);
    pinMode(pin_clock_, OUTPUT);
    pinMode(pin_clear_, OUTPUT);
    pinMode(pin_sClock_, OUTPUT);
    pinMode(pin_sClear_, OUTPUT);

    digitalWrite(pin_data_, LOW);
    digitalWrite(pin_clock_, LOW);
    digitalWrite(pin_clear_, HIGH);
    digitalWrite(pin_sClock_, LOW);
    digitalWrite(pin_sClear_, HIGH);
}

void ShiftRegister::set()
{
    digitalWrite(pin_clock_, HIGH);
    coolDown();
    digitalWrite(pin_clock_, LOW);
}

void ShiftRegister::write(bool data)
{
    digitalWrite(pin_data_, data);
    coolDown();
    sClock();
    digitalWrite(pin_data_, LOW);
}

void ShiftRegister::clear()
{
    digitalWrite(pin_clear_, LOW);
    coolDown();
    digitalWrite(pin_clear_, HIGH);
}

void ShiftRegister::clearStorage()
{
    digitalWrite(pin_sClear_, LOW);
    coolDown();
    digitalWrite(pin_sClear_, HIGH);
}


void ShiftRegister::sClock()
{
    digitalWrite(pin_sClock_, HIGH);
    coolDown();
    digitalWrite(pin_sClock_, LOW);
}