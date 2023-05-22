#define motor1_stepPin 2
#define motor1_dirPin 3

#define motor2_stepPin 4
#define motor2_dirPin 5

#define motor3_stepPin 6
#define motor3_dirPin 7

#include <Servo.h>

Servo servoPinza;
Servo servoChange;

int currentX = 0;
int currentY = 0;
int currentZ = 0;
int instruction = 0;
bool firstTime = true;
char *token;
const char s[2] = " ";
char *x;
char *y;
int count = 0;

void setup() {
  Serial.begin(9600);

  pinMode(motor1_stepPin, OUTPUT);
  pinMode(motor1_dirPin, OUTPUT);
  pinMode(motor2_stepPin, OUTPUT);
  pinMode(motor2_dirPin, OUTPUT);
  pinMode(motor3_stepPin, OUTPUT);
  pinMode(motor3_dirPin, OUTPUT);

  servoPinza.attach(9);
  servoChange.attach(10);

  servoChange.write(0);
}

void setInstruction(String input) {
  if (strstr(input.c_str(), "TOOL_UP")) {
    instruction = 0;
  } else if (strstr(input.c_str(), "TOOL_DOWN")) {
    instruction = 1;
  } else if (strstr(input.c_str(), "MOVE_TO")) {
    instruction = 2;
  } else if (strstr(input.c_str(), "CHANGE_COLOR")) {
    instruction = 3;
  }
}

void loop() {
  if (Serial.available() <= 0) return;

  String input = Serial.readStringUntil('\n');

  setInstruction(input);

  switch (instruction) {
    case 0:  // TOOL_UP
      toolUp();
      break;

    case 1:  // TOOL_DOWN
      toolDown();
      break;

    case 2:  // MOVE_TO
      count = 0;
      token = strtok(input.c_str(), s);
      while (token != NULL) {
        token = strtok(NULL, s);
        count++;
        if (count == 1) {
          x = token;
        } else if (count == 2) {
          y = token;
        }
      }
      moveMotor();
      break;

    case 3:  // CHANGE_COLOR
      if (strstr(input.c_str(), "RED")) {
        returnHome();
        delay(500);
        if (firstTime == true) {
          servoPinza.write(80);
        }
        toolDown();
        delay(500);
        changeColor(0);

      } else if (strstr(input.c_str(), "GREEN")) {
        returnHome();
        delay(500);
        if (firstTime == true) {
          servoPinza.write(80);
        }
        toolDown();
        delay(500);
        changeColor(1);

      } else if (strstr(input.c_str(), "BLUE")) {
        returnHome();
        delay(500);

        toolDown();
        delay(500);
        changeColor(2);
      }
      break;

    default:
      break;
  }
}

void returnHome() {
  if (firstTime == false) {
    toolUp();
  }

  x = 0;
  y = 0;

  moveMotor();

  if (Serial.available() <= 0) return;
}

void changeColor(int color) {
  switch (color) {
    case 0:

      servoPinza.write(80);
      delay(500);

      if (firstTime == false) {
        toolUp();
        delay(500);
      }

      servoChange.write(0);
      delay(500);

      if (firstTime == false) {
        toolDown();
        delay(500);
      }

      servoPinza.write(0);
      delay(500);
      toolUp();

      break;

    case 1:

      servoPinza.write(80);
      delay(500);

      if (firstTime == false) {
        toolUp();
        delay(500);
      }

      servoChange.write(90);
      delay(500);

      if (firstTime == false) {
        toolDown();
        delay(500);
      }

      servoPinza.write(0);
      delay(500);
      toolUp();

      break;

    case 2:

      servoPinza.write(80);
      delay(500);

      if (firstTime == false) {
        toolUp();
        delay(500);
      }

      servoChange.write(180);
      delay(500);

      if (firstTime == false) {
        toolDown();
        delay(500);
      }

      servoPinza.write(0);
      delay(500);
      toolUp();
      break;

    default:
      break;
  }

  firstTime = false;
}

void toolDown() {
  digitalWrite(motor3_dirPin, HIGH);

  for (int i = 0; i < 950; i++) {
    digitalWrite(motor3_stepPin, HIGH);
    delay(1);
    digitalWrite(motor3_stepPin, LOW);
    delay(1);
  }
}

void toolUp() {
  digitalWrite(motor3_dirPin, LOW);

  for (int i = 0; i < 950; i++) {
    digitalWrite(motor3_stepPin, HIGH);
    delay(1);
    digitalWrite(motor3_stepPin, LOW);
    delay(1);
  }
}

void moveMotor() {
  int targetX = atoi(x);
  int targetY = atoi(y);

  int deltaX = targetX - currentX;
  int deltaY = targetY - currentY;

  moveStepper(motor1_stepPin, motor1_dirPin, deltaX);
  moveStepper(motor2_stepPin, motor2_dirPin, deltaY);

  currentX = targetX;
  currentY = targetY;
}

void moveStepper(int stepPin, int dirPin, int steps) {
  if (steps >= 0) {
    digitalWrite(dirPin, HIGH);
  } else {
    digitalWrite(dirPin, LOW);
    steps = -steps;
  }

  for (int i = 0; i < steps; i++) {
    digitalWrite(stepPin, HIGH);
    delay(1);
    digitalWrite(stepPin, LOW);
    delay(1);
  }
}
