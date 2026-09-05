# Design and Implementation of a Timed Traffic Signal System Using Arduino

### A First-Year BSIT Culminating Project

---

## 📌 Project Overview

**Design and Implementation of a Timed Traffic Signal System Using Arduino** is a completed first-year culminating project developed as part of the **Bachelor of Science in Information Technology (BSIT)** program.

The project demonstrates the application of fundamental concepts learned during the first year of study, particularly **programming, digital logic, sequential systems, embedded systems, problem-solving, hardware implementation, testing, and debugging**.

The completed system implements a timed traffic signal controller using an **Arduino Uno**, three LEDs representing the traffic signals, and a **7-segment display** for the countdown timer.

The traffic signal operates through a predefined sequence of three states:

```text
RED → YELLOW → GREEN → RED → ...
```

Each state has a specific duration and is controlled by the Arduino through programmed sequential logic.

---

# 🎓 Project Context

This project was created as part of the **completion of the first year of the Bachelor of Science in Information Technology (BSIT) program**.

As a culminating project, it brings together the foundational knowledge and technical skills developed throughout the first year.

The completed project demonstrates the ability to:

* Analyze a technical problem
* Design a logical solution
* Apply digital logic concepts
* Program a microcontroller
* Connect and control electronic components
* Implement a sequential system
* Test system behavior
* Troubleshoot hardware and software issues
* Document a completed technical project

The project therefore serves as a practical demonstration of the student's first-year learning experience in BSIT.

---

# 🎯 Project Objectives

The completed project achieved the following objectives:

* Designed a timed traffic signal system using an Arduino Uno.
* Implemented a state-based traffic-light sequence.
* Applied sequential digital logic concepts.
* Controlled Red, Yellow, and Green LEDs through the Arduino.
* Implemented a countdown timer using a 7-segment display.
* Eliminated the need for external integrated circuits for the main control logic.
* Demonstrated the traffic signal sequence through simulation and/or physical hardware.
* Tested the timing, LED outputs, countdown display, and state transitions.
* Documented the complete system and its implementation.

---

# ⚙️ System Description

The completed system is a **sequential state-based traffic signal controller**.

The Arduino Uno functions as the main controller and executes the programmed sequence continuously.

### System Flow

```text
        Arduino Uno
             │
             ▼
      State Controller
             │
     ┌───────┼────────┐
     ▼       ▼        ▼
    RED    YELLOW    GREEN
     │       │        │
     └───────┼────────┘
             │
             ▼
     7-Segment Countdown
```

The system does not require external physical input devices. The state transitions are controlled automatically according to the programmed timing.

---

# 🔄 Traffic Signal Sequence

The completed system uses three states.

| State  | Traffic Signal | Countdown             |  Duration |
| ------ | -------------- | --------------------- | --------: |
| **S0** | 🔴 Red         | 5 → 4 → 3 → 2 → 1 → 0 | 5 seconds |
| **S1** | 🟡 Yellow      | 2 → 1 → 0             | 2 seconds |
| **S2** | 🟢 Green       | 5 → 4 → 3 → 2 → 1 → 0 | 5 seconds |

The states continuously cycle:

```text
S0 → S1 → S2 → S0
```

Therefore:

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

# 🔢 Digital Logic Implementation

The system was designed using three logical states:

```text
S0 = Red State
S1 = Yellow State
S2 = Green State
```

The traffic-light outputs are represented by:

```text
R = S0
Y = S1
G = S2
```

Where:

```text
R = Red LED
Y = Yellow LED
G = Green LED
```

Each traffic-light output corresponds to its respective active state.

---

# 📊 State Table

The final state behavior is represented by the following table:

| State | Red | Yellow | Green |
| ----- | --: | -----: | ----: |
| S0    |   1 |      0 |     0 |
| S1    |   0 |      1 |     0 |
| S2    |   0 |      0 |     1 |

`1` indicates that the corresponding LED is ON, while `0` indicates that it is OFF.

---

# 🔌 Hardware Components

The completed project used the following components:

| Component         |    Quantity | Function                     |
| ----------------- | ----------: | ---------------------------- |
| Arduino Uno       |           1 | Main controller              |
| Breadboard        |           1 | Circuit assembly             |
| Red LED           |           1 | Stop indicator               |
| Yellow LED        |           1 | Caution indicator            |
| Green LED         |           1 | Go indicator                 |
| 7-Segment Display |           1 | Countdown display            |
| 220Ω Resistors    | As required | Current limiting             |
| Jumper Wires      |     Several | Electrical connections       |
| USB Cable         |           1 | Programming/power connection |

---

# 📍 Arduino Pin Configuration

## Traffic LEDs

| Component     | Arduino Pin |
| ------------- | ----------: |
| 🔴 Red LED    |      **13** |
| 🟡 Yellow LED |      **12** |
| 🟢 Green LED  |      **11** |

## 7-Segment Display

| Segment | Arduino Pin |
| ------- | ----------: |
| A       |       **2** |
| B       |       **3** |
| C       |       **4** |
| D       |       **5** |
| E       |       **6** |
| F       |       **7** |
| G       |       **8** |

The completed implementation used a **common-anode 7-segment display configuration**.

---

# 💻 Software Implementation

The system was programmed using the **Arduino IDE** and Arduino-compatible **C/C++ syntax**.

The source code was organized into several functions to make the program easier to understand and maintain.

### Main Functions

```text
setup()
resetLights()
clearDisplay()
displayDigit()
countdown()
loop()
```

---

## `setup()`

The `setup()` function initializes the Arduino pins and prepares the traffic LEDs and 7-segment display for operation.

It configures the required pins as outputs and ensures that the system starts in a known state.

---

## `resetLights()`

The `resetLights()` function turns off the traffic LEDs before activating the LED associated with the next state.

This prevents multiple traffic signals from remaining active at the same time.

---

## `clearDisplay()`

The `clearDisplay()` function turns off the 7-segment display segments when the countdown is not being displayed.

---

## `displayDigit()`

The `displayDigit()` function controls the individual segments of the 7-segment display to represent numerical values.

The function works with the digit mapping used by the common-anode display.

---

## `countdown()`

The `countdown()` function controls the countdown sequence for each traffic-light state.

The function:

1. Activates the selected traffic LED.
2. Displays the current countdown number.
3. Waits approximately one second.
4. Decreases the displayed number.
5. Continues until the countdown is complete.
6. Clears the display.

---

# 🔁 Program Execution

The completed program executes the traffic-light sequence continuously.

The main sequence is equivalent to:

```cpp
countdown(5, redled);
countdown(2, yellowled);
countdown(5, greenled);
```

This produces:

```text
┌─────────────────────────────┐
│       RED — 5 seconds       │
│       5 4 3 2 1 0           │
└──────────────┬──────────────┘
               ↓
┌─────────────────────────────┐
│     YELLOW — 2 seconds      │
│          2 1 0              │
└──────────────┬──────────────┘
               ↓
┌─────────────────────────────┐
│      GREEN — 5 seconds      │
│       5 4 3 2 1 0           │
└──────────────┬──────────────┘
               ↓
              RED
               ↓
             REPEAT
```

---

# 🧪 Testing and Verification

After implementation, the system was tested to verify whether the hardware and software operated according to the designed behavior.

## LED Output Testing

The Red, Yellow, and Green LEDs were tested to verify that the correct LED activated during each state.

### Expected Result

```text
S0 → Red ON
S1 → Yellow ON
S2 → Green ON
```

The state-based output behavior followed the designed sequence.

---

## 7-Segment Display Testing

The 7-segment display was tested to verify the countdown sequence.

### Red State

```text
5 → 4 → 3 → 2 → 1 → 0
```

### Yellow State

```text
2 → 1 → 0
```

### Green State

```text
5 → 4 → 3 → 2 → 1 → 0
```

The display was used as a visual representation of the remaining duration of the active state.

---

## ⏱️ Timing Testing

The programmed durations were verified according to the project design.

| State  | Target Duration |
| ------ | --------------: |
| Red    |       5 seconds |
| Yellow |       2 seconds |
| Green  |       5 seconds |

The timing sequence was successfully integrated with the LED and display behavior.

---

## 🔄 State Transition Testing

The complete sequence was tested to verify that the controller correctly moved between states.

```text
S0 → S1 → S2 → S0
```

The system returned to the Red state after completing the Green state, allowing continuous operation.

---

# 🐛 Debugging and Issues Encountered

During development and testing, several implementation issues were encountered and addressed.

### Wiring Issues

Incorrect or misplaced connections could cause LEDs or display segments to behave unexpectedly.

The wiring was checked against the defined Arduino pin configuration.

### 7-Segment Display Issues

Incorrect segment indexing or digit mapping could result in incorrect numbers being displayed.

The display mapping and corresponding Arduino connections were verified.

### Function and Sequence Issues

Incorrect function calls or sequencing could cause the traffic signals to activate incorrectly.

The state sequence and countdown function calls were checked to ensure the correct order:

```text
RED → YELLOW → GREEN
```

### Timing Considerations

The implementation uses `delay(1000)` for the one-second countdown interval.

Although this approach is simple and appropriate for the project's scope, `delay()` blocks normal program execution while waiting.

---

# ⚠️ Project Limitations

The completed project has a deliberately simple scope appropriate for a first-year BSIT culminating project.

Current limitations include:

* Fixed traffic-light durations.
* No vehicle-detection sensors.
* No pedestrian button.
* No pedestrian crossing signal.
* No buzzer.
* No wireless connectivity.
* No real-time traffic monitoring.
* Timing is implemented using `delay()`.

These limitations provide opportunities for future versions of the project.

---

# 🚀 Possible Future Improvements

Although the current project is complete, it can be expanded in future development.

### 1. Non-Blocking Timing

The `delay()`-based timing could be replaced with `millis()` to allow the Arduino to perform additional tasks while maintaining the traffic-light timing.

### 2. Pedestrian Crossing System

A push button and pedestrian signal could be added to allow pedestrians to request a crossing cycle.

### 3. Traffic Detection

Infrared or other sensors could be introduced to detect vehicles and dynamically modify the traffic sequence.

### 4. Warning Buzzer

A buzzer could be added to provide an audible warning during specific states.

### 5. IoT Integration

An ESP8266 or ESP32 could be used in a future version to provide:

* Wi-Fi connectivity
* Remote monitoring
* Online data collection
* Remote control
* Smart traffic-management features

These features are considered possible future improvements rather than requirements of the completed project.

---

# 📂 Repository Structure

The completed GitHub repository is organized as follows:

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
├── circuit/
│   ├── circuit-diagram.png
│   └── wiring-diagram.png
│
└── screenshots/
    ├── simulation.png
    └── final-output.png
```

---

# 📚 Technologies and Tools Used

| Technology / Tool       | Purpose                                          |
| ----------------------- | ------------------------------------------------ |
| **Arduino Uno**         | Microcontroller                                  |
| **Arduino IDE**         | Programming and uploading code                   |
| **Arduino C/C++**       | System programming                               |
| **7-Segment Display**   | Countdown output                                 |
| **LEDs**                | Traffic signal indicators                        |
| **Breadboard**          | Circuit prototyping                              |
| **Tinkercad / Proteus** | Circuit simulation                               |
| **GitHub**              | Source-code and project documentation management |

---

# 🎓 Skills Demonstrated

The completed project demonstrates the following first-year BSIT skills:

### Programming

* Arduino C/C++ programming
* Functions
* Variables
* Conditional logic
* Loops
* Digital output control

### Digital Logic

* Sequential systems
* State representation
* State transitions
* Truth tables
* Boolean expressions

### Hardware

* Arduino Uno
* LEDs
* Resistors
* 7-segment display
* Breadboard wiring
* Digital pins

### Problem-Solving

* Hardware troubleshooting
* Software debugging
* Display debugging
* Timing verification
* System testing

### Technical Documentation

* System design
* Hardware documentation
* Software documentation
* Testing documentation
* GitHub repository organization

---

# 📊 Final Project Summary

| Category                 | Final Implementation                                                     |
| ------------------------ | ------------------------------------------------------------------------ |
| **Project Title**        | Design and Implementation of a Timed Traffic Signal System Using Arduino |
| **Project Type**         | First-Year BSIT Culminating Project                                      |
| **Program**              | Bachelor of Science in Information Technology                            |
| **System Type**          | Sequential State-Based System                                            |
| **Microcontroller**      | Arduino Uno                                                              |
| **Programming Language** | Arduino C/C++                                                            |
| **Traffic States**       | Red → Yellow → Green                                                     |
| **Red Duration**         | 5 seconds                                                                |
| **Yellow Duration**      | 2 seconds                                                                |
| **Green Duration**       | 5 seconds                                                                |
| **Display**              | 7-Segment Display                                                        |
| **Logic Concept**        | Sequential Digital Logic                                                 |
| **Simulation**           | Tinkercad / Proteus                                                      |
| **Repository**           | GitHub                                                                   |

---

# ✅ Project Completion Status

The project has been completed according to its defined objectives.

### Completed Components

* [x] Project planning
* [x] System design
* [x] State definition
* [x] Digital logic design
* [x] Arduino programming
* [x] Traffic LED control
* [x] 7-segment countdown
* [x] State transitions
* [x] Timing implementation
* [x] System testing
* [x] Debugging
* [x] Technical documentation
* [x] GitHub project organization

---

# 🏁 Conclusion

**Design and Implementation of a Timed Traffic Signal System Using Arduino** was successfully developed as a **First-Year BSIT Culminating Project**.

The completed system demonstrates how foundational concepts from the first year of the BSIT program can be combined to create a functional embedded-system application.

By integrating an Arduino Uno, traffic LEDs, a 7-segment display, programmed timing, and sequential state logic, the project successfully demonstrates the relationship between **software, digital logic, and hardware**.

The project also provided practical experience in programming, circuit implementation, debugging, testing, and technical documentation.

Ultimately, the project represents the completion and practical application of the student's foundational first-year BSIT knowledge and skills.

---

## 👨‍💻 Project Information

**Project Title:**
Design and Implementation of a Timed Traffic Signal System Using Arduino

**Program:**
Bachelor of Science in Information Technology (BSIT)

**Project Classification:**
First-Year BSIT Culminating Project

**Project Status:**
**Completed**

**Primary Technology:**
Arduino Uno

**Academic Focus:**
Digital Logic, Programming, and Embedded Systems

---

> **A practical demonstration of first-year BSIT knowledge through programming, digital logic, hardware implementation, and problem-solving.**
