#include <Servo.h>
Servo myservo;

void setup() {
  int pos=0;
  pinMode(2,INPUT);              // exit pressure-plate
  pinMode(7,INPUT);              // enter pressure-plate
  pinMode(9,OUTPUT);
  myservo.attach(11);            // servo to block or allow the door to open
  Serial.begin(2000000);
  for (pos=180;pos>=0;pos-=1) {  // goes from 180 degrees to 0 degrees
    myservo.write(pos);          // tell servo to go to position in variable pos
  };
  myservo.write(90);   
}
int person_enter=0;
int max=3;                       // the limit of people allowed in the area
void loop() {
	int pos=0;
	int d=14;
  delay(5);
  if(person_enter<0){
    person_enter=0;
  };
  if(digitalRead(7)==1){
    person_enter=person_enter+1; // someone entered
    delay(600);
    if(person_enter>max-1){      // checks if reached limit of people allowed in the area
      myservo.write(0);
      delay(d);
    };
	};
  if(digitalRead(2)==1){
    person_enter=person_enter-1; // someone left
    delay(600);
    if(person_enter<max){        // checks if below the limit of people allowed in the area
      myservo.write(90);
      delay(d);
    };
  };
}




