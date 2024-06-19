int X = 0;
int Y = 0;
void setup() {
  Serial.begin(9600);           //  setup serial
}

void loop() {
  X = analogRead(A1);
  Y = analogRead(A2);             // read the input pin
  Serial.println(X);
  Serial.println(Y);             // debug value
  delay(1000);
}