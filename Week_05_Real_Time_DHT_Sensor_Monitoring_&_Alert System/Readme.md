# Week 5 — Real-Time DHT Sensor Monitoring & Alert System

## 📌 Project Overview

This project is a Real-Time DHT Sensor Monitoring and Alert System developed using an Arduino Uno, DHT11 temperature and humidity sensor, LEDs, and a buzzer.

The system continuously reads real-time temperature and humidity values from the DHT11 sensor and generates a structured UART-style message containing the sensor readings and system status.

The generated message is then parsed to extract the temperature, humidity, and status information. Based on the parsed status, the system controls the LEDs and buzzer.

The system also stores sensor readings and provides historical analysis through commands entered in the Serial Monitor.

This project was completely developed and tested on real hardware using the Arduino IDE.

---

## 🎯 Objective

The main objectives of this project are:

- Read real-time temperature and humidity using a DHT11 sensor.
- Process sensor data using Embedded C.
- Generate structured sensor messages.
- Parse temperature, humidity, and status from a string.
- Control LEDs based on the parsed system status.
- Generate an alert using a buzzer during dangerous conditions.
- Store historical sensor readings using arrays.
- Generate reports from stored sensor data.
- Use functions for modular program organization.
- Communicate with the system through the Serial Monitor.
- Understand the interaction between sensors, software, and hardware.

---

## 🛠️ Platform

- Arduino Uno
- ATmega328P Microcontroller
- Arduino IDE
- Arduino C/C++
- DHT11 Sensor

---

## 🔧 Components Used

- Arduino Uno
- DHT11 3-Pin Sensor Module
- Green LED
- Yellow LED
- Red LED
- 3 × 220Ω Resistors
- Buzzer
- Breadboard
- Jumper Wires

---

## 🔌 Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| DHT11 Data | D2 |
| 🟢 Green LED | D8 |
| 🟡 Yellow LED | D9 |
| 🔴 Red LED | D10 |
| 🔔 Buzzer | D11 |

The DHT11 sensor is connected to the Arduino Uno to provide real-time temperature and humidity readings.

---

## ⚙️ Working Principle

The system follows the following process:

```text
DHT11 Sensor
      ↓
Read Temperature & Humidity
      ↓
Generate Status
      ↓
Create Structured Message
      ↓
Parse Message
      ↓
Extract Temperature / Humidity / Status
      ↓
Control LEDs & Buzzer
      ↓
Store Reading in History
      ↓
Generate Reports