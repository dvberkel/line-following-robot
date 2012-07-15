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
    operate_left_motor(forward, value);
    operate_right_motor(forward, value);
    delay(100);
  }
}

void operate_left_motor(int a_direction, int a_speed) {
    digitalWrite(left_direction_pin, a_direction);
    analogWrite(left_speed_pin, a_speed);
}

void operate_right_motor(int a_direction, int a_speed) {
    digitalWrite(right_direction_pin, a_direction);
    analogWrite(right_speed_pin, a_speed);
}

void operate_motor(int direction_pin, int speed_pin, int a_direction, int a_speed) {
    digitalWrite(direction_pin, a_direction);
    analogWrite(speed_pin, a_speed);
}

