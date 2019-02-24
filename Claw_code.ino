/*
 Controlling a servo position based on the distance reading from a sensor

 Program designed to operate a claw arm based on its height from the ground
*/

#include <Servo.h>

#define GroundPin 10 //the Ground pin is attached to pin 13

#define echoPin 11 //the Echo pin is attached to pin 13

#define trigPin 12 // the Trig pin is attached to pin 13

#define VccPin 13 // the Vcc pin is attached to pin 13

#define SERVO_PIN 9 // attaches the servo on pin 9 to the servo object



Servo myservo;  // create servo object to control a servo


void setup() {
  myservo.attach(SERVO_PIN);  // attaches the servo on pin 9 to the servo object

  Serial.begin (9600);         //set data transmission rate to communicate with computer

pinMode(VccPin, OUTPUT) ;    //tell pin 13 it is going to be an output

digitalWrite(VccPin, HIGH) ; //tell pin 13 to output HIGH (+5V)

pinMode(echoPin, INPUT);     //tell pin 11 it is going to be an input

pinMode(trigPin, OUTPUT);    //tell pin 12 it is going to be an output

pinMode(GroundPin, OUTPUT) ; //tell pin 10 it is going to be an output

digitalWrite(GroundPin,LOW) ;//tell pin 10 to output LOW (0V, or ground)
  
}

void loop() {
  int duration, distance;                //defining variables

digitalWrite(trigPin, HIGH);           //set trigger pin to HIGH

delayMicroseconds(1000);               //wait 1000 microseconds

digitalWrite(trigPin, LOW);            //set trigger pin to LOW

duration = pulseIn(echoPin, HIGH);     //read echo pin

distance = (duration/2) / 29.1;        //compute distance from duration of echo Pin

if (distance <= 14 && distance >= 1)  //deciding whether or not distance is reasonable

  {

  Serial.println(distance);      // print the distance for testing purposes
  delay(2000);                  //One second delay to allow for claw to be properly positioned
  myservo.write(65);                  // Closes the claw
                             
  }

// The Claw will remain closed after raising it as long as it isn't raised it too high

if(distance <=100 && distance >=50 )   //If claw is raised above a certain height, it will open again

  {

  Serial.print(distance);              //printing the value of the variable "distance" in cm for testing purposes
  
  Serial.println(" cm");               //printing " cm" after the value and cuz I'm too lazy to delete this line
  myservo.write(140);                  // Opens the claw
  delay(50);                           // waits for the servo to get there
  
  }

 if(distance <50 && distance >15 )
 {
    Serial.print(distance);              //printing the value of the variable "distance" in cm for testing purposes
  
  Serial.println(" cm");               //printing " cm" after the value and cuz I'm too lazy to delete this line
  delay(50);
 }
  
}
