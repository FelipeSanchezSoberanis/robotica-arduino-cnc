void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available() <= 0) return;

  String input = Serial.readStringUntil('\n');
  input.trim();
  input.toUpperCase();

  if (input == "1") {
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (input == "0") {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(1000);
}
