#include <Wire.h>
#include <Servo.h>

Servo myservo1;

int IR1 = 2;
int IR2 = 4;

void setup() {
pinMode(IR1, INPUT);
pinMode(IR2, INPUT);

myservo1.attach(3);
myservo1.write(100);
}
void loop(){

if(digitalRead (IR1) == LOW){
myservo1.write(0); 
}
if(digitalRead (IR2) == LOW){
myservo1.write(0);
}
}