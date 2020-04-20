//including libraries
#include <EspMQTTClient.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

//Defining pins
#define motorPinRightDir  0//D3
#define motorPinRightSpeed 5//D1

void onConnectionEstablished();

Servo My_servo;

EspMQTTClient client(
 "Harleys iPhone",             // Wifi ssid  ABB_Indgym_Guest
  "hejhoj123",                 // Wifi password   Welcome2abb
  "maqiatto.com",              // MQTT broker ip
  1883,                        // MQTT broker port
  "harley@berglun.se",         // MQTT username
  "HEJHEJ",                    // MQTT password
  "Node",                      // Client name
  onConnectionEstablished,     // Connection established callback
  true,                        // Enable web updater
  true                         // Enable debug messages
);

void setup(){
  pinMode(LED_BUILTIN, OUTPUT);
  analogWrite(LED_BUILTIN, 0);
  Serial.begin(115200);
  pinMode(motorPinRightDir, OUTPUT);
  pinMode(motorPinRightSpeed, OUTPUT);
  My_servo.attach(2); //D4
  My_servo.write(90);
}

void onConnectionEstablished(){
  client.subscribe("harley@berglun.se/motor", [] (const String &payload1){    
    int Power = payload1.substring(1, payload1.indexOf(',')).toInt();
    int Strength = payload1.substring(payload1.lastIndexOf(',') + 1).toInt();   

    //Serial.println(Strength);
    //Serial.println(Power);
    digitalWrite(motorPinRightDir, Power);
    analogWrite(motorPinRightSpeed, Strength);
  });

    client.subscribe("harley@berglun.se/servo", [] (const String &payload2){    
    int SERVO = payload2.substring(1, payload2.indexOf(',')).toInt();

    //Serial.println(SERVO);
    My_servo.write(SERVO);
  });
  }


void loop(){
    client.loop();
}
