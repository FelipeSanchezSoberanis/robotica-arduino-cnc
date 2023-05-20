#define motor1_stepPin 2
#define motor1_dirPin 3

#define motor2_stepPin 4
#define motor2_dirPin 5

const int stepsPerRevolution = 200;

int currentX = 0;
int currentY = 0;

void setup() {
    pinMode(motor1_stepPin, OUTPUT);
    pinMode(motor1_dirPin, OUTPUT);
    pinMode(motor2_stepPin, OUTPUT);
    pinMode(motor2_dirPin, OUTPUT);
}

void loop() {
    int targetX = readXCoordinate();
    int targetY = readYCoordinate();
    int deltaX = targetX - currentX;
    int deltaY = targetY - currentY;

    int totalSteps = max(abs(deltaX), abs(deltaY));

    float xStepSize = deltaX / (float)totalSteps;
    float yStepSize = deltaY / (float)totalSteps;

    for (int i = 0; i < totalSteps; i++) {
        int xSteps = round(currentX + i * xStepSize);
        int ySteps = round(currentY + i * yStepSize);

        moveStepper(motor1_stepPin, motor1_dirPin, xSteps);

        moveStepper(motor2_stepPin, motor2_dirPin, ySteps);

        currentX = xSteps;
        currentY = ySteps;
    }
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
        delayMicroseconds(500);
        digitalWrite(stepPin, LOW);
        delayMicroseconds(500);
    }
}

int readXCoordinate() {
    int xCoordinate = analogRead(A0);
    return xCoordinate;
}

int readYCoordinate() {
    int yCoordinate = analogRead(A1);
    return yCoordinate;
}
