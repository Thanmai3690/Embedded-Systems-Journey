# 🚦 Monthly Challenge — Smart Traffic Signal System

## 📌 Project Overview

The Smart Traffic Signal System is a monthly Embedded Systems challenge project developed using an Arduino Uno and Embedded C.

The system simulates a smart traffic signal that dynamically adjusts the green-light duration based on traffic density. A potentiometer is used to simulate the traffic level, and the system changes the green-light duration according to the sensor value.

A buzzer is also activated during high traffic conditions to provide an alert.

This project combines concepts learned during the first four weeks of my Embedded Systems learning journey, including GPIO, analog input, arrays, functions, loops, conditional logic, and hardware control.

---

## 🎯 Objective

The main objectives of this project are:

- Understand GPIO control using an Arduino Uno.
- Read analog input using a potentiometer.
- Simulate traffic density using sensor values.
- Classify traffic into different levels.
- Dynamically control the green-light duration.
- Control multiple LEDs using Embedded C.
- Use a buzzer for high-traffic alerts.
- Apply arrays and functions in an embedded system.
- Understand software-to-hardware interaction.
- Build and test a complete embedded system on real hardware.

---

## 🛠️ Platform

- Arduino Uno
- ATmega328P Microcontroller
- Arduino IDE
- Arduino C/C++

---

## 🔧 Components Used

- Arduino Uno
- Red LED
- Yellow LED
- Green LED
- 3 × 220Ω Resistors
- Potentiometer
- Buzzer
- Breadboard
- Jumper Wires

---

## 🔌 Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Potentiometer | A0 |
| 🔴 Red LED | D8 |
| 🟡 Yellow LED | D9 |
| 🟢 Green LED | D10 |
| 🔔 Buzzer | D11 |

---

## ⚙️ Working Principle

The potentiometer is used to simulate traffic density.

The Arduino reads the analog value from the potentiometer and determines the traffic level.

### 🟢 Low Traffic

```text
Sensor Value: 0 – 300
Green Duration: 3 seconds
Buzzer: OFF
```

### 🟡 Medium Traffic

```text
Sensor Value: 301 – 700
Green Duration: 5 seconds
Buzzer: OFF
```

### 🔴 High Traffic
``text
Sensor Value: 701 – 1023
Green Duration: 8 seconds
Buzzer: ON

```

The traffic signal follows the sequence:

RED → GREEN → YELLOW → RED