# Smart Parking Occupancy Detection System

## Overview
This project is an Arduino-based **Smart Parking Occupancy Detection System** that uses **two ultrasonic sensors** (entry and exit), a **servo motor** as a barrier gate, and **LEDs + buzzer** for status indication. The system counts cars entering and exiting a parking lot, automatically controlling the barrier and signaling when the lot is full.

## Features
- Detects cars at **entry and exit gates** using ultrasonic sensors.
- **Barrier gate (servo motor)** opens/closes automatically.
- **Car counter** tracks the number of vehicles inside.
- **LED indicators**:
  - Green LED → Parking available.
  - Red LED → Parking full or exit blocked.
- **Buzzer alert** when parking is full.
- Configurable maximum capacity (`maxCars`).

## Components Required
- Arduino Uno (or compatible board)
- 2 × Ultrasonic Sensor (HC-SR04)
- 1 × Micro Servo Motor (SG90)
- 1 × Buzzer
- 2 × LEDs (Red & Green)
- 2 × 220Ω resistors (for LEDs)
- Breadboard & jumper wires
- Power supply (USB or adapter)

## Circuit Connections
- **Ultrasonic Entry Sensor**: TRIG → D9, ECHO → D10
- **Ultrasonic Exit Sensor**: TRIG → D11, ECHO → D12
- **Servo Motor**: Signal → D5, VCC → 5V, GND → GND
- **Buzzer**: Positive → D8, Negative → GND
- **Red LED**: Anode → D6 (via resistor), Cathode → GND
- **Green LED**: Anode → D7 (via resistor), Cathode → GND

## Code
The full Arduino sketch is included in `parking_system.ino`.  
Key logic:
- Entry sensor increments car count.
- Exit sensor decrements car count.
- Barrier opens if space is available, closes otherwise.
- LEDs and buzzer provide real-time feedback.

## Usage
1. Upload the code to Arduino.
2. Connect components as per circuit diagram.
3. Start simulation in Tinkercad or test on hardware.
4. Observe barrier, LEDs, and buzzer responding to car detection.

## Future Improvements
- Add LCD/7-segment display for live car count.
- Integrate IoT (ESP8266/ESP32) for remote monitoring.
- Use magnetic or camera-based sensors for higher accuracy.
