#include "plant_plot.h"


void blynk_led(int delay_time) {
  digitalWrite(BLUE_LED, HIGH);
  delay(delay_time - 100);
  digitalWrite(BLUE_LED, LOW);
  delay(delay_time - 900);
}

void getLightValue(){
  sensor_value = analogRead(LIGHT_SENSOR_PIN);
  Serial.println(sensor_value);
  delay(500);
}

void setBlueLEDformlight(){
  if(sensor_value > 700){
    digitalWrite(BLUE_LED, HIGH);
    }
  else{
    digitalWrite(BLUE_LED, LOW);
    }
}

void setup() {
  // put your setup code here, to run once: 
  pinMode(BLUE_LED, OUTPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
  sensor_value = 0;
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //blynk_led(1000);
  setBlueLEDformlight();
  getLightValue();
}
