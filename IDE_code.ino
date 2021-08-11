#include <Servo.h>
Servo myservo;

void setup() {
  int pos=0;
  pinMode(2,INPUT);
  pinMode(7,INPUT);
  pinMode(9,OUTPUT);
  myservo.attach(11);            //servo 1
  Serial.begin(2000000);
  for (pos=180;pos>=0;pos-=1) {  // goes from 180 degrees to 0 degrees
    myservo.write(pos);          // tell servo to go to position in variable pos
  };
  myservo.write(90);   
}
int person_enter=0;
int max=3;                       //The limit of people allowed in the area
void loop() {
	int pos=0;
	int d=14;
  Serial.println("---start---");
  Serial.println("")
  Serial.print("Digital Pin 7 (RED) (ENTER):  ");
  Serial.println(digitalRead(7));
  Serial.println("")
  Serial.print("Digital Pin 2 (GREEN) (EXIT): ");
  Serial.println(digitalRead(2));
  Serial.println("")
  Serial.print("No. of People: ");
  Serial.println(person_enter);
  Serial.println("")
  Serial.println("----end----");
  delay(5);
  if(person_enter<0){
    person_enter=0;
  };
	if(digitalRead(7)==1){
    person_enter=person_enter+1; //someone entered
    delay(600);
    if(person_enter>max-1){      //Checks if reached limit of people allowed in the area
      myservo.write(0);
      delay(d);
    };
	};
  if(digitalRead(2)==1){
    person_enter=person_enter-1; //someone left
    delay(600);
    if(person_enter<max){        //Checks if below the limit of people allowed in the area
      myservo.write(90);
      delay(d);
    };
  };
}


