// SEGMENT PINS
int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;

// TRAFFIC LIGHT PINS
int greenled = 11;
int yellowled = 12;
int redled = 13;

// DIGIT MAP (COMMON ANODE)
int digits[10][7] = {
  {0, 0, 0, 0, 0, 0, 1}, // 0
  {1, 0, 0, 1, 1, 1, 1}, // 1
  {0, 0, 1, 0, 0, 1, 0}, // 2
  {0, 0, 0, 0, 1, 1, 0}, // 3
  {1, 0, 0, 1, 1, 0, 0}, // 4
  {0, 1, 0, 0, 1, 0, 0}, // 5
  {0, 1, 0, 0, 0, 0, 0}, // 6
  {0, 0, 0, 1, 1, 1, 1}, // 7
  {0, 0, 0, 0, 0, 0, 0}, // 8
  {0, 0, 0, 0, 1, 0, 0}  // 9
};

// SETUP
void setup() {
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);

  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);

  clearDisplay();
  resetLights();
}

// RESET LIGHTS
void resetLights() {
  digitalWrite(redled, LOW);
  digitalWrite(yellowled, LOW);
  digitalWrite(greenled, LOW);
}

// CLEAR DISPLAY
void clearDisplay() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

// DISPLAY NUMBER
void displayDigit(int num) {
  digitalWrite(pinA, digits[num][0]);
  digitalWrite(pinB, digits[num][1]);
  digitalWrite(pinC, digits[num][2]);
  digitalWrite(pinD, digits[num][3]);
  digitalWrite(pinE, digits[num][4]);
  digitalWrite(pinF, digits[num][5]);
  digitalWrite(pinG, digits[num][6]);
}

// COUNTDOWN FUNCTION
void countdown(int seconds, int ledPin) {
  resetLights();
  digitalWrite(ledPin, HIGH);

  for (int i = seconds; i >= 0; i--) {
    displayDigit(i);
    delay(1000);
  }

  clearDisplay();
}

// MAIN LOOP
void loop() {
  countdown(5, redled);
  countdown(2, yellowled);
  countdown(5, greenled);
}
