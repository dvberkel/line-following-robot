const int left_direction_pin = 7;
const int left_speed_pin = 6;
const int right_direction_pin = 4;
const int right_speed_pin = 5;
const int direction_forward = LOW;
const int direction_backward = HIGH;

const int sensor_pin = 0; // Should be an interrupt pin. Either 0 -> D2 or 1 -> D3
const int start_pin = 8;

volatile boolean on_track = false;
boolean started = false;

int a_speed = 255;
int a_delay = 1000;

void setup() {
  pinMode(sensor_pin, INPUT);
  pinMode(start_pin, INPUT);
  pinMode(left_direction_pin, OUTPUT);
  pinMode(right_direction_pin, OUTPUT);
  
  Serial.begin(9600);
  
  attachInterrupt(sensor_pin, on_track_changed, CHANGE);
}

void loop() {
  if (digitalRead(start_pin) == HIGH) {
    started = ! started;
    on_track = true;
    delay(1000);
  }
  if (started) {
    if (on_track) {
      Serial.println("on");
    } else {
      Serial.println("off");
    }
  }
}

void on_track_changed() {
  on_track = ! on_track;
}

void forward(int a_speed) {
  operate_left_motor(direction_forward, a_speed);
  operate_right_motor(direction_forward, a_speed);
}

void backward(int a_speed) {
  operate_left_motor(direction_backward, a_speed);
  operate_right_motor(direction_backward, a_speed);
}

void left(int a_speed) {
  operate_left_motor(direction_backward, a_speed);
  operate_right_motor(direction_forward, a_speed);
}

void right(int a_speed) {
  operate_left_motor(direction_forward, a_speed);
  operate_right_motor(direction_backward, a_speed);
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

