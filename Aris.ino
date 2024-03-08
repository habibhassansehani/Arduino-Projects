#define out A5

void setup() {
  Serial.begin(9600);
  pinMode(out,OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
   
  digitalWrite(out, HIGH);
  delay(2000);
  digitalWrite(out, LOW);
   delay(2000);
  // put your main code here, to run repeatedly:

}
