#define in4  //Motor2  L298 Pin in1 

void setup(){ // put your setup code here, to run once

Serial.begin(9600); // start serial communication at 9600bps
   
pinMode(in4, OUTPUT); // declare as output for L298 Pin in4
}


void loop(){  
//==============================================
digitalWrite(in4, HIGH); //Right Motor backword Pin 
delay(1500);
}