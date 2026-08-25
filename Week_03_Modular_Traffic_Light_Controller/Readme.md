# 🚦 Week 3 - Modular Traffic Light Controller

## 📌 Project Overview

This project is a Modular Traffic Light Controller built using an Arduino Uno, three LEDs, resistors, and a breadboard.

The main objective of this project is to understand how functions can be used to organize embedded system code. Instead of writing all LED control logic directly inside the `loop()` function, separate functions are created for each traffic light state.

The traffic light follows the sequence:

🔴 Red → 🟡 Yellow → 🟢 Green → 🟢 Green Blinks 3 Times → 🔴 Red

The cycle then repeats continuously.

---

## 🎯 Objective

The objective of this project is to:

- Understand user-defined functions
- Practice `void` functions
- Understand function calls
- Learn modular programming
- Control multiple LEDs using separate functions
- Use a `for` loop to create a blinking effect
- Understand the role of `setup()` and `loop()` in Arduino programming

---

## 🛠️ Components Used

Arduino Uno 
Red LED 
Yellow LED 
Green LED 
220Ω Resistor 
Breadboard
Jumper Wires

---

## 🔌 Pin Connections

| LED | Arduino Pin |
|-----|-------------|
| 🔴 Red LED | Pin 8 |
| 🟡 Yellow LED | Pin 9 |
| 🟢 Green LED | Pin 10 |

The cathode of each LED is connected to GND through the circuit connection, and each LED uses a resistor for current limiting.

---

## ⚙️ Working Principle

The Arduino continuously controls the three LEDs to simulate a traffic light.

### 1. Red Light State

- Red LED turns ON
- Yellow LED turns OFF
- Green LED turns OFF
- The system remains in this state for 4 seconds

### 2. Yellow Light State

- Red LED turns OFF
- Yellow LED turns ON
- Green LED turns OFF
- The system remains in this state for 2 seconds

### 3. Green Light State

- Red LED turns OFF
- Yellow LED turns OFF
- Green LED turns ON
- The system remains in this state for 4 seconds

### 4. Green Blinking State

Before changing back to the red light, the green LED blinks 3 times.

Each blink consists of:

Green ON → 500 ms  
Green OFF → 500 ms

After the blinking sequence is completed, the program returns to the red light state and the cycle repeats.

---

## 🧩 Functions Used

### `redLight()`

Controls the red traffic light state.

```text
Red LED    → ON
Yellow LED → OFF
Green LED  → OFF

[Open Wokwi Simulation](https://wokwi.com/projects/473142524392233985)