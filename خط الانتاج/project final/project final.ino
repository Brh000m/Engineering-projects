


#include <Servo.h> 

Servo Servo1;

int IRSensor1 =12; // connect ir sensor to arduino pin 2
int IRSensor2 = 13; // conect Led to arduino pin 13
int DCMOTOr1 = 2;
int SERVO = 3;
int PUMP = 4;
int DCMOTOR2 = 5;
int AIR = 7;


// stepper
const int dirPin = 10;
const int stepPin = 11;
//const int stepsPerRevolution = 1000;


void setup() 
{
  pinMode (IRSensor1, INPUT); // sensor pin INPUT
  pinMode (IRSensor2, INPUT); // Led pin OUTPUT
  pinMode (DCMOTOr1, OUTPUT);
  Servo1.attach(SERVO); 
 // pinMode (SERVO, OUTPUT);
  pinMode (PUMP, OUTPUT);
 // pinMode (STEPR, OUTPUT);
   pinMode(stepPin, OUTPUT);
   pinMode(dirPin, OUTPUT);
   
  pinMode (DCMOTOR2, OUTPUT);
  pinMode (AIR, OUTPUT);
  
}

void loop()
{
  int statusSensor1 = digitalRead (IRSensor1);
  int statusSensor2 = digitalRead (IRSensor2);

  digitalWrite(DCMOTOr1, HIGH);
   //delay(3000);
     
                                               //    int statusSensor11=0;
  if (statusSensor1 == 0){
    digitalWrite(DCMOTOr1, LOW); // LED LOW    
    Servo1.write(180);  
    // digitalWrite(SERVO, HIGH);
     digitalWrite(PUMP, HIGH); 
     delay(3000);
     digitalWrite(PUMP, LOW);
    // digitalWrite(STEPR, HIGH);
    
    int stepsPerRevolution1=15000;
     digitalWrite(dirPin,HIGH);
      for(int x = 0; x < stepsPerRevolution1; x++)
  {
    
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
  }
  
    // digitalWrite(DCMOTOr1, HIGH);
    // Servo1.write(0);
  }
                                                                             //int statusSensor21=0;
  if (statusSensor2 == 0){
    
    digitalWrite(stepPin, LOW);// stop stepper motor
    delay(3000);
    digitalWrite(DCMOTOr1, LOW);
    //digitalWrite(STEPR, LOW);
    //digitalWrite(stepPin, LOW);
    digitalWrite(AIR, HIGH);
    delay(3000);
    digitalWrite(AIR, LOW);
    digitalWrite(DCMOTOR2, HIGH);
    delay(3000);
    digitalWrite(DCMOTOR2, LOW);
    
   int stepsPerRevolution2=12000;
    digitalWrite(dirPin, HIGH);
      for(int x = 0; x < stepsPerRevolution2; x++)
  {
    digitalWrite(stepPin,LOW);
    delayMicroseconds(500);
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
  }
  Servo1.write(0);

  
   digitalWrite(dirPin, LOW);
  int stepsPerRevolution3=23000;
      for(int x = 0; x < stepsPerRevolution3; x++)
  {
    
    digitalWrite(stepPin, HIGH);
    delayMicroseconds(500);
    
    digitalWrite(stepPin, LOW);
    delayMicroseconds(500);
  }
    //digitalWrite(STEPR, HIGH);
    
    }
  
  
}