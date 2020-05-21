//including libraries
#include <EspMQTTClient.h>
#include <ESP8266WiFi.h>
#include <Servo.h>

#include "OLED_SCREEN.h"
#include "CREDENTIALS.h"
#include "RECEIVE.h"

#define GREEN_LED 12    //D6
#define RED_LED 13      //D7
#define LED_Strip 14      //D5

int Strength;
int Power;

unsigned long time_now;

void onConnectionEstablished();

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  analogWrite(LED_BUILTIN, 0);
  Serial.begin(115200);
  pinMode(motorPinRightDir, OUTPUT);
  pinMode(motorPinRightSpeed, OUTPUT);
  My_servo.attach(2); //D4
  My_servo.write(90);
  digitalWrite(RED_LED, HIGH);
  analogWrite(LED_Strip, 1024);
}


void loop() {
  client.loop();

}
