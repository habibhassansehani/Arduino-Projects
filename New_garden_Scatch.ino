// this is new garden Scatch

/*===============code written by Habib Hassan in CCO Computer lab on 5th Dec,2023 ================*/
#define BLYNK_TEMPLATE_ID "TMPL6sRazXqVI"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "XxxTnr0vaQieMxovzx3ClYrSz-TGGEJF"
#define relay D5 //relay pin
int r_v;// value read by loop from blynk cloud


#define BLYNK_PRINT Serial
#include <OneWire.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS D2
#define Light D3
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

char auth[] ="XxxTnr0vaQieMxovzx3ClYrSz-TGGEJF";
char ssid[] = "DELL";
char pass[] = "12345678";



int water; //random variable 



int sensorPin = A0; //moisture sensor pin 
int sensorValue;  //value read by moisture sensor
int limit = 200;

#define moisture_pin A0  
int moisture;  
void loop();


#define DHTPIN D6   // dht senor signal pin 
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

void setup() {
   Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
 // Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
   dht.begin();


  pinMode(relay, OUTPUT);   //output pin for relay board, this will sent signal to the relay
  pinMode(A0,INPUT); //input pin coming from soil sensor
}

















void loop() {
  //r_v= Blynk.virtualRead(V1);
   // r_v = Blynk.virtualRead(V1);
  // if (value== HIGH) {
  //   // Button is pressed, turn on the light
  //   digitalWrite(relay, HIGH);
  // } else {
  //   // Button is released, turn off the light
  //   digitalWrite(relay, LOW);
  // }
  // Wait a few seconds between measurements.
  delay(2000);



  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  water = digitalRead(A0);  // reading the coming signal from the soil sensor

Blynk.virtualWrite(V5, h); //V5 is for Humidit
Blynk.virtualWrite(V6, t); //V6 is for Temperature
//  Serial.print(water);


   sensorValue = analogRead(sensorPin); 
 Serial.println("Moisture : ");
 Serial.println(sensorValue);
 Blynk.virtualWrite(V2,sensorValue); //V2 for sensor value


if(sensorValue < 600)
{
  Serial.println("Motor is off");
digitalWrite(relay, LOW);// turn relay OFF  
Blynk.virtualWrite(V1,0); //V1 FOR MOTOR
} else 
{
  Serial.println("Motor is on");  
  digitalWrite(relay,HIGH);// turn relay ON
  Blynk.virtualWrite(V1,1); //V1 is for MOTOR
  
}
 
 delay(500); 
}
 


