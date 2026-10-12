# 🔐 Digital Door Lock System

## 📌 Project Overview

The Digital Door Lock System is an embedded systems project developed using an Arduino Uno, a 4×4 membrane keypad, LEDs, a buzzer, and a servo motor.

The system allows users to unlock a door by entering a predefined four-character password through the keypad. If the entered password is correct, the green LED turns ON and the servo motor unlocks the door. After three seconds, the servo returns to its locked position.

If the entered password is incorrect, the red LED turns ON and the buzzer sounds for three seconds to indicate denied access.

This project demonstrates how an embedded system can combine user input, decision-making, output control, and motor movement.

## 🎯 Objectives

- Interface a 4×4 membrane keypad with an Arduino Uno.
- Accept and store a four-character password.
- Compare the entered password with the predefined password.
- Control LEDs based on password verification.
- Generate an audible alert for incorrect passwords.
- Control a servo motor to simulate door locking and unlocking.
- Display system status through the Serial Monitor.
- Practice modular programming using functions.

## 🛠️ Components Required

| Component | Quantity |
|---|---:|
| Arduino Uno | 1 |
| 4×4 Membrane Keypad | 1 |
| Green LED | 1 |
| Red LED | 1 |
| 220Ω Resistors | 2 |
| Buzzer | 1 |
| Servo Motor | 1 |
| Breadboard | 1 |
| Jumper Wires | As required |

## 🔌 Circuit Connections

### 1. Keypad Connections

| Keypad Pin | Arduino Pin |
|---|---|
| Pin 1 | D2 |
| Pin 2 | D3 |
| Pin 3 | D4 |
| Pin 4 | D5 |
| Pin 5 | D6 |
| Pin 6 | D7 |
| Pin 7 | D8 |
| Pin 8 | D9 |

### 2. LED Connections

| Component | Arduino Connection |
|---|---|
| Green LED | D10 through a 220Ω resistor |
| Red LED | D11 through a 220Ω resistor |

Connect the other side of each LED circuit to GND.

### 3. Buzzer Connection

| Buzzer Pin | Arduino Connection |
|---|---|
| Positive (+) | D12 |
| Negative (-) | GND |

### 4. Servo Motor Connections

| Servo Wire | Arduino Connection |
|---|---|
| Signal | D13 |
| VCC | 5V |
| GND | GND |

**Note:** Ensure the servo receives an adequate power supply. If using an external supply, connect its GND to Arduino GND.

## ⚙️ Working Principle

The system operates through the following steps:

1. **System Initialization:** The Arduino initializes the keypad, LEDs, buzzer, and servo motor. The servo starts at the locked position.
2. **Password Input:** The user enters four characters using the keypad.
3. **Password Storage:** The entered characters are stored in a character array.
4. **Password Verification:** The `strcmp()` function compares the entered password with the predefined password.
5. **Correct Password:** The green LED turns ON, and the servo moves to 90°, simulating an unlocked door.
6. **Automatic Relocking:** After three seconds, the servo returns to 0°, and the green LED turns OFF.
7. **Incorrect Password:** The red LED turns ON, and the buzzer sounds for three seconds. The servo remains in the locked position.
8. **Reset:** The password input index resets, allowing the user to make another attempt.

## 🔄 System Flow

```text
              Start
                |
                v
       Initialize Components
                |
                v
       Enter 4-Character Password
                |
                v
        Store Entered Password
                |
                v
        Compare with Stored Password
                |
          +-----+-----+
          |           |
       Correct      Incorrect
          |           |
          v           v
     Green LED     Red LED ON
         ON        Buzzer ON
          |           |
          v           v
     Servo to 90°  Access Denied
          |           |
          v           v
      Wait 3 sec   Wait 3 sec
          |           |
          v           v
     Servo to 0°   Outputs OFF
          |           |
          +-----+-----+
                |
                v
        Reset Password Input
                |
                v
         Ready for Next Attempt