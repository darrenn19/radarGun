const int BUTTON_PIN = 25;
const int SEG_PINS[8] = {13, 14, 27, 26, 33, 32, 23, 22};
const int DIG_PINS[4] = {16, 17, 18, 19};

// Segment patterns for 0-9 (bit 0 = A ... bit 6 = G)
const byte NUMBERS[10] = {
  0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F
};

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  for (int i = 0; i < 8; i++) { pinMode(SEG_PINS[i], OUTPUT); digitalWrite(SEG_PINS[i], LOW); }
  for (int i = 0; i < 4; i++) { pinMode(DIG_PINS[i], OUTPUT); digitalWrite(DIG_PINS[i], HIGH); }
}

void showDigit(int position, byte pattern) {
  for (int i = 0; i < 4; i++) digitalWrite(DIG_PINS[i], HIGH);  // Turn all digits off
  for (int s = 0; s < 8; s++) digitalWrite(SEG_PINS[s], (pattern >> s) & 1);
  digitalWrite(DIG_PINS[position], LOW);
  delayMicroseconds(2000);
}

void loop() {
  int value = (digitalRead(BUTTON_PIN) == LOW) ? 8888 : 1234;
  int d[4] = { value / 1000 % 10, value / 100 % 10, value / 10 % 10, value % 10 };
  for (int p = 0; p < 4; p++) showDigit(p, NUMBERS[d[p]]);
}
