//including libraries
#include <EspMQTTClient.h>
#include <ESP8266WiFi.h>
#include <Servo.h>
#include "CREDENTIALS.h"      //Including the tabs
#include "RECEIVE.h"

int Strength;     //defining variables
int Power;

unsigned long time_now;

void onConnectionEstablished();     //Run the onConnectionEstablished function

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);     //Shuting of the builtin led
  analogWrite(LED_BUILTIN, 0);
  Serial.begin(115200);       //Start serial monitor
  pinMode(motorPinRightDir, OUTPUT);    //Motor pinmodes
  pinMode(motorPinRightSpeed, OUTPUT);
  My_servo.attach(2); //D4      
  My_servo.write(90);       //Center Servo on start
  pinMode(LED_Strip, OUTPUT);       //Ledstrip set to output
}


void loop() {
  client.loop();      //Looping 

}
