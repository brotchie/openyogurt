/*
 
 Copyright (C) 2012 James Brotchie

 This file is part of open-yogurt, an open-source design
 for an automated yoghurt maker:

    https://github.com/brotchie/openyogurt

*/

#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal_I2C.h>

#include "PowerRelay.h"
#include "Joystick.h"

/*
 * DEVICE SETUP
 */
#define ONEWIRE_BUS_DPIN 4
#define TEMPERATURE_RESOLUTION 12

#define POWER_RELAY_DPIN 5

#define JOYSTICK_XAXIS_APIN 0
#define JOYSTICK_YAXIS_APIN 1
#define JOYSTICK_ZAXIS_APIN 2

/* OneWire Temperature Sensor. */
OneWire oneWire(ONEWIRE_BUS_DPIN);
DallasTemperature sensors(&oneWire);
DeviceAddress thermometer;

/* I2C LCD */
LiquidCrystal_I2C lcd(0x27,16,2); // set the LCD address to 0x27

/* Power Relay */
PowerRelay relay(POWER_RELAY_DPIN);

/* Control Joystick */
Joystick joystick(JOYSTICK_XAXIS_APIN, JOYSTICK_YAXIS_APIN, JOYSTICK_ZAXIS_APIN);

void setup_temp_sensor(void);

void setup(void)
{
    Serial.begin(9600);
    Serial.println("OpenYogurt");

    relay.init();

    lcd.init();
    lcd.backlight();
    lcd.print("Hello World");

    setup_temp_sensor();
}

void setup_temp_sensor(void)
{
    sensors.begin();
    sensors.getAddress(thermometer, 0);
    sensors.setResolution(thermometer, TEMPERATURE_RESOLUTION);
}

void loop(void)
{
    sensors.requestTemperatures();
    joystick.update();

    float tempC = sensors.getTempC(thermometer); 
    lcd.clear();
    lcd.print(tempC);
    lcd.setCursor(0, 1);
    lcd.print(joystick);
}
