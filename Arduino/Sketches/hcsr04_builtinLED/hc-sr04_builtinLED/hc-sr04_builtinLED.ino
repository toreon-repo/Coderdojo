/*
  HC-SR04 NewPing Duration Demonstration
  HC-SR04-NewPing-Duration.ino
  Demonstrates using Duration function of NewPing Library for HC-SR04 Ultrasonic Range Finder
  Displays results on Serial Monitor

  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/

// This uses Serial Monitor to display Range Finder distance readings

// Include NewPing Library
#include "NewPing.h"

// Hook up HC-SR04 with Trig to Arduino Pin 10, Echo to Arduino pin 13
// Maximum Distance is 400 cm

#define TRIGGER_PIN  11
#define ECHO_PIN     12
#define MAX_DISTANCE 400
 
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

float duration, distance;

void setup() {
  Serial.begin (9600);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
   
  duration = sonar.ping();
  
  // Determine distance from duration
  // Use 343 metres per second as speed of sound
  // Note: above is only true at specific temperature ... true distance needs to take temp and humidity into account
  
  distance = (duration / 2) * 0.0343;
  
  // Send results to Serial Monitor
  // Serial.print("Distance = ");
  if (distance >= 400 || distance <= 2) {
    Serial.println("Out of range");
  }
  else {
    // Serial.print(distance);
    // Serial.println(" cm");
    if (distance < 20) {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else {
      digitalWrite(LED_BUILTIN, LOW);
    }
    // delay(100);
  }
  delay(1000);
}
