#include <Servo.h>
Servo myservo;
int pos = 0;
// setting up the servo library
int Echo = 12;
int Trig = 13;
// setting up the ultrasosonic pins
// setting up pins for motor A and B for directiona and speed
int AIN1 = 7;
int PWMA = 5;
int BIN1 = 8;
int PWMB = 6;
#define carSpeed 50
float duration, distance;
// define the speed limit duration and distance

void setup() {
  // set up pin to servo and the inputs and outputs for the rest
myservo.attach(10);
 digitalWrite(3,1);
for (int i=3; i<9; i++){
pinMode(i, OUTPUT);
Serial.begin(9660);
pinMode(Trig,OUTPUT);
pinMode(Echo,INPUT);


}
  }
// setting up functions to control all the 9 different movements of the car /direction and speed

///////////////////////////////////////////////////
void Forward(){
  digitalWrite(AIN1,1);
  digitalWrite(BIN1,1);
  analogWrite(PWMA,carSpeed);
  analogWrite(PWMB,carSpeed);
}
/////////////////////////////////////////////////
void Stop(){
  digitalWrite(AIN1,1);
  digitalWrite(BIN1,1);
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
}
///////////////////////////////////////////////////
void Backward(){
  digitalWrite(AIN1,0);
  digitalWrite(BIN1,0);
  analogWrite(PWMA,carSpeed);
  analogWrite(PWMB,carSpeed);
}
/////////////////////////////////////////////////
void Left(){
  digitalWrite(AIN1,1);
  digitalWrite(BIN1,0);
  analogWrite(PWMA,carSpeed);
  analogWrite(PWMB,carSpeed);
}
/////////////////////////////////////////////////
void Right(){
  digitalWrite(AIN1,0);
  digitalWrite(BIN1,1);
  analogWrite(PWMA,carSpeed);
  analogWrite(PWMB,carSpeed);
}
/////////////////////////////////////////////////
void LeftForward(){
  digitalWrite(AIN1,1);
  digitalWrite(BIN1,1);
  analogWrite(PWMA,carSpeed);
  analogWrite(PWMB,carSpeed);
}
/////////////////////////////////////////////////
void LeftBackward(){
  digitalWrite(AIN1,0);
  digitalWrite(BIN1,0);
  analogWrite(PWMA,carSpeed);
  analogWrite(PWMB,carSpeed);
}
/////////////////////////////////////////////////
void RightForward(){
  digitalWrite(AIN1,1);
  digitalWrite(BIN1,1);
  analogWrite(PWMA,carSpeed);
  analogWrite(PWMB,carSpeed);
}
/////////////////////////////////////////////////
void RightBackward(){
  digitalWrite(AIN1,0);
  digitalWrite(BIN1,0);
  analogWrite(PWMA,carSpeed);
  analogWrite(PWMB,carSpeed);
}
/////////////////////////////////////////////////
void loop() {
  // put your main code here, to run repeatedly:
 
 //setting up the ultrasonic to calculate the distance and print it on serial monitor
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);

  duration = pulseIn(Echo,HIGH);
  distance = (duration/2)*0.0343;

  Serial.print("Distance = ");
  if (distance >= 50 || distance <=2){
    Serial.println("out of range");
  }
else { Serial.print(distance);
Serial.println("cm");
delay(100);
}


//set up servo with the ultrasonic to rotate and locate any obstacle in the path of the car and change the movement by rotating in adifferent direction distance limit 

 if (distance >= 50){
  Forward();
 }

 if (distance <= 20){
    Stop();
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(90);
    delay(1000);
    myservo.write(0);
    delay(1000);
  
 }

 if (distance <= 20){
    Stop();
    delay(1000);
    myservo.write(0);
    delay(1000);
  
    myservo.write(1800);
    delay(1000);
 }
if (distance <= 20){
  Left();
  delay(2000);
}

















 
  
  






}
