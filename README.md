# MultiThermo

Arduino sketch for monitoring ambient and probe temperature.

## What it does

This sketch monitors uses two sensors to monitor the ambient temperature and humidity and the temperature of a probe. Readouts from these sensors can then be displayed on the LCD or retrieved over USB.

TL;DR: It's basically a fancy thermometer.

## Why make this

I used this to monitor the temperature difference between my room (ambient) and the inside of my PC case (probe).

Besides this it was an exercise on how to use DHT22/11 and DS18B20 temperature sensors and a fun little project.

## Components

Components needed to build this:

- Arduino (I'm using a Nano because of its size)
- DHT22 (AM2302) / DHT11 temperature / humidity sensor (ambient sensor)
- DS18B20 Digital Thermometer, optionally pre-wired & waterproofed (probe sensor)
- 16x2 I²C LCD
- 4.75k Ω resistor
- Momentary switch
- Optionally some (three-pin) connector for the probe (e.g. 3.5mm TRS or mini XLR)
- Enclosure, wires etc.

## Default pin layout

- Probe (DS18B20) - **D2**
- Ambient (DHT22) - **D3**
- LCD I²C SDA - **A4**
- LCD I²C SCL - **A5**
- Switch - **D4**

## Libraries

This sketch uses the following libraries:

- LiquidCrystal I2C
    - https://github.com/johnrickman/LiquidCrystal_I2C
    - https://www.arduinolibraries.info/libraries/liquid-crystal-i2-c
- DHT Sensor Library
    - https://github.com/adafruit/DHT-sensor-library
    - https://www.arduinolibraries.info/libraries/dht-sensor-library
- Arduino Temperature Control Library
    - https://github.com/milesburton/Arduino-Temperature-Control-Library
    - https://www.arduinolibraries.info/libraries/dallas-temperature
- OneWire
    - https://www.pjrc.com/teensy/td_libs_OneWire.html
    - https://www.arduinolibraries.info/libraries/one-wire

## Todo

- Implement switch (input pullup)
- Add schematic / circuit diagram
- Companion app (PC)