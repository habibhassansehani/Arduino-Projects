#define BLYNK_TEMPLATE_ID "TMPL6oC_lxeYu"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "Dz1d54lzKK0PlsJ_wxzSDiQ1T8ziI1hl"


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Replace these with your WiFi credentials and Blynk Auth Token
char auth[] = "Dz1d54lzKK0PlsJ_wxzSDiQ1T8ziI1hl";
char ssid[] = "DELL";
char pass[] = "12345678";

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
}

void loop() {
  Blynk.run();
}
