#define enc_rev 400


volatile long int counter = 0;

 
    int t1 = 0;
    int t2 = 0;
    int diff = 0;
    int interval = 10;
    int i = 255;
    int sp ;
    float kp = 0.4;
    float rpm_right = 0;
const int motor1Pin = 6;
const int motor2Pin = 5;
const float rpm_to_radians = 0.10471975512;
void setup() {
  Serial.begin (9600);

  pinMode(2, INPUT_PULLUP); // internal pullup input pin 2 
  
  pinMode(4, INPUT_PULLUP);
  pinMode(motor1Pin, OUTPUT);
  pinMode(motor2Pin, OUTPUT);// internalเป็น pullup input pin 3
  pinMode(9,OUTPUT);
//Setting up interrupt
  //A rising pulse from encodenren activated ai0(). AttachInterrupt 0 is DigitalPin nr 2 on moust Arduino.
  attachInterrupt(digitalPinToInterrupt(2), ai0, RISING);
   
  //B rising pulse from encodenren activated ai1(). AttachInterrupt 1 is DigitalPin nr 3 on moust Arduino.
 // attachInterrupt(1, ai1, RISING);
  }
   
  void loop() {
    sp = 100;
  // Send the value of counter
  if (sp>0){  	 
          digitalWrite(motor1Pin, HIGH);   
           digitalWrite(motor2Pin, LOW);
           }
     else {
   	  digitalWrite(motor1Pin, LOW);   
       digitalWrite(motor2Pin, HIGH);
       }
    
    t1=millis();
    analogWrite(9,i);
  if((t1 - t2)>10)
  {
    t2 = t1;
  
    rpm_right = (float)(counter*60/enc_rev);
     Serial.println(fabs(rpm_right));
     counter = 0;

  }
    if (Serial.available() == 0){
  
  String val = Serial.readString();
     sp = val.toInt();
  }
     diff=kp*(100-fabs(rpm_right));
             if (fabs(rpm_right)==100)
             {
               i=i;
             }
             else {
               i=i+diff;
             }
             
}

  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
void ai0() {
  // ai0 is activated if DigitalPin nr 2 is going from LOW to HIGH
  // Check pin 3 to determine the direction
  if(digitalRead(3)==LOW) {
  counter++;
  }else{
  counter--;
  }
  }
