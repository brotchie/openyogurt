/*
 
 Copyright (C) 2012 James Brotchie

 This file is part of open-yogurt, an open-source design
 for an automated yoghurt maker:

    https://github.com/brotchie/openyogurt

*/

#ifndef __INCLUDE_POWER_RELAY_H
#define __INCLUDE_POWER_RELAY_H

/* Power relay is active low. */
#define POWER_RELAY_ON LOW
#define POWER_RELAY_OFF HIGH

class PowerRelay {
public:
    PowerRelay(uint8_t pin) : _pin(pin) {}

    void init() {
        /* Always starts in the off state. */
        off();
        pinMode(_pin, OUTPUT);
    }
    void on() { digitalWrite(_pin, POWER_RELAY_ON); }
    void off() { digitalWrite(_pin, POWER_RELAY_OFF); }
    
private:
    uint8_t _pin;
};

#endif
