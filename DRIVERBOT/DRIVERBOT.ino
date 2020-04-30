//including libraries
#include <EspMQTTClient.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

#include "OLED_SCREEN.h"
#include "CREDENTIALS.h"
#include "RECEIVE.h"

unsigned long time_now;

void onConnectionEstablished();

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  analogWrite(LED_BUILTIN, 0);
  Serial.begin(115200);
  pinMode(motorPinRightDir, OUTPUT);
  pinMode(motorPinRightSpeed, OUTPUT);
  My_servo.attach(2); //D4
  My_servo.write(90);
  
}


void loop() {
  client.loop();

  if (millis() > time_now + 2000){
   oledScreen();                                     //Looping the getTemperature every 2 seconds
   time_now = millis();
}

}
