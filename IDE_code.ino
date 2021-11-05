#include <Servo.h>
Servo myservo;

void setup() {
  int pos=0;
  // exit pressure-plate
  pinMode(2,INPUT);
  // enter pressure-plate
  pinMode(7,INPUT);
  pinMode(9,OUTPUT);
  // servo to block or allow the door to open
  myservo.attach(11);
  // goes from 180 degrees to 0 degrees
  for (pos=180;pos>=0;pos-=1) {
    // tell servo to go to position in variable pos
    myservo.write(pos);
  };
  myservo.write(90);   
};
int person_enter=0;
// limit of people allowed in the area
int max=3;
void loop() {
	int pos=0;
	int d=14;
  delay(5);
  if(person_enter<0){
    person_enter=0;
  };
  if(digitalRead(2)==1){
    // someone entered
    person_enter=person_enter+1; 
    delay(600);
    // checks if reached limit of people allowed in the area
    if(person_enter>max-1){      
      myservo.write(0);
      delay(d);
    };
	};
  if(digitalRead(7)==1){
    // someone left
    person_enter=person_enter-1; 
    delay(600);
    // checks if below the limit of people allowed in the area
    if(person_enter<max){
      myservo.write(90);
      delay(d);
    };
  };
}
