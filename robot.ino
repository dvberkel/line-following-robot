const int left_motor_pin = 4;
const int left_speed_pin = 5;

int indicator_state = LOW;

void setup() {
  pinMode(left_motor_pin, OUTPUT);
}

void loop() {
  int value;
  for (value = 0; value < 255; value += 10) {
    digitalWrite(left_motor_pin, LOW);
    analogWrite(left_speed_pin, value);
    delay(100);
  }
}

