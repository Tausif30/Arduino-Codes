/* This code works with GY-31 TCS3200 TCS230 color sensor module
 *   It select a photodiode set and read its value (Red Set/Blue set/Green set) and reproduce   the color on the RGB LED
 * Refer to www.surtrtech.com for more details
 */
   
#define s0 2        //Module pins wiring
#define s1 3
#define s2 4
#define   s3 5
#define out 6

#define LED_R 9   //LED pins, don't forget "pwm"
#define   LED_G 10
#define LED_B 11

int Red=0, Blue=0, Green=0;

void setup()   
{
   pinMode(LED_R,OUTPUT);     //pin modes
   pinMode(LED_G,OUTPUT);
    pinMode(LED_B,OUTPUT);
   
   pinMode(s0,OUTPUT);    
   pinMode(s1,OUTPUT);
    pinMode(s2,OUTPUT);
   pinMode(s3,OUTPUT);
   pinMode(out,INPUT);

    Serial.begin(9600);   //intialize the serial monitor baud rate
   
   digitalWrite(s0,HIGH);   //Putting S0/S1 on HIGH/HIGH levels means the output frequency scalling is at 100%   (recommended)
   digitalWrite(s1,HIGH); //LOW/LOW is off HIGH/LOW is 20% and   LOW/HIGH is  2%
   
}

void loop()
{
  GetColors();                                    //Execute   the GetColors function
  
  analogWrite(LED_R,map(Red,15,60,255,0));      //analogWrite   generates a PWM signal with 0-255 value (0 is 0V and 255 is 5V), LED_R is the pin   where we are generating the signal, 15/60 are the min/max of the "Red" value,   try measuring your own ones
                                               //e.g:   if the "Red" value given by the sensor is 15 -> it will generate a pwm signal   with 255 value on the LED_R pin same for 60->0, because the lower the value given   by the sensor the higher is that color
  analogWrite(LED_G,map(Green,30,55,255,0));     
  analogWrite(LED_B,map(Blue,13,45,255,0));

}

void GetColors()   
{    
  digitalWrite(s2, LOW);                                           //S2/S3   levels define which set of photodiodes we are using LOW/LOW is for RED LOW/HIGH   is for Blue and HIGH/HIGH is for green 
  digitalWrite(s3, LOW);                                           
   Red = pulseIn(out, digitalRead(out) == HIGH ? LOW : HIGH);       //here we wait   until "out" go LOW, we start measuring the duration and stops when "out" is   HIGH again, if you have trouble with this expression check the bottom of the code
   delay(20);  
  digitalWrite(s3, HIGH);                                         //Here   we select the other color (set of photodiodes) and measure the other colors value   using the same techinque
  Blue = pulseIn(out, digitalRead(out) == HIGH ? LOW   : HIGH);
  delay(20);  
  digitalWrite(s2, HIGH);  
  Green = pulseIn(out,   digitalRead(out) == HIGH ? LOW : HIGH);
  delay(2000);  
}

//Here's an   example how to understand that expression above,
//""digitalRead(out) == HIGH   ? LOW : HIGH"" this whole expression is either HIGH or LOW as pulseIn function   requires a HIGH/LOW value on the second argument

//led_Status = led_Status   == HIGH ? LOW : HIGH;  
//
//if(led_Status == HIGH) 
//{ 
//led_Status   =LOW; 
//} 
//else 
//{ 
//led_Status = HIGH; 
//}

