# IDE_code
Code for school IDE project.


# What is it?
The code is for an arduino with senses how many people have entered a room by pressure-plates located at doors where someone either enters through one door or exits through the other. The arduino will count the number of times someone has stepped on the pressure-plate and either entered or exit the room and when the limit of the number of people in the room has been reached, the arduino will turn a servo to block the door to enter so that more people cannot enter the area.


# Why this and not simply have someone keep track?
* Human memory is not always reliable


The human brain can only rember so much after it starts to forget about what it was trying to keep track of. Even if someone had very good memory and is very focused on the task, they might accidentally miss out someone or count one person more than there is.

The arduino is a microcontroller which acts upon a fixed set of rules which is much more reliable in simple tasks like counting which is better suited for our purposes. This will eliminate human error in the task and make keeping to the Safe Management Measures much easier and simpler.


# How does the code work?
The code works by checking the number of people as seen in here:


```objectivec
if(digitalRead(7)==1){
    person_enter=person_enter+1; //someone entered
    delay(600);
```


This will check if the pressure-plate has been pressed down on and the ```delay(6);``` is to make sure that the number won't just rapidly increase when someone steps on the pressure-plate for a while.


```objectivec
if(person_enter>max-1){      //Checks if reached limit of people allowed in the area
      myservo.write(0);
      delay(d);
    };
 ```


This code will check if the number of people reaches or exceeds the limit, if it does then it will activate the servo to turn and block the entery door from opening.


```objectivec
person_enter=person_enter-1; //someone left
    delay(600);
```


This part of the code checks if someone has exited the area, the delay is in place here to make sure that it registers one person at a time and not think that there is six people entering at once.



```objectivec
if(person_enter<max){        //Checks if below the limit of people allowed in the area
      myservo.write(90);
      delay(d);
    };
```

This part of the code checks if the number of people in the area is less than the maximum amount of people in the area and if the number of people in the area is below the limit then it will make the servo move and allow the entry door to be opened.
