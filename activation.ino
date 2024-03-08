#define BLYNK_TEMPLATE_ID "TMPL6oC_lxeYu"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "efblPM8LVaDQXPcXJC7WjWynTCvP4pih"

#define BLYNK_PRINT Serial
#include <OneWire.h>
#include <SPI.h>
#include <BlynkSimpleEsp8266.h>
#include <DHT.h>
#include <DallasTemperature.h>
#define ONE_WIRE_BUS D2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
char auth[] ="efblPM8LVaDQXPcXJC7WjWynTCvP4pih";
char ssid[] = "DELL";
char pass[] = "12345678";

#define DHTPIN SS
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
SimpleTimer timer;
void sendSensor()
{
float h = dht.readHumidity();
float t = dht.readTemperature();


if (isnan(h) || isnan(t)) {
Serial.println("Failed to read from DHT sensor!");
return;
}



Blynk.virtualWrite(V5, h); //V5 is for Humidit
Blynk.virtualWrite(V6, t); //V6 is for Temperature
}

void setup()
{
Serial.begin(9600);
dht.begin();

timer.setInterval(1000L, sendSensor);
Blynk.begin(auth, ssid, pass);
sensors.begin();
}
int sensor=0;
int output=0;

void sendTemps()
{
sensor=analogRead(A0);
int moisture=analogRead(A0);
output=(145-map(sensor,0,1023,0,100)); //in place 145 there is 100(it change with the change in sensor)
delay(1000);
sensors.requestTemperatures();
float temp = sensors.getTempCByIndex(0);
Serial.println(temp);
Serial.print("moisture = ");
Serial.print(output);
Serial.println("%");
Blynk.virtualWrite(V1, temp);
Blynk.virtualWrite(V2,output);
delay(1000);
}


void loop()
{
  int moisture=analogRead(A0);
  Serial.println(moisture);
Blynk.run();
timer.run();
sendTemps();
}