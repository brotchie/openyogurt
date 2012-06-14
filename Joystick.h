/*
 
 Copyright (C) 2012 James Brotchie

 This file is part of open-yogurt, an open-source design
 for an automated yoghurt maker:

    https://github.com/brotchie/openyogurt

*/
#ifndef __INCLUDE_JOYSTICK_H
#define __INCLUDE_JOYSTICK_H

#include <Printable.h>

class Joystick : public Printable {
public:
    Joystick(uint8_t xpin, uint8_t ypin, uint8_t zpin) :
        _xpin(xpin), _ypin(ypin), _zpin(zpin) {};

    void update(void) {
        _lastx = analogRead(_xpin);
        _lasty = analogRead(_ypin);
        _lastz = analogRead(_zpin);
    }

    int x() const { return _lastx; }
    int y() const { return _lasty; }
    int z() const { return _lastz; }

    virtual size_t printTo(Print &print) const {
        String result("J(");
        result += x();
        result += ",";

        result += y();
        result += ",";

        result += z();
        result += ")";

        return print.print(result);
    }
private:
    uint8_t _xpin, _ypin, _zpin;
    int _lastx, _lasty, _lastz;
};

#endif
