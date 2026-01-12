// Motor driver pins
#define enA 10
#define in1 9
#define in2 8
#define in3 7
#define in4 6
#define enB 5

// IR Sensors
#define L_S A0      // Left IR sensor
#define R_S A1      // Right IR sensor

// Ultrasonic Sensor
#define trig 12
#define echo 11

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  pinMode(L_S, INPUT);
  pinMode(R_S, INPUT);

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  // Motor speed
  analogWrite(enA, 180);
  analogWrite(enB, 180);
}

void loop() {

  int leftSensor  = digitalRead(L_S);
  int rightSensor = digitalRead(R_S);

  distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | L:");
  Serial.print(leftSensor);
  Serial.print(" R:");
  Serial.println(rightSensor);

  // 🚧 Obstacle avoidance using ultrasonic sensor
  if (distance > 0 && distance < 15) {
    stopMotors();
    delay(300);

    moveBackward();
    delay(400);

    turnRight();
    delay(500);
  }

  // ➖ Line following logic
  else if (leftSensor == LOW && rightSensor == LOW) {
    moveForward();
  }
  else if (leftSensor == HIGH && rightSensor == LOW) {
    turnLeft();
  }
  else if (leftSensor == LOW && rightSensor == HIGH) {
    turnRight();
  }
  else {
    stopMotors();
  }

  delay(10);
}

// 📏 Ultrasonic distance function
int getDistance() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  duration = pulseIn(echo, HIGH, 25000); // timeout 25ms

  if (duration == 0) return -1; // no object detected

  return duration * 0.034 / 2;
}

// 🚗 Motor control functions
void moveForward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void moveBackward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void turnLeft() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void turnRight() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopMotors() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
