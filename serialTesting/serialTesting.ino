void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void parseCoords(String input, int* x, int* y) {
  String coordsString = input.substring(input.indexOf(" ") + 1, input.length());
  int spaceIndex = coordsString.indexOf(" ");
  *x = coordsString.substring(0, spaceIndex).toInt();
  *y = coordsString.substring(spaceIndex + 1, coordsString.length()).toInt();
}
void parseColor(String input, String* color) {
  *color = input.substring(input.indexOf(" ") + 1, input.length());
}

void toolUp() { Serial.println("Received command TOOL_UP"); }
void toolDown() { Serial.println("Received command TOOL_DOWN"); }
void moveTo(String input) {
  Serial.println("Received command MOVE_TO");
  int x, y;
  parseCoords(input, &x, &y);
  Serial.print("x: ");
  Serial.println(x);
  Serial.print("y: ");
  Serial.println(y);
}
void changeColor(String input) {
  Serial.println("Received command CHANGE_COLOR");
  String color;
  parseColor(input, &color);
  Serial.print("Color: ");
  Serial.println(color);
}

void loop() {
  if (Serial.available() <= 0) return;

  String input = Serial.readStringUntil('\n');
  input.trim();
  input.toUpperCase();

  if (input == "TOOL_UP") {
    toolUp();
  } else if (input == "TOOL_DOWN") {
    toolDown();
  } else if (input.startsWith("MOVE_TO")) {
    moveTo(input);
  } else if (input.startsWith("CHANGE_COLOR")) {
    changeColor(input);
  }

  Serial.println("DONE");
}
