ARDUINO_LIBS = LiquidCrystal_I2C OneWire DallasTemperature Wire Wire/utility

ARDUINO_MK_DIR = contrib/Arduino-Makefile/
ARDUINO_DIR = $(HOME)/contrib/arduino-1.0/
PARSE_BOARD = $(ARDUINO_MK_DIR)/arduino-mk/ard-parse-boards
AVR_TOOLS_PATH = /usr/bin
AVRDUDE = $(ARDUINO_DIR)/hardware/tools/avrdude
AVRDUDE_CONF = $(ARDUINO_DIR)/hardware/tools/avrdude.conf

BOARD_TAG    = uno
ARDUINO_PORT = /dev/ttyACM0

include $(ARDUINO_MK_DIR)/arduino-mk/Arduino.mk
