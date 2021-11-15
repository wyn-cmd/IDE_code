# IDE_code
Code for Greendale Secondary School IDE Maker project.


# What is it?
The code is for an arduino with senses how many people have entered a room by pressure-plates located at doors where someone either enters through one door or exits through the other. The arduino will count the number of times someone has stepped on the pressure-plate and either entered or exit the room and when the limit of the number of people in the room has been reached, the arduino will turn a servo to block the door to enter so that more people cannot enter the area.


# Why this and not simply have someone keep track?
* Human memory is not always reliable


The human brain can only remeber so much after it starts to forget about what it was trying to keep track of. Even if someone had very good memory and is very focused on the task, they might accidentally miss out someone or count one person more than there is.

The arduino is a microcontroller which acts upon a fixed set of rules which is much more reliable in simple tasks like counting which is better suited for our purposes. This will eliminate human error in the task and make keeping to the Safe Management Measures much easier and simpler.


* people can take a lot of money to hire


With paying humans to keep track of the number of people, you have to pay them for how long they keep track and as more time passes, you end up paying a large sum of money just to keep track of people in an area. The arduino is relativly cheap with some implementations using an Arduino Nano costing around a few dollars which is a one time cost and thanks to the low power consumption of the arduino, electricity costs aren't much of an issue.


# How does the code work?
The code works by checking the number of people as seen in here:


```objectivec
if(digitalRead(7)==1){
    // someone entered
    person_enter=person_enter+1; 
    delay(600);
```


This will check if the pressure-plate has been pressed down on and the `delay(600);` is to make sure that the number won't just rapidly increase when someone steps on the pressure-plate for a while.


```objectivec
// checks if reached limit of people allowed in the area
if(person_enter>max-1){      
      myservo.write(0);
      delay(d);
    };
 ```


This code will check if the number of people reaches or exceeds the limit, if it does then it will activate the servo to turn and block the entery door from opening.


```objectivec
// someone left
person_enter=person_enter-1; 
    delay(600);
```


This part of the code checks if someone has exited the area, the delay is in place here to make sure that it registers one person at a time and not think that there is six people entering at once.



```objectivec
// checks if below the limit of people allowed in the area
if(person_enter<max){        
      myservo.write(90);
      delay(d);
    };
```

This part of the code checks if the number of people in the area is less than the maximum amount of people in the area and if the number of people in the area is below the limit then it will make the servo move and allow the entry door to be opened.



## Serial
The ```Serial.begin``` in the code is used to check if the variables in the code and the arduino are working, if one does not activate the Serial Monitor then the code will not run. Hence, there is a version of the code that has no `Serial.begin;` and will be able to run with the parts and power source connected.

                by Wynston Wong Jun De
