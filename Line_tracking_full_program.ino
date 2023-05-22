//Line Tracking IO define
#define LT_R analogRead(A0)
#define LT_M analogRead(A1)
#define LT_L analogRead(A2)

// motor pins define
int AIN1 = 7;
int PWMA = 5;
int BIN1 = 8;
int PWMB = 6;
int senL;
int senR;
int senM;
// speed set define
#define carSpeed 100





void setup() {
  // set in puts and outputs for the pins
for (int i=3; i<9; i++){
pinMode(i, OUTPUT);
  }
  digitalWrite(3,1);
  pinMode(LT_R, INPUT);
  pinMode(LT_M, INPUT);
  pinMode(LT_L, INPUT);
  Serial.begin(9660);
}

// set up functions for all the different movements/ direction and speed

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
// setting up the sensor to read the black tape line based on the bit value corresponding to it 
//  it will follow the line and when the line ends will search for line using rotation movement  
if (LT_M >100 && LT_M<300){
  Forward();
}
if (LT_L >350 && LT_L<550){
  Left();
}
if (LT_R >600 && LT_R<850){
  Right();
}
else if (LT_L<60 && LT_M<60 && LT_R<60 ){
  Left();
}
else if (LT_L>1000 && LT_M>1000 && LT_R>1000 ){
  Stop();
}
// serial monitor print to verify bit values
senL = analogRead(A2);
senR = analogRead(A0);
senM = analogRead(A1);

 Serial.print(senL);
Serial.print("\t");
 Serial.print(senM);
Serial.print("\t");
Serial.println(senR);



//  Serial.print(LT_M);
// Serial.print("\t");
//  Serial.print(LT_R);
//  Serial.print("\t");
//  Serial.println(LT_L);
  
  
}
