// C++ code

//
#include<Servo.h>
Servo s;
const int buzzerPin = 12;

void setup()
{
  
  s.attach(3);
  pinMode(3,OUTPUT);
  pinMode(8,INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
  
}
  
  


void loop()
{
  
  int a = digitalRead(8);
  if ( a == 1){
    Serial.println("Motion Detected......");// motion detection
    delay(10);
     for(int i = 0;i <= 90;i++){
  s.write(i);
   delay(20);
}    // Door opening
  delay(10000);
  
  for(int i=90;i>=0;i--){
   s.write(i);
   delay(20); //Door closing
} 
    delay(1000);
   
  }
   double b = analogRead(A0);
    double t = (((b/1024)*5)-0.5)*100;
    Serial.print("Temperature value:");// temperature detection
    Serial.println(t);
  
    delay (1000);
   if ( t >=100)

   
  {
     
    digitalWrite(buzzerPin, HIGH); // if high temperature buzzer on
    
  }
  else
  {
    digitalWrite(buzzerPin, LOW); // if low temperature no buzzer on 
    
  }
  }