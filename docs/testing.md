# Testing and Verification

## Design and Implementation of a Timed Traffic Signal System Using Arduino

This document describes the testing procedures used to verify the functionality of the completed traffic signal system.

---

## 1. Testing Objective

The primary goal of testing was to verify that the system operated according to its intended design.

Testing focused on:

* Traffic LED outputs
* 7-segment countdown
* Timing
* State transitions
* Continuous operation
* Hardware and software integration

---

## 2. Test Environment

Testing was performed using the completed Arduino-based circuit and/or circuit simulation environment.

### Main Components

* Arduino Uno
* Red LED
* Yellow LED
* Green LED
* 7-segment display
* Resistors
* Breadboard
* Arduino IDE
* Tinkercad / Proteus, where applicable

---

## 3. LED Output Testing

Each traffic-light state was tested individually.

### Red State

**Expected:**

```text
Red    = ON
Yellow = OFF
Green  = OFF
```

### Yellow State

**Expected:**

```text
Red    = OFF
Yellow = ON
Green  = OFF
```

### Green State

**Expected:**

```text
Red    = OFF
Yellow = OFF
Green  = ON
```

### Result

The traffic LEDs followed the intended state-based sequence.

---

## 4. Countdown Display Testing

The 7-segment display was tested to verify that it showed the correct countdown values.

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

The display was verified against the expected countdown sequence.

---

## 5. Timing Testing

The timing behavior was tested according to the defined state durations.

| State  | Target Duration |
| ------ | --------------: |
| Red    |       5 seconds |
| Yellow |       2 seconds |
| Green  |       5 seconds |

The countdown and LED activation were synchronized with the programmed timing behavior.

---

## 6. State Transition Testing

The complete state sequence was tested to verify that each state transitioned to the correct next state.

```text
S0 → S1 → S2 → S0
```

Expected sequence:

```text
RED → YELLOW → GREEN → RED
```

The controller successfully returned to the Red state after completing the Green state.

---

## 7. Continuous Operation Test

The system was allowed to operate through multiple complete cycles.

### Expected Behavior

```text
RED
 ↓
YELLOW
 ↓
GREEN
 ↓
RED
 ↓
YELLOW
 ↓
GREEN
 ↓
REPEAT
```

The system was designed to continue operating automatically without user input.

---

## 8. Test Cases

| Test Case             | Expected Result     | Status   |
| --------------------- | ------------------- | -------- |
| Red LED activation    | Red LED turns ON    | ✅ Passed |
| Yellow LED activation | Yellow LED turns ON | ✅ Passed |
| Green LED activation  | Green LED turns ON  | ✅ Passed |
| Red countdown         | 5 → 0               | ✅ Passed |
| Yellow countdown      | 2 → 0               | ✅ Passed |
| Green countdown       | 5 → 0               | ✅ Passed |
| State transition      | S0 → S1 → S2        | ✅ Passed |
| Return to Red         | S2 → S0             | ✅ Passed |
| Continuous cycle      | Sequence repeats    | ✅ Passed |

---

## 9. Hardware Testing

Hardware testing included verification of:

* LED polarity
* Resistor connections
* Arduino pin assignments
* Breadboard wiring
* 7-segment display connections
* Power and ground connections

Incorrect or loose connections were checked and corrected during the development and testing process.

---

## 10. Software Testing

Software testing focused on:

* Pin configuration
* LED control functions
* Countdown logic
* 7-segment digit mapping
* State sequence
* Timing behavior
* Function execution order

The program was tested repeatedly to ensure consistent behavior.

---

## 11. Debugging

When unexpected behavior occurred, troubleshooting was performed systematically.

### Common Issues Checked

**LED not lighting**

* Check LED polarity.
* Check resistor connection.
* Check Arduino pin assignment.
* Check program output.

**Incorrect number on display**

* Check segment wiring.
* Check digit mapping.
* Check common-anode configuration.

**Incorrect traffic sequence**

* Check function calls.
* Check state order.
* Check LED reset logic.

**Incorrect timing**

* Check countdown values.
* Check delay interval.
* Check countdown function execution.

---

## 12. Limitations of Testing

The testing process verifies the behavior of the prototype under its defined conditions.

It does not represent a real-world traffic-control system because the project does not include:

* Real traffic conditions
* Vehicle sensors
* Pedestrian traffic
* Adaptive timing
* Emergency vehicle detection
* Network communication

The system is intended for educational demonstration rather than real-world traffic management.

---

## 13. Verification Summary

The completed system was verified against its primary functional requirements.

The testing confirmed that:

* Traffic LEDs activate according to their assigned states.
* The 7-segment display provides the intended countdown.
* The programmed durations are followed.
* States transition in the correct order.
* The complete cycle repeats automatically.

---

## 14. Final Test Result

### Overall Status

**✅ SYSTEM VERIFIED**

The completed prototype successfully demonstrates the intended timed traffic signal behavior.

```text
RED → YELLOW → GREEN → RED
```

The testing process confirmed the integration of the Arduino program, digital logic, traffic LEDs, countdown display, and timing system.

---

## 15. Conclusion

Testing and verification were essential parts of the project implementation.

By testing individual components and the complete system, hardware and software behavior could be checked against the original design.

The final result demonstrates a functional and repeatable timed traffic signal system suitable for the scope of a **First-Year BSIT Culminating Project**.
