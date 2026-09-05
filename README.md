# Design and Implementation of a Timed Traffic Signal System Using Arduino

### A First-Year BSIT Culminating Project

---

## 📌 Project Overview

**Design and Implementation of a Timed Traffic Signal System Using Arduino** is a completed culminating project developed as part of the **Bachelor of Science in Information Technology (BSIT)** program.

The project demonstrates foundational first-year skills in **programming, digital logic, embedded systems, hardware implementation, testing, debugging, and problem-solving**.

The system uses an **Arduino Uno** to control three traffic LEDs and a **7-segment display** that shows the remaining time for each traffic-light state.

```text
RED → YELLOW → GREEN → RED → ...
```

Each state operates for a predefined duration and repeats continuously.

---

## 🎓 Project Context

This project was developed as part of the **completion of the first year of the BSIT program**.

It serves as a practical application of the technical concepts and skills learned during the first year, combining software programming with digital logic and physical hardware implementation.

---

## 🎯 Objectives

The project was designed to:

* Implement a timed traffic signal using an Arduino Uno.
* Apply sequential digital logic and state-based control.
* Control Red, Yellow, and Green LEDs.
* Implement a countdown timer using a 7-segment display.
* Test timing, outputs, and state transitions.
* Apply programming, hardware implementation, debugging, and problem-solving skills.

---

## ⚙️ System Description

The Arduino Uno serves as the main controller of the system. It executes a predefined sequence consisting of three states:

```text
S0 → S1 → S2 → S0

S0 = Red
S1 = Yellow
S2 = Green
```

The traffic LEDs and countdown display are updated according to the active state.

### System Flow

```text
             Arduino Uno
                  │
                  ▼
           State Controller
                  │
        ┌─────────┼─────────┐
        ▼         ▼         ▼
       RED      YELLOW     GREEN
        │         │         │
        └─────────┼─────────┘
                  ▼
         7-Segment Countdown
```

---

## 🔄 Traffic Signal Sequence

| State  | Signal    | Countdown             | Duration |
| ------ | --------- | --------------------- | -------: |
| **S0** | 🔴 Red    | 5 → 4 → 3 → 2 → 1 → 0 |    5 sec |
| **S1** | 🟡 Yellow | 2 → 1 → 0             |    2 sec |
| **S2** | 🟢 Green  | 5 → 4 → 3 → 2 → 1 → 0 |    5 sec |

The sequence continuously repeats:

```text
RED
 ↓
YELLOW
 ↓
GREEN
 ↓
RED
 ↓
REPEAT
```

---

## 🔢 Digital Logic

The system uses three logical states:

```text
S0 = Red State
S1 = Yellow State
S2 = Green State
```

The traffic outputs correspond to the active state:

```text
R = S0
Y = S1
G = S2
```

### State Table

| State  | Red | Yellow | Green |
| ------ | --: | -----: | ----: |
| **S0** |   1 |      0 |     0 |
| **S1** |   0 |      1 |     0 |
| **S2** |   0 |      0 |     1 |

`1` represents ON and `0` represents OFF.

---

## 🔌 Hardware Components

| Component         |    Quantity | Purpose                |
| ----------------- | ----------: | ---------------------- |
| Arduino Uno       |           1 | Main controller        |
| Breadboard        |           1 | Circuit assembly       |
| Red LED           |           1 | Stop indicator         |
| Yellow LED        |           1 | Caution indicator      |
| Green LED         |           1 | Go indicator           |
| 7-Segment Display |           1 | Countdown display      |
| 220Ω Resistors    | As required | Current limiting       |
| Jumper Wires      |     Several | Electrical connections |
| USB Cable         |           1 | Programming and power  |

---

## 📍 Arduino Pin Configuration

### Traffic LEDs

| Component     | Arduino Pin |
| ------------- | ----------: |
| 🔴 Red LED    |      **13** |
| 🟡 Yellow LED |      **12** |
| 🟢 Green LED  |      **11** |

### 7-Segment Display

| Segment | Arduino Pin |
| ------- | ----------: |
| A       |       **2** |
| B       |       **3** |
| C       |       **4** |
| D       |       **5** |
| E       |       **6** |
| F       |       **7** |
| G       |       **8** |

The implementation uses a **common-anode 7-segment display**.

---

## 💻 Software

The system was programmed using the **Arduino IDE** and Arduino-compatible **C/C++**.

### Main Functions

```text
setup()
resetLights()
clearDisplay()
displayDigit()
countdown()
loop()
```

The `countdown()` function coordinates the active traffic LED, displayed number, timing interval, and completion of each state.

The main sequence is:

```cpp
countdown(5, redled);
countdown(2, yellowled);
countdown(5, greenled);
```

---

## 🧪 Testing and Verification

