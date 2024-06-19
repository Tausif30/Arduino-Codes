const int trigPin = 9;
const int echoPin = 10;
// defines variables
long duration;
int distance;
void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2;
  if (distance < 5){
  //Right
  digitalWrite(12, LOW); 
  digitalWrite(9, LOW); 
  analogWrite(3, 255); 
  //Left 
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);   
  analogWrite(11, 255);

  delay(2500);
  //Right
  digitalWrite(12, HIGH); 
  digitalWrite(9, HIGH); 
  analogWrite(3, 0); 
  //Left 
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);   
  analogWrite(11, 0);

  delay(2500);

  //Right
  digitalWrite(12, HIGH); 
  digitalWrite(9, LOW); 
  analogWrite(3, 255); 
  //Left 
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);   
  analogWrite(11, 255);
  }
  else{
  //Right
  digitalWrite(12, HIGH); 
  digitalWrite(9, LOW); 
  analogWrite(3, 255); 
  //Left 
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);   
  analogWrite(11, 255);
  }
}