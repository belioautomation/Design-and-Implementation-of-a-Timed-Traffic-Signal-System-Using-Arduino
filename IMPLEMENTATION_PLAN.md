# Implementation Plan

## Design and Implementation of a Timed Traffic Signal System Using Arduino

### First-Year BSIT Culminating Project

---

## 1. Project Introduction

The **Design and Implementation of a Timed Traffic Signal System Using Arduino** was developed as a first-year BSIT culminating project.

The implementation focused on combining basic programming, sequential digital logic, embedded-system concepts, and electronic hardware to create a functional automated traffic signal.

The completed system uses an **Arduino Uno**, three LEDs, and a 7-segment display to simulate a timed traffic-light sequence.

---

## 2. Implementation Goals

The implementation was planned around the following goals:

1. Design a simple automated traffic signal system.
2. Define the required traffic-light states.
3. Implement sequential state transitions.
4. Control traffic LEDs using Arduino digital pins.
5. Display countdown values using a 7-segment display.
6. Integrate timing with LED and display behavior.
7. Test and debug the complete system.
8. Document the final implementation.

---

## 3. System Architecture

The system was designed around the Arduino Uno as the central controller.

```text
                Arduino Uno
                     │
                     ▼
             State Controller
                     │
        ┌────────────┼────────────┐
        ▼            ▼            ▼
     Red LED     Yellow LED    Green LED
                     │
                     ▼
             7-Segment Display
```

The Arduino determines the active state and controls the corresponding outputs.

---

## 4. State Design

Three states were defined for the traffic signal:

```text
S0 = Red
S1 = Yellow
S2 = Green
```

The state transition sequence is:

```text
S0 → S1 → S2 → S0
```

### State Durations

| State | Signal |  Duration |
| ----- | ------ | --------: |
| S0    | Red    | 5 seconds |
| S1    | Yellow | 2 seconds |
| S2    | Green  | 5 seconds |

This sequence repeats continuously during system operation.

---

## 5. Hardware Implementation

The required components were selected based on the project's objectives and scope.

### Components

* Arduino Uno
* Breadboard
* Red LED
* Yellow LED
* Green LED
* Common-anode 7-segment display
* 220Ω resistors
* Jumper wires
* USB cable

### Pin Assignment

#### Traffic LEDs

```text
Red LED     → Pin 13
Yellow LED  → Pin 12
Green LED   → Pin 11
```

#### 7-Segment Display

```text
A → Pin 2
B → Pin 3
C → Pin 4
D → Pin 5
E → Pin 6
F → Pin 7
G → Pin 8
```

---

## 6. Digital Logic Implementation

The traffic signal was represented using three sequential states.

### State Table

| State | Red | Yellow | Green |
| ----- | --: | -----: | ----: |
| S0    |   1 |      0 |     0 |
| S1    |   0 |      1 |     0 |
| S2    |   0 |      0 |     1 |

Only one traffic LED is active at a time.

The state-based approach simplifies the control logic and makes the sequence easier to implement and troubleshoot.

---

## 7. Software Implementation

The system was programmed using **Arduino C/C++** through the **Arduino IDE**.

The program was divided into functions to make each part of the system easier to manage.

### Function Structure

```text
setup()
│
├── Configure pins
└── Initialize outputs

loop()
│
├── Red countdown
├── Yellow countdown
└── Green countdown
```

Supporting functions were implemented for:

```text
resetLights()
clearDisplay()
displayDigit()
countdown()
```

---

## 8. Traffic-Light Control

The `resetLights()` function was used to ensure that previous traffic-light outputs were turned off before activating the next state.

The intended behavior was:

```text
Red State:
Red ON
Yellow OFF
Green OFF

Yellow State:
Red OFF
Yellow ON
Green OFF

Green State:
Red OFF
Yellow OFF
Green ON
```

This prevents multiple traffic signals from being active simultaneously.

---

## 9. Countdown Display Implementation

The 7-segment display was configured to represent numerical countdown values.

The `displayDigit()` function controls the individual segments required to display each number.

The countdown behavior was designed as:

```text
Red:
5 → 4 → 3 → 2 → 1 → 0

Yellow:
2 → 1 → 0

Green:
5 → 4 → 3 → 2 → 1 → 0
```

The countdown provides a visual indication of the remaining duration of the active traffic state.

---

## 10. Timing Implementation

The initial implementation uses a one-second delay interval:

```cpp
delay(1000);
```

The countdown function decreases the displayed value approximately once every second.

The target timing is:

```text
Red     = 5 seconds
Yellow  = 2 seconds
Green   = 5 seconds
```

This approach was selected because it is straightforward and appropriate for the project's introductory scope.

---

## 11. Development and Assembly Process

The implementation followed a structured development process.

### Phase 1 — Planning

* Defined the project problem.
* Identified required components.
* Established traffic-light states.
* Defined timing requirements.

### Phase 2 — System Design

* Designed the state sequence.
* Created the state table.
* Assigned Arduino pins.
* Planned the 7-segment display connections.

### Phase 3 — Circuit Assembly

* Connected the Arduino Uno.
* Installed the traffic LEDs.
* Added current-limiting resistors.
* Connected the 7-segment display.
* Verified wiring against the pin configuration.

### Phase 4 — Programming

* Configured Arduino pins.
* Implemented LED control.
* Implemented 7-segment digit mapping.
* Created countdown functionality.
* Implemented the traffic-light sequence.

### Phase 5 — Testing

* Tested individual LEDs.
* Tested display digits.
* Tested countdown behavior.
* Verified timing.
* Verified state transitions.
* Tested continuous operation.

### Phase 6 — Debugging

Potential implementation issues were isolated by checking:

* Wiring connections.
* Pin assignments.
* LED states.
* Segment mappings.
* Function calls.
* Countdown logic.
* State order.

### Phase 7 — Documentation

The completed system was documented through:

* Project README.
* Implementation plan.
* Hardware documentation.
* Digital logic documentation.
* Testing documentation.
* Circuit diagrams.
* Simulation/final-output screenshots.

---

## 12. Testing Plan

Testing was performed according to the major system components.

### Test 1 — Red LED

**Input:** Red state activated.

**Expected Result:**

```text
Red ON
Yellow OFF
Green OFF
```

### Test 2 — Yellow LED

**Input:** Yellow state activated.

**Expected Result:**

```text
Red OFF
Yellow ON
Green OFF
```

### Test 3 — Green LED

**Input:** Green state activated.

**Expected Result:**

```text
Red OFF
Yellow OFF
Green ON
```

### Test 4 — Countdown

**Expected Result:**

```text
Red:     5 → 4 → 3 → 2 → 1 → 0
Yellow:  2 → 1 → 0
Green:   5 → 4 → 3 → 2 → 1 → 0
```

### Test 5 — State Transition

**Expected Result:**

```text
S0 → S1 → S2 → S0
```

### Test 6 — Continuous Operation

The system should continuously repeat the complete traffic-light cycle without requiring user input.

---

## 13. Verification Criteria

The implementation was considered successful when:

* Each LED activated during its assigned state.
* Only one traffic LED was active at a time.
* The 7-segment display showed the correct countdown.
* Countdown timing followed the defined durations.
* States transitioned in the correct order.
* The system continuously repeated the sequence.
* Hardware and software operated together as intended.

---

## 14. Debugging Strategy

When unexpected behavior occurred, troubleshooting followed a systematic approach.

### Hardware

1. Check power connections.
2. Verify LED polarity.
3. Verify resistor connections.
4. Check jumper-wire placement.
5. Confirm 7-segment display connections.

### Software

1. Verify pin definitions.
2. Check LED control logic.
3. Check digit mappings.
4. Verify countdown values.
5. Check function execution order.
6. Verify state transitions.

This approach helped isolate hardware and programming errors efficiently.

---

## 15. Implementation Limitations

The implementation was intentionally kept within the scope of a first-year BSIT project.

The completed system does not include:

* Vehicle sensors.
* Pedestrian controls.
* Dynamic traffic detection.
* Wireless communication.
* Internet connectivity.
* Real-time traffic monitoring.

The timing also relies on `delay()`, which blocks other program execution during the delay period.

---

## 16. Future Implementation Improvements

Future versions could improve the system by implementing:

### Non-Blocking Timing

Replace `delay()` with `millis()` to allow simultaneous operations.

### Pedestrian Controls

Add a push button and pedestrian signal.

### Vehicle Detection

Add sensors to detect traffic and dynamically modify signal timing.

### IoT Connectivity

Use an ESP32 or ESP8266 to support wireless monitoring and control.

### Intelligent Traffic Control

Future versions could use sensor data to dynamically adjust signal durations based on traffic conditions.

---

## 17. Final Implementation Outcome

The implementation successfully produced a functional timed traffic signal system based on the original design.

The final system demonstrates the integration of:

```text
Programming
     +
Digital Logic
     +
Arduino Hardware
     +
LED Control
     +
7-Segment Display
     +
Timing
     +
Testing
     =
Functional Traffic Signal System
```

The project therefore achieved its intended purpose as a practical **First-Year BSIT Culminating Project**.

---

## 18. Project Completion Checklist

* [x] Project requirements defined
* [x] System architecture designed
* [x] Traffic states defined
* [x] State table created
* [x] Hardware components selected
* [x] Arduino pins assigned
* [x] Circuit assembled
* [x] Arduino program implemented
* [x] LED control implemented
* [x] 7-segment countdown implemented
* [x] Timing implemented
* [x] State transitions implemented
* [x] System tested
* [x] Hardware/software issues debugged
* [x] Documentation completed
* [x] GitHub repository organized

---

## 19. Conclusion

The implementation of the **Design and Implementation of a Timed Traffic Signal System Using Arduino** successfully combined fundamental programming, digital logic, and hardware concepts into a functional embedded-system project.

The development process provided practical experience in planning, system design, circuit assembly, programming, testing, debugging, and technical documentation.

As a first-year BSIT culminating project, the system demonstrates the practical application of foundational knowledge acquired during the first year of the program.
