#include <Servo.h>

const byte SERVO_PIN = 3;
const byte MOTOR_PIN1 = 6;
const byte MOTOR_PIN2 = 5;
const byte MOTOR_PIN3 = 8;
const byte MOTOR_PIN4 = 9;
const byte SERVO_ECHO = 10;
const byte SERVO_TRIGGER = 11;

// === TO FINETUNE ===
const int START_ANGLE = 180;
const int END_ANGLE = 65;

const unsigned long MOTOR_RUN_TIME_MS = 4400; // not used
const unsigned long MOTOR_RUN_TIME_BACK_MS = 3500;
const unsigned long MOTOR_REVERSE_MS = 500;
const unsigned long MOTOR_REVERSE_ABIT_MS = 200;
const unsigned long TURN_TIME_MS = 700;
const unsigned long SERVO_SETTLE_MS = 1000;
const unsigned long MOTOR_SETTLE_MS = 1000;

const float STOP_DISTANCE_CM = 10.0;
const unsigned long SENSOR_INTERVAL_MS = 60;
// ===================

Servo latchServo;

void stopMotor() {
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, LOW);
  digitalWrite(MOTOR_PIN3, LOW);
  digitalWrite(MOTOR_PIN4, LOW);
}

void moveForward() {
  digitalWrite(MOTOR_PIN1, HIGH);
  digitalWrite(MOTOR_PIN2, LOW);
  digitalWrite(MOTOR_PIN3, HIGH);
  digitalWrite(MOTOR_PIN4, LOW);
}

void moveReverse() {
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, HIGH);
  digitalWrite(MOTOR_PIN3, LOW);
  digitalWrite(MOTOR_PIN4, HIGH);
}

void moveTurn() {
  digitalWrite(MOTOR_PIN1, LOW);
  digitalWrite(MOTOR_PIN2, HIGH);
  digitalWrite(MOTOR_PIN3, HIGH);
  digitalWrite(MOTOR_PIN4, LOW);
}

// Added: wait until the ultrasonic sensor detects the wall.
void waitUntilNearWall() {
  Serial.println("ULTRASONIC: WAITING FOR DISTANCE");

  while (true) {
    digitalWrite(SERVO_TRIGGER, LOW);
    delayMicroseconds(2);
    digitalWrite(SERVO_TRIGGER, HIGH);
    delayMicroseconds(10);
    digitalWrite(SERVO_TRIGGER, LOW);

    unsigned long echoDuration =
        pulseIn(SERVO_ECHO, HIGH, 30000UL);

    if (echoDuration == 0) {
      Serial.println("NO ECHO: CONTINUING MOVEMENT");
    } else {
      float distanceCm = echoDuration * 0.0345 / 2.0;

      if (distanceCm <= STOP_DISTANCE_CM) {
        stopMotor();

        Serial.print("WALL DETECTED AT: ");
        Serial.print(distanceCm, 1);
        Serial.println(" CM — MOTORS STOPPED");
        return;
      }

      Serial.print("DISTANCE CM: ");
      Serial.println(distanceCm, 1);
    }

    delay(SENSOR_INTERVAL_MS);
  }
}

void setup() {
  Serial.begin(9600);

  pinMode(MOTOR_PIN1, OUTPUT);
  pinMode(MOTOR_PIN2, OUTPUT);
  pinMode(MOTOR_PIN3, OUTPUT);
  pinMode(MOTOR_PIN4, OUTPUT);
  stopMotor();

  // Added: ultrasonic sensor setup.
  pinMode(SERVO_ECHO, INPUT);
  pinMode(SERVO_TRIGGER, OUTPUT);
  digitalWrite(SERVO_TRIGGER, LOW);

  latchServo.attach(SERVO_PIN);

  // 1. Servo to END_ANGLE.
  Serial.println("SERVO TO END ANGLE");
  latchServo.write(END_ANGLE);
  delay(SERVO_SETTLE_MS);

  // 2. Go forward, then stop at the wall.
  Serial.println("REVERSING");
  moveReverse();
  waitUntilNearWall(); // Replaces delay(MOTOR_RUN_TIME_MS)
  stopMotor();

  // 3. Servo to START_ANGLE.
  Serial.println("SERVO TO START ANGLE");
  latchServo.write(START_ANGLE);
  delay(SERVO_SETTLE_MS);

  // Reverse a bit
  moveForward();
  delay(MOTOR_REVERSE_MS);
  stopMotor();

  // 1. Servo to END_ANGLE.
  Serial.println("SERVO TO END ANGLE");
  latchServo.write(END_ANGLE);
  delay(SERVO_SETTLE_MS);

  // 4. Turn, then stop.
  Serial.println("TURNING");
  moveTurn();
  delay(TURN_TIME_MS);
  stopMotor();
  delay(MOTOR_SETTLE_MS);

  moveForward();
  delay(MOTOR_REVERSE_ABIT_MS);
  stopMotor();

  moveTurn();
  delay(TURN_TIME_MS);
  stopMotor();
  delay(MOTOR_SETTLE_MS);

  moveForward();
  delay(MOTOR_REVERSE_ABIT_MS);
  stopMotor();

  moveTurn();
  delay(TURN_TIME_MS);
  stopMotor();
  delay(MOTOR_SETTLE_MS);

  // Now reverse.
  Serial.println("REVERSING");
  moveReverse();
  delay(MOTOR_RUN_TIME_BACK_MS);
  stopMotor();

  Serial.println("SEQUENCE COMPLETE");
}

void loop() {
  // Runs once in setup(). Reset to repeat.
}
