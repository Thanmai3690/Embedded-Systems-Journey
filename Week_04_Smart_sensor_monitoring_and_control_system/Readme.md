# Week 4 — Smart Sensor Monitoring & Control System

## 📌 Project Overview

This project is a Smart Sensor Monitoring and Control System developed using an Arduino Uno and the Wokwi simulator.

The system uses a potentiometer to simulate a sensor input. Based on the sensor value, the system classifies the condition into three levels:

- 🟢 SAFE
- 🟡 WARNING
- 🔴 DANGER

The corresponding LED is activated based on the detected condition. A buzzer is also activated when the system enters the DANGER state.

The project demonstrates how sensor data can be processed using Embedded C and used to control multiple outputs.

---

## 🎯 Objective

The main objectives of this project are:

- Understand analog sensor input.
- Read sensor values using `analogRead()`.
- Process sensor data using conditional logic.
- Classify sensor values into different states.
- Control multiple LEDs based on sensor conditions.
- Control a buzzer during dangerous conditions.
- Use functions to organize the program.
- Use arrays for managing multiple outputs.
- Display sensor values and system status through the Serial Monitor.
- Understand basic sensor monitoring and control logic.

---

## 🛠️ Platform

- Arduino Uno
- ATmega328P Microcontroller
- Wokwi Simulator
- Arduino C/C++

---

## 🔧 Components Used

- Arduino Uno
- Potentiometer
- Green LED
- Yellow LED
- Red LED
- 3 × 220Ω Resistors
- Buzzer
- Jumper Wires

---

## 🔌 Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Potentiometer | A0 |
| 🟢 Green LED | D8 |
| 🟡 Yellow LED | D9 |
| 🔴 Red LED | D10 |
| 🔔 Buzzer | D11 |

The potentiometer is connected to the analog input pin A0 and is used to simulate changing sensor values.

---

## ⚙️ Working Principle

The potentiometer provides an analog value between 0 and 1023.

The Arduino reads this value and classifies the system condition based on predefined thresholds.

### 🟢 SAFE

```text
Sensor Value: 0 – 300

```
[Open Wokwi Simulation](https://wokwi.com/projects/473880109537800193)