#include<Servo.h>
#include<math.h>
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
#define x 3
#define y 4

}
void forward()
{


float q1 = acos(((x+3)*(x+3) + y*y - l1*l1 - (l2)*(l2))/(2*(l1)*(l2)));
 float q2 = atan(y/(x+3)) - atan((l2*sin(q1))/(l1 + l2*cos(q1)));
myservo1.write(q2);
myservo2.write(q1);
}
void backward()
{


float q1 = acos(((x-3)*(x-3) + y*y - l1*l1 - (l2)*(l2))/(2*(l1)*(l2)));
 float q2 = atan(y/(x-3)) - atan((l2*sin(q1))/(l1 + l2*cos(q1)));
myservo1.write(q2);
myservo2.write(q1);
}
void upward()
{

float q1 = acos(((x)*(x) + (y+3)*(y+3) - l1*l1 - (l2)*(l2))/(2*(l1)*(l2)));
 float q2 = atan((y+3)/(x)) - atan((l2*sin(q1))/(l1 + l2*cos(q1)));
myservo1.write(q2);
myservo2.write(q1);
}
void downward()
{

float q1 = acos(((x)*(x) + (y-3)*(y-3) - l1*l1 - (l2)*(l2))/(2*(l1)*(l2)));
 float q2 = atan((y-3)/(x)) - atan((l2*sin(q1))/(l1 + l2*cos(q1)));
myservo1.write(q2);
myservo2.write(q1);
}
void loop(){
if(Serial.available()==0){

}

while(Serial.available() == 0){

 }
 char s = Serial.parseInt();
 if(Serial.read()=='A')
 {
   forward();
 }
 if(Serial.read()=='S')
 {
   backward();
 }
 if(Serial.read()=='D')
 {
   upward();
 }
 if(Serial.read()=='W')
 {
   downward();
 }



}

