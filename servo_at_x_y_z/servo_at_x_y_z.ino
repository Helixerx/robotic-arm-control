#include<Servo.h>
int ServoPin1 = 1;
int ServoPin2 = 3;
Servo myservo1;
Servo myservo2;
int a,b;

void setup(){
 Serial.begin(9600);
 myservo1.attach(ServoPin1);
 myservo2.attach(ServoPin2);

 #define l1 13.6 
#define l2   12.0
}
 void movetoPos(int x,int  y)
 {

 float q1 = acos((x*x + y*y - l1*l1 - (l2)*(l2))/(2*(l1)*(l2)));
 float q2 = atan(y/x) - atan((l2*sin(q1))/(l1 + l2*cos(q1)));


myservo1.write(q2);
myservo2.write(q1);
 }

void loop(){
 Serial.println("What is x?");
 while(Serial.available() == 0){

 }
 a = Serial.parseInt();
 delay(250);
 Serial.println("What is y?");
 while(Serial.available() == 0){

 }
 b = Serial.parseInt();
 delay(250);
 
movetoPos(a,b);
}





