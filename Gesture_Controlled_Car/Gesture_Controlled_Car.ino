int X = 0;
int Y = 0;
int Z = 0;

void setup() {
  Serial.begin(9600); //  setup serial
}

void loop(){
  X = analogRead(A0);
  Y = analogRead(A1);
  Z = analogRead(A2);

  if(X>150){
      //Right
  digitalWrite(12, HIGH); 
  digitalWrite(9, LOW); 
  analogWrite(3, 255); 
  //Left 
  digitalWrite(13, HIGH);
  digitalWrite(8, LOW);   
  analogWrite(11, 255);
  }
  if(X<100){
      //Right
  digitalWrite(12, LOW); 
  digitalWrite(9, LOW); 
  analogWrite(3, 255); 
  //Left 
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);   
  analogWrite(11, 255);
  }
  if(Y>150){
  //Right
  digitalWrite(12, HIGH); 
  digitalWrite(9, LOW); 
  analogWrite(3, 255); 
  //Left 
  digitalWrite(13, LOW);
  digitalWrite(8, LOW);   
  analogWrite(11, 255);
  }
  if(Y<100){
  //Right
  digitalWrite(12, LOW); 
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
  digitalWrite(9, HIGH); 
  analogWrite(3, 0); 
  //Left 
  digitalWrite(13, HIGH);
  digitalWrite(8, HIGH);   
  analogWrite(11, 0);
  }
}