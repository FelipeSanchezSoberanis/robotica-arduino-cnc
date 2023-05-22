void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  if (Serial.available() <= 0) return;

  String input = Serial.readStringUntil('\n');
  input.trim();
  input.toUpperCase();

  if (input == "ON") {
    digitalWrite(LED_BUILTIN, HIGH);
  } else if (input == "OFF") {
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(100);

  Serial.println("DONE");
}
