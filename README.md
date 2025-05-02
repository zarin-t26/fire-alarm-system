# 🔥 Fire Alarm System with NodeMCU, Email Alert & Blynk (v2)

This project is a simple yet effective **Fire Detection System** using a NodeMCU (ESP8266) that sends **email alerts** and uses the **Blynk IoT platform** to notify users of potential fire incidents.

## 🚀 Features

- Real-time fire detection using a flame sensor.
- Email alerts sent automatically when fire is detected.
- Blynk 2.0 integration to monitor fire status from a mobile app.
- LED indicator for visual alert.
- Buzzer for audible alert.

## 🛠️ Components Used

- NodeMCU (ESP8266)
- Flame Sensor
- Buzzer
- LED
- Resistor (220 ohm)
- Jumper wires
- Breadboard

## 🧠 How It Works

1. The flame sensor constantly monitors for the presence of fire.
2. If fire is detected (sensor output LOW), the system:
   - Activates the buzzer and LED.
   - Sends a notification through the Blynk app.
   - Sends an email alert to the user.
3. When fire is not detected, the system stays idle, checking sensor status in a loop.

## 🔌 Circuit Diagram

| Component        | NodeMCU Pin |
|------------------|-------------|
| Flame Sensor     | D2          |
| Buzzer           | D1          |
| LED              | D0          |

(Note: You can create and attach a schematic diagram for visual reference.)

## 📲 Blynk Setup

1. Download the **Blynk IoT** app from the App Store or Google Play.
2. Create a new template in Blynk 2.0 web dashboard.
3. Set up a datastream for virtual pin `V0`.
4. Copy your **Template ID**, **Device Name**, and **Auth Token**.
5. Update these credentials in the code:
   ```cpp
   #define BLYNK_TEMPLATE_ID "YourTemplateID"
   #define BLYNK_TEMPLATE_NAME "Fire Detection"
   #define BLYNK_AUTH_TOKEN "YourAuthToken"