The completed system was tested to verify:

* Correct LED activation.
* Correct countdown display.
* Correct timing duration.
* Correct state transitions.
* Continuous operation.

### Expected State Behavior

```text
S0 → Red ON
S1 → Yellow ON
S2 → Green ON
```

### Countdown Testing

```text
Red:     5 → 4 → 3 → 2 → 1 → 0
Yellow:  2 → 1 → 0
Green:   5 → 4 → 3 → 2 → 1 → 0
```

The complete state sequence was verified as:

```text
S0 → S1 → S2 → S0
```

---

## 🐛 Debugging

During development, hardware and software issues were addressed through:

* Checking LED and display wiring.
* Verifying Arduino pin assignments.
* Correcting 7-segment digit mappings.
* Checking state transitions.
* Verifying countdown behavior.
* Testing programmed timing.

These debugging activities helped ensure that the final system operated according to its design.

---

## ⚠️ Limitations

The completed system intentionally maintains a simple scope appropriate for a first-year BSIT project.

Current limitations include:

* Fixed traffic-light durations.
* No vehicle-detection sensors.
* No pedestrian controls.
* No wireless connectivity.
* No real-time traffic monitoring.
* Timing relies on `delay()`.

---

## 🚀 Future Improvements

Possible future versions could include:

* Non-blocking timing using `millis()`.
* Pedestrian crossing controls.
* Vehicle-detection sensors.
* Warning buzzer.
* ESP32/ESP8266 connectivity.
* Remote monitoring.
* Dynamic traffic-light timing.

These features are outside the scope of the completed project but provide opportunities for future development.

---

## 📂 Repository Structure

```text
arduino-timed-traffic-signal/
│
├── README.md
├── IMPLEMENTATION_PLAN.md
├── LICENSE
├── .gitignore
│
├── src/
│   └── traffic_signal/
│       └── traffic_signal.ino
│
├── docs/
│   ├── digital-logic.md
│   ├── hardware.md
│   └── testing.md
│
├── builders/
│   └── Meet the Team.png
│
├── Papers/
│   ├── Cover Page
│   ├── Table of Contents
│   └── Final Project Paper
│
└── screenshots/
    ├── simulation.png
    └── final-output.png
```

---

## 🛠️ Technologies and Tools

* **Arduino Uno**
* **Arduino IDE**
* **Arduino C/C++**
* **7-Segment Display**
* **LEDs**
* **Breadboard**
* **Tinkercad / Proteus**
* **GitHub**

---

## 🎓 Skills Demonstrated

### Programming

* C/C++ programming
* Functions
* Variables
* Loops
* Conditional logic
* Digital output control

### Digital Logic

* Sequential systems
* State representation
* State transitions
* Truth tables
* Boolean logic

### Hardware

* Arduino Uno
* LEDs and resistors
* 7-segment display
* Breadboard wiring
* Digital pins

### Problem-Solving

* Hardware troubleshooting
* Software debugging
* Timing verification
* System testing

### Documentation

* System design
* Hardware documentation
* Software documentation
* Testing documentation
* GitHub organization

---

## 📊 Final Project Summary

| Category             | Final Implementation                |
| -------------------- | ----------------------------------- |
| **Project Type**     | First-Year BSIT Culminating Project |
| **System Type**      | Sequential State-Based System       |
| **Microcontroller**  | Arduino Uno                         |
| **Language**         | Arduino C/C++                       |
| **Traffic Sequence** | Red → Yellow → Green                |
| **Red Duration**     | 5 seconds                           |
| **Yellow Duration**  | 2 seconds                           |
| **Green Duration**   | 5 seconds                           |
| **Display**          | 7-Segment Display                   |
| **Logic**            | Sequential Digital Logic            |
| **Simulation**       | Tinkercad / Proteus                 |
| **Status**           | **Completed**                       |

---

## 🏁 Conclusion

**Design and Implementation of a Timed Traffic Signal System Using Arduino** successfully demonstrates the practical application of foundational BSIT knowledge.

By combining **programming, sequential digital logic, Arduino hardware, LED control, countdown display, testing, and debugging**, the project provides a practical representation of the skills developed during the first year of the BSIT program.

It serves as a completed academic project demonstrating the integration of software and hardware to solve a simple real-world problem.

---

## 👨‍💻 Project Information

**Project Title:**
Design and Implementation of a Timed Traffic Signal System Using Arduino

**Program:**
Bachelor of Science in Information Technology (BSIT)

**Classification:**
First-Year BSIT Culminating Project

**Status:**
**Completed**

**Primary Technology:**
Arduino Uno

**Academic Focus:**
Programming, Digital Logic, and Embedded Systems

> **A practical demonstration of first-year BSIT knowledge through programming, digital logic, hardware implementation, and problem-solving.**
