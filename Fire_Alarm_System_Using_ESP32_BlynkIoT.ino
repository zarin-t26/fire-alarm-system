#define BLYNK_TEMPLATE_ID "YourTemplateID"
#define BLYNK_TEMPLATE_NAME "Fire Detection"
#define BLYNK_AUTH_TOKEN "YourAuthToken"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

char ssid[] = "CUET-Students";        // Enter your WiFi name
char pass[] = "1020304050";    // Enter your WiFi password

int flameSensor = 4;    // D2 = GPIO4
int buzzer = 5;         // D1 = GPIO5
int greenLED = 2;       // D0 = GPIO2
int redLED = 18;        // GPIO18

void setup() {
  Serial.begin(115200);

  pinMode(flameSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();

  int fireStatus = digitalRead(flameSensor);

  if (fireStatus == LOW) { // Fire detected
    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);

    Blynk.logEvent("fire_alert", "🔥 Fire Detected!");
    Blynk.virtualWrite(V0, "🔥 Fire Detected!");
    delay(1000); // Small delay to prevent spamming alerts
  } else {
    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);

    Blynk.virtualWrite(V0, "✅ Normal");
  }

  delay(500);
}