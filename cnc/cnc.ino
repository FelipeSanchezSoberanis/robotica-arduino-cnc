#define motor1_stepPin 2
#define motor1_dirPin 3

#define motor2_stepPin 4
#define motor2_dirPin 5

#define motor3_stepPin 6
#define motor3_dirPin 7

int currentX = 0;
int currentY = 0;
int currentZ = 0;
int instruction = 0;
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
}

void loop() {

    if (Serial.available() <= 0)
        return;

    String input = Serial.readStringUntil('\n');

    // char* pinput = input.toCharArray();

    if (input == "TOOL_UP") {
        instruction = 0;
    } else if (input == "TOOL_DOWN") {
        instruction = 1;
    } else if (strstr(input.c_str(), "MOVE_TO")) {
        instruction = 2;
    } else if (strstr(input.c_str(), "CHANGE_COLOR")) {
        instruction = 3;
    }

    switch (instruction) {

    case 0: // TOOL_UP
        toolUp();
        break;

    case 1: // TOOL_DOWN
        toolDown();
        break;

    case 2: // MOVE_TO
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

    case 3: // CHANGE_COLOR
        if (strstr(input.c_str(), "RED")) {
            Serial.println("rojo");
            returnHome();
        } else if (strstr(input.c_str(), "GREEN")) {
            Serial.println("verde");
        } else if (strstr(input.c_str(), "BLUE")) {
            Serial.println("azul");
        }
        break;

    default:
        break;
    }
}

void returnHome() {

    toolUp();

    x = 0;
    y = 0;

    moveMotor();

    if (Serial.available() <= 0)
        return;
}

void changeColor() {}

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

    Serial.println(deltaX);
    Serial.println(deltaY);

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
