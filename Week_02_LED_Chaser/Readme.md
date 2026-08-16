# Week 2 — LED Chaser

## Project Overview

This is the second project of my one-year Embedded Systems learning journey. The project demonstrates sequential control of six LEDs using an Arduino Uno. The LEDs create a chaser effect with changing speed, reverse movement, and a final ping-pong pattern. The circuit was designed and successfully tested using the Wokwi Arduino simulator.

## Objective

The main objectives of this project are:

- Control multiple LEDs using digital GPIO pins.
- Use `for` loops for sequential LED control.
- Understand forward and reverse iteration.
- Control LED timing using variables and `delay()`.
- Implement acceleration and deceleration.
- Implement a ping-pong LED pattern.
- Improve understanding of Arduino program structure.

## Platform

- Arduino Uno
- ATmega328P Microcontroller
- Wokwi Simulator
- Arduino C/C++

## Components

- Arduino Uno
- 6 LEDs
- 6 × 220Ω Resistors
- Jumper Wires

## Circuit

Six LEDs are connected to digital pins 2–7 of the Arduino Uno. Each LED is connected through a 220Ω resistor.

```text
Arduino Uno Pin 2
       |
     220Ω
       |
      LED 1
       |
      GND

Arduino Uno Pin 3
       |
     220Ω
       |
      LED 2
       |
      GND

Arduino Uno Pin 4
       |
     220Ω
       |
      LED 3
       |
      GND

Arduino Uno Pin 5
       |
     220Ω
       |
      LED 4
       |
      GND

Arduino Uno Pin 6
       |
     220Ω
       |
      LED 5
       |
      GND

Arduino Uno Pin 7
       |
     220Ω
       |
      LED 6
       |
      GND
```
## Wokwi Simulation

[Open the LED Chaser simulation in Wokwi](https://wokwi.com/projects/472508846074874881)
