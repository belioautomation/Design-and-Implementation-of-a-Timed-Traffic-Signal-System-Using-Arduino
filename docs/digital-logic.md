# Digital Logic Design

## Design and Implementation of a Timed Traffic Signal System Using Arduino

This document describes the digital logic and state-based control used in the timed traffic signal system.

---

## 1. Overview

The traffic signal system is designed as a simple **sequential state-based system**.

The Arduino Uno controls the traffic lights according to three predefined states:

```text
S0 → S1 → S2 → S0
```

Where:

```text
S0 = Red
S1 = Yellow
S2 = Green
```

Each state activates only its corresponding traffic-light output.

---

## 2. State Representation

The system contains three traffic-light states:

| State  | Traffic Signal | Description |
| ------ | -------------- | ----------- |
| **S0** | 🔴 Red         | Stop        |
| **S1** | 🟡 Yellow      | Caution     |
| **S2** | 🟢 Green       | Go          |

The controller continuously transitions between these states.

```text
       ┌───────┐
       │  S0   │
       │  RED  │
       └───┬───┘
           │
           ▼
       ┌───────┐
       │  S1   │
       │YELLOW │
       └───┬───┘
           │
           ▼
       ┌───────┐
       │  S2   │
       │ GREEN │
       └───┬───┘
           │
           └──────────► S0
```

---

## 3. State Table

The traffic-light outputs are represented using binary values.

`1` means ON and `0` means OFF.

| State  | Red | Yellow | Green |
| ------ | --: | -----: | ----: |
| **S0** |   1 |      0 |     0 |
| **S1** |   0 |      1 |     0 |
| **S2** |   0 |      0 |     1 |

This ensures that only one traffic signal is active at a time.

---

## 4. Output Logic

The traffic-light outputs correspond directly to the active state:

```text
R = S0
Y = S1
G = S2
```

Therefore:

```text
S0 → Red ON
S1 → Yellow ON
S2 → Green ON
```

The controller resets the previous outputs before activating the next state.

---

## 5. State Transition Logic

The state sequence follows:

```text
S0 → S1
S1 → S2
S2 → S0
```

The complete cycle is:

```text
RED → YELLOW → GREEN → RED
```

The transition occurs after the countdown associated with the current state has completed.

---

## 6. Timing Logic

Each state has a predefined duration.

| State  |  Duration |
| ------ | --------: |
| Red    | 5 seconds |
| Yellow | 2 seconds |
| Green  | 5 seconds |

The countdown display provides a visual representation of the remaining time.

```text
RED
5 → 4 → 3 → 2 → 1 → 0

YELLOW
2 → 1 → 0

GREEN
5 → 4 → 3 → 2 → 1 → 0
```

---

## 7. 7-Segment Display Logic

The 7-segment display represents numerical values by controlling seven individual segments:

```text
      A
     ───
  F │   │ B
     ─G─
  E │   │ C
     ───
      D
```

The Arduino activates the required segments to display each countdown digit.

The project uses a **common-anode 7-segment display**, so the segment control logic follows the electrical behavior of that configuration.

---

## 8. Sequential Operation

The complete logical operation can be represented as:

```text
Initialize System
       │
       ▼
   Red State
   5 seconds
       │
       ▼
  Yellow State
   2 seconds
       │
       ▼
  Green State
   5 seconds
       │
       ▼
   Red State
       │
       └──────► Repeat
```

---

## 9. Logic Summary

The project demonstrates basic concepts of sequential digital systems:

* State representation
* State transitions
* Binary output states
* Sequential control
* Timing-based transitions
* Digital output control

Although the system is implemented using an Arduino rather than discrete logic ICs, the underlying behavior follows a simple sequential-state model.

---

## 10. Conclusion

The digital logic design provides the foundation for the traffic signal controller.

By defining clear states, outputs, transitions, and timing requirements, the Arduino can reliably execute the traffic-light sequence:

```text
S0 → S1 → S2 → S0
```

This demonstrates how fundamental digital logic concepts can be applied to a practical embedded-system application.
