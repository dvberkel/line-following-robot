const int left_direction_pin = 7;
const int left_speed_pin = 6;
const int right_direction_pin = 4;
const int right_speed_pin = 5;
const int forward = LOW;
const int backward = HIGH;

int indicator_state = LOW;

void setup() {
  pinMode(left_direction_pin, OUTPUT);
  pinMode(right_direction_pin, OUTPUT);
}

void loop() {
  int value;
  for (value = 0; value < 255; value += 10) {
    digitalWrite(left_direction_pin, forward);
    analogWrite(left_speed_pin, value);
    digitalWrite(right_direction_pin, forward);
    analogWrite(right_speed_pin, value);
    delay(100);
  }
}

