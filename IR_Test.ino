#include <IRremote.h>
#define RECV_PIN  11


IRrecv irrecv(RECV_PIN);
decode_results results;
unsigned long key_value = 0;

void setup(){
  Serial.begin(9600);
  irrecv.enableIRIn();
  irrecv.blink13(true);
}

void loop(){
  if (irrecv.decode(&results)){
 
        if (results.value == 0XFFFFFFFF)
          results.value = key_value;

        switch(results.value){
          case 0XFF18E7:
          Serial.println("UP");
          delay(200);
          break;
          case 0XFF4AB5:
          Serial.println("DOWN");
          delay(200);
          break;
          case 0XFF10EF:
          Serial.println("LEFT");
          delay(200);break;
          case 0XFF5AA5:
          Serial.println("RIGHT");
          delay(200);break;
          case 0XFF38C7:
          Serial.println("OK");
          break ;  
          case 0XFF9867:
          Serial.println("0");
          break ;               
          case 0XFFB04F:
          Serial.println("#");
          break ;  
          case 0XC101E57B:
          Serial.println("*");
          break ;
          case 0XFFA25:
          Serial.println("1");
          break ;
          case 0XFF629D:
          Serial.println("2");
          break ;
          case 0XFFE21D:
          Serial.println("3");
          break ;
          case 0XFF22DD:
          Serial.println("4");
          break ;
          case 0XFF02FD:
          Serial.println("5");
          break ;
          case 0XFFC23D:
          Serial.println("6");
          break ;
          case 0XFFE01F:
          Serial.println("7");
          break ;
          case 0XFFA857:
          Serial.println("8");
          break ;
          case 0XFF906F:
          Serial.println("9");
          break ;      
        }
        key_value = results.value;
        irrecv.resume(); 
  }
}
