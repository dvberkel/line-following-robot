const int indicator_pin = 13;

int indicator_state = LOW;

void setup() {
  pinMode(indicator_pin, OUTPUT);
}

void loop() {
  if (indicator_state == LOW) {
    indicator_state = HIGH;
  } else {
    indicator_state = LOW;
  }
  digitalWrite(indicator_pin, indicator_state);
  delay(500);
}

