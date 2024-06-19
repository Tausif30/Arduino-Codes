const int redPin = 9;    // Pin connected to the red LED
const int greenPin = 10; // Pin connected to the green LED
const int bluePin = 11;  // Pin connected to the blue LED

void setup() {
  Serial.begin(9600);    // Initialize serial communication
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();  // Read the command character
    Serial.println(command);
    if (command == 'R') {
      int redValue = Serial.parseInt();  // Read the red value
      analogWrite(redPin, redValue);     // Set the red LED intensity
    } 
    else if (command == 'G') {
      int greenValue = Serial.parseInt();  // Read the green value
      analogWrite(greenPin, greenValue);   // Set the green LED intensity
    } 
    else if (command == 'B') {
      int blueValue = Serial.parseInt();   // Read the blue value
      analogWrite(bluePin, blueValue);     // Set the blue LED intensity
    }

    // Read and discard the delimiter "R" after the value
    Serial.read();
  }
}
