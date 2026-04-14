# ⏰ PS6 – Smart Alarm Clock for Arduino

An embedded alarm clock system built with **Arduino Uno** and **PlatformIO**, featuring real-time clock support, alarm scheduling, timer mode, environmental monitoring, and persistent settings storage via EEPROM.

## Overview

This project implements a multifunctional digital clock designed for Arduino-based hardware.
It combines several modules into one embedded application:

* real-time clock display
* date display and editing
* alarm scheduling
* countdown timer
* temperature and humidity monitoring
* buzzer-based alarm notification
* EEPROM persistence for saved alarms and timers

The application is structured as a **finite state machine**, where each screen or mode is implemented as a separate state.

## Features

* Real-time clock using **DS1302 RTC**
* LCD interface using **16x2 I2C display**
* Alarm scheduling with stored settings
* Timer mode with countdown calculation
* Snooze support
* Temperature and humidity readings via **DHT11**
* EEPROM-based persistence for alarm and timer data
* Button-based navigation and editing
* Modular architecture with separated wrappers for LCD, RTC, and sensors

## Hardware Components

* Arduino Uno
* DS1302 RTC module
* DHT11 temperature and humidity sensor
* 16x2 I2C LCD display
* Buzzer
* 4 push buttons

## Software Stack

* C++
* Arduino framework
* PlatformIO

Libraries used:

* `RTC`
* `DHT sensor library`
* `Adafruit Unified Sensor`
* `LiquidCrystal_I2C`

## Project Structure

```text
ps6/
├── include/
│   ├── config.h
│   ├── lcd_wrapper.h
│   ├── rtc_wrapper.h
│   ├── sensors.h
│   └── states.h
├── lib/
│   └── helpers/
│       ├── helpers.cpp
│       └── helpers.h
├── src/
│   ├── main.cpp
│   ├── lcd_wrapper.cpp
│   ├── rtc_wrapper.cpp
│   ├── sensors.cpp
│   └── states.cpp
└── platformio.ini
```

## Architecture

The project is divided into several modules:

* `main.cpp` – initializes hardware and runs the main state machine
* `states.cpp` – implements all application states and alarm logic
* `rtc_wrapper.cpp` – provides a wrapper around the RTC module
* `lcd_wrapper.cpp` – handles LCD output
* `sensors.cpp` – reads temperature and humidity values
* `config.h` – stores pin mappings and configuration constants

## State Machine

The application is built around the following states:

* `CLOCK` – displays current time and allows time editing
* `SHOW_DATE` – displays date and allows date editing
* `SHOW_ENV` – displays temperature and humidity
* `ALARM` – shows and configures the saved alarm
* `TIMER` – manages a countdown timer

This approach keeps the UI logic organized and makes the system easier to extend.

## Alarm Logic

The alarm mode allows the user to:

* view the currently configured alarm
* set or update alarm time
* store alarm settings in EEPROM
* trigger a buzzer when the target time is reached
* snooze the alarm using button input

Alarm data is persisted in EEPROM, so settings can survive device restart.

## Timer Logic

The timer mode allows the user to:

* configure a relative countdown time
* calculate the future trigger time
* save the timer in EEPROM
* show the remaining time on the LCD
* trigger the same alarm behavior when the timer expires

## Environmental Monitoring

Using the DHT11 sensor, the project can display:

* current temperature
* current humidity

This extends the clock into a simple smart desk device rather than just a basic alarm clock.

## EEPROM Usage

EEPROM is used to persist state between restarts:

* alarm enabled flag
* alarm target time
* timer enabled flag
* timer target time

This improves usability and makes the project more realistic as an embedded system.

## How to Build and Upload

This project uses PlatformIO.

### Build

```bash
pio run
```

### Upload

```bash
pio run --target upload
```

### Monitor serial output

```bash
pio device monitor
```

## Controls

The project uses four hardware buttons for navigation and editing.

Typical actions include:

* switching between screens
* entering edit mode
* adjusting hours, minutes, and seconds
* confirming alarm or timer settings
* snoozing the alarm

## Learning Outcomes

This project demonstrates:

* embedded C++ development
* state machine design
* RTC integration
* LCD-based UI design
* sensor integration
* EEPROM persistence
* event-based alarm logic
* modular code organization for microcontroller projects

## Possible Improvements

* improve button debouncing
* unify naming conventions
* add better validation for RTC date/time setup
* support multiple alarms
* add a cleaner menu system
* add backlight timeout or low-power mode
* add sound patterns instead of simple buzzer toggling

## Author

**Yaroslav Shyshmylo**
GitHub: https://github.com/Yaroslav2705
