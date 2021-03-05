#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
int buzzer = D2;
int smokeA0 = A0;

// Your threshold value. You might need to change it.
int sensorThres = 400;
char auth[] = "x7qic4yAwQBY1fkaGq7QLjpEJa2Se8pZ";
char ssid[] = "noobwifi_wlink";
char pass[] = "12345zxcvb";
void setup() {
 pinMode(buzzer, OUTPUT);
 pinMode(smokeA0, INPUT);
 Blynk.begin(auth, ssid, pass);
 Serial.begin(9600);
}

void loop() {
 int analogSensor = analogRead(smokeA0);

 Serial.print("Pin A0: ");
 Serial.println(analogSensor);
 // Checks if it has reached the threshold value
 if (analogSensor > sensorThres)
 {
   Blynk.virtualWrite(V3, 255);
   Blynk.notify("Gas is leaked!!");
    tone(buzzer, 1000, 200);
 }
 else
 {
   noTone(buzzer);
 }
 delay(100);
}
