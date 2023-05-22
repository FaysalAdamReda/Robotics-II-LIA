///////// IR REMOTE CODES //////////
#define F 16736925  // FORWARD
#define B 16754775  // BACK
#define L 16720605  // LEFT
#define R 16761405  // RIGHT
#define S 16712445  // STOP
#define UNKNOWN_F 5316027     // FORWARD
#define UNKNOWN_B 2747854299  // BACK
#define UNKNOWN_L 1386468383  // LEFT
#define UNKNOWN_R 553536955   // RIGHT
#define UNKNOWN_S 3622325019  // STOP


#define C1 7
#define C2 5
#define B1 8
#define B2 6


#include <IRremote.h>
/*#include <Servo.h>
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position*/

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long val;
unsigned long preMillis;


void move ( bool a, int b, bool c, int d){

digitalWrite(C1, a);
digitalWrite(B1, c);

analogWrite(C2, b);
analogWrite(B2, d);
}

//////////////////////////////////////
int data = A2 ;
int latch = A0 ;
int cs = A1;
 
int datapins[4]= {13,12,A5,A4};
const byte digits[10] = {
B00111111,
B00000110,
B01011011,
B01001111,
B01100110,
B01101101,
B01111101,
B0000111,
B01111111,
B01101111,
};
 
//////////////////////////////////////////

void setup() {

 pinMode(latch, OUTPUT);
  pinMode(cs, OUTPUT);
  pinMode(data, OUTPUT);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);


//myservo.attach(10);  // attaches the servo on pin 9 to the servo object



digitalWrite(3, OUTPUT);
pinMode(3,1);
for (int i=3; i<9; i++){
pinMode (i, OUTPUT);

move( 1, 0, 1, 0);//stop, mkaes sure the cars stationary 
irrecv.enableIRIn(); //starts receiver
}
}

void loop(){
 if (irrecv.decode(&results)){ 
    preMillis = millis();
    val = results.value;
    irrecv.resume();
    switch(val){
      case F: 
      case UNKNOWN_F: move( 1, 100, 1, 100); break; //forward
      case B: 
      case UNKNOWN_B: move( 0, 100, 0, 100); break; //backward
      case L: 
      case UNKNOWN_L: move( 1, 100, 0, 100); break; // left
      case R: 
      case UNKNOWN_R: move( 0, 100, 1, 100); break; //right
      case S: 
      case UNKNOWN_S: move( 1, 0, 1, 0); break; //stop
      default: break;
    }
  }
  else{
    if(millis() - preMillis > 500){
     move( 1, 0, 1, 0);//stop
      preMillis = millis();
    }
  }
//////////////////////////////////////////////////

digitalWrite(13, HIGH);
digitalWrite(12, HIGH);
digitalWrite(A5, HIGH);
digitalWrite(A4, LOW);

digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[1]);
  digitalWrite(latch, HIGH);

////////////////////////////////////////////////////////////////////

digitalWrite(13, HIGH);
digitalWrite(12, HIGH);
digitalWrite(A5, LOW);
digitalWrite(A4, HIGH);

digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[2]);
  digitalWrite(latch, HIGH);
////////////////////////////////////////////////////////////////////

digitalWrite(13, HIGH);
digitalWrite(12, LOW);
digitalWrite(A5, HIGH);
digitalWrite(A4, HIGH);

digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[3]);
  digitalWrite(latch, HIGH);
///////////////////////////////////////////////////////////////////

digitalWrite(13, LOW);
digitalWrite(12, HIGH);
digitalWrite(A5, HIGH);
digitalWrite(A4, HIGH);

digitalWrite(latch, LOW);
  shiftOut(data, cs, MSBFIRST, digits[4]);
  digitalWrite(latch, HIGH);

////////////////////////////////////////
 /*for (pos = 0; pos <= 45; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 45; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(50);                       // waits 15 ms for the servo to reach the position
  }
*/
  
  }
