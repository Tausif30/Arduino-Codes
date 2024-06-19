char command;
int A = 255;  // Default speed

void setup() {
  Serial.begin(9600);  // Set the baud rate to your Bluetooth module.
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    if (command == 'S') {
      stop();
    } else if (command == 'A') {
      A = Serial.parseInt();  // Read the speed value from the serial input
    } else {
      stop(); 
      switch (command) {
        case 'F':
          forward();
          break;
        case 'B':
          back();
          break;
        case 'L':
          left();
          break;
        case 'R':
          right();
          break;
        case 'S':
          stop();
          break;
      }
    }
  }
}

void forward() {
  // Right
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  analogWrite(3, A);  // Use the variable A for speed
  // Left
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  analogWrite(11, A);  // Use the variable A for speed
}

void back() {
  // Right
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  analogWrite(3, A);  // Use the variable A for speed
  // Left
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);
  analogWrite(11, A);  // Use the variable A for speed
}

void stop() {
  // Right
  digitalWrite(12, HIGH);
  digitalWrite(9, HIGH);
  analogWrite(3, 0); 
  // Left
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);
  analogWrite(11, 0);
}

void right() {
  // Right
  digitalWrite(12, HIGH);
  digitalWrite(9, LOW);
  analogWrite(3, A);  // Use the variable A for speed
  // Left
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);
  analogWrite(11, A);  // Use the variable A for speed
}

void left() {
  // Right
  digitalWrite(12, LOW);
  digitalWrite(9, LOW);
  analogWrite(3, A);  // Use the variable A for speed
  // Left
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);
  analogWrite(11, A);  // Use the variable A for speed
}
