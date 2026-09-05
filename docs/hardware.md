# Hardware Documentation

## Design and Implementation of a Timed Traffic Signal System Using Arduino

This document describes the hardware components, connections, and physical implementation of the completed traffic signal system.

---

## 1. Hardware Overview

The system uses an **Arduino Uno** as the primary microcontroller.

The Arduino controls:

* Red LED
* Yellow LED
* Green LED
* Common-anode 7-segment display

The circuit can be assembled on a breadboard for prototyping and demonstration.

---

## 2. Hardware Components

| Component                      |    Quantity | Function               |
| ------------------------------ | ----------: | ---------------------- |
| Arduino Uno                    |           1 | Main controller        |
| Breadboard                     |           1 | Circuit assembly       |
| Red LED                        |           1 | Stop indicator         |
| Yellow LED                     |           1 | Caution indicator      |
| Green LED                      |           1 | Go indicator           |
| Common-Anode 7-Segment Display |           1 | Countdown display      |
| 220Ω Resistors                 | As required | LED current limiting   |
| Jumper Wires                   |     Several | Electrical connections |
| USB Cable                      |           1 | Power and programming  |

---

## 3. Arduino Pin Configuration

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

---

## 4. LED Connections

Each traffic LED is connected to an Arduino digital output through a current-limiting resistor.

```text
Arduino Pin
     │
     ▼
  Resistor
     │
     ▼
    LED
     │
     ▼
    GND
```

The three LEDs represent the traffic signals:

```text
Pin 13 → Red LED
Pin 12 → Yellow LED
Pin 11 → Green LED
```

---

## 5. 7-Segment Display Connections

The seven segments of the display are connected to Arduino digital pins.

```text
A → 2
B → 3
C → 4
D → 5
E → 6
F → 7
G → 8
```

The display is configured as a **common-anode** type.

The Arduino controls the individual segments to produce the required countdown digits.

---

## 6. Circuit Structure

A simplified representation of the hardware is:

```text
                    Arduino Uno
                 ┌───────────────┐
                 │               │
             13 ─┤               ├─ 2 → Segment A
             12 ─┤               ├─ 3 → Segment B
             11 ─┤               ├─ 4 → Segment C
                 │               ├─ 5 → Segment D
                 │               ├─ 6 → Segment E
                 │               ├─ 7 → Segment F
                 │               ├─ 8 → Segment G
                 └───────────────┘
                    │   │   │
                    ▼   ▼   ▼
                   RED YEL GREEN
```

---

## 7. Power and Ground

The Arduino can be powered through its USB connection during development and testing.

The circuit components share a common ground connection with the Arduino.

Proper power and ground connections are necessary for reliable operation.

---

## 8. Breadboard Assembly

The physical implementation follows these general steps:

1. Place the Arduino Uno and breadboard in the workspace.
2. Connect the Arduino ground to the breadboard ground rail.
3. Install the Red, Yellow, and Green LEDs.
4. Connect each LED through an appropriate resistor.
5. Connect the LEDs to their assigned Arduino pins.
6. Install the 7-segment display.
7. Connect segments A–G to pins 2–8.
8. Verify all wiring before powering the circuit.
9. Upload the Arduino program.
10. Test the complete system.

---

## 9. Hardware Safety Considerations

The following practices should be observed during assembly:

* Use appropriate current-limiting resistors for LEDs.
* Verify LED polarity before powering the circuit.
* Check 7-segment display pin configuration.
* Avoid short circuits.
* Disconnect power when modifying wiring.
* Verify Arduino pin assignments before uploading the program.

---

## 10. Hardware Verification

Before running the complete system, individual hardware components should be checked.

### LED Verification

```text
Pin 13 → Red
Pin 12 → Yellow
Pin 11 → Green
```

### Display Verification

Each segment should respond correctly to the Arduino's output.

### Final Verification

After individual components are confirmed, the complete circuit should be tested together.

---

## 11. Hardware Limitations

The hardware implementation is intentionally simple and designed for an introductory embedded-system project.

It does not include:

* Vehicle sensors
* Pedestrian buttons
* Buzzer
* Wireless communication
* Traffic monitoring sensors

These components can be added in future versions.

---

## 12. Conclusion

The hardware implementation successfully combines the Arduino Uno, traffic LEDs, resistors, breadboard, and 7-segment display into a functional traffic signal system.

The selected components provide a simple and accessible platform for demonstrating programming, digital logic, and embedded-system concepts.
