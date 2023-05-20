#define motor1StepPin 2
#define motor1DirPin 3

#define motor2StepPin 4
#define motor2DirPint 5

int currentX = 0;
int currentY = 0;

void setup() {
    Serial.begin(9600);

    pinMode(motor1StepPin, OUTPUT);
    pinMode(motor1DirPin, OUTPUT);
    pinMode(motor2StepPin, OUTPUT);
    pinMode(motor2DirPint, OUTPUT);
}

void loop() {
    if (Serial.available() <= 0)
        return;

    String input = Serial.readStringUntil('\n');
    int xIndex = input.indexOf('X');
    int yIndex = input.indexOf('Y');

    String xSubstring = input.substring(xIndex + 1, yIndex);
    String ySubstring = input.substring(yIndex + 1, input.length());

    int targetX = xSubstring.toInt();
    int targetY = ySubstring.toInt();

    int deltaX = targetX - currentX;
    int deltaY = targetY - currentY;

    moveStepper(motor1StepPin, motor1DirPin, deltaX);
    moveStepper(motor2StepPin, motor2DirPint, deltaY);

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
        delay(100);
        digitalWrite(stepPin, LOW);
        delay(100);
    }
}
