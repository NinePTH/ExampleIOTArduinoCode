#include "plant_plot.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
float analogPin = A0;
float val = 0;
float per = 0;

#define BLYNK_TEMPLATE_ID "TMPL8Ms5jeH_"
#define BLYNK_DEVICE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "OO3idLQwEksycpX_OOCect9lDUklUXsE"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "AndroidAPED3F";
char pass[] = "ckkz7752";

//BLYNK_WRITE(V3)
//{
//  int s0 = param.asInt(); // parameter as int
//  if(s0 == HIGH)
//  {
//    digitalWrite(WHITE_LED,HIGH);
//    delay(10);
//    }
//    if(s0 == LOW)
//  {
//    digitalWrite(WHITE_LED,LOW);
//    delay(10);
//    }
//}

void setRedLEDformlight(){
  if(per < 30){
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    }
  else{
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    }
}

//void setBlueLEDformlight(){
//  if((per >= 20) && (per <=60)){
//    digitalWrite(RED_LED, LOW);
//    digitalWrite(BLUE_LED, HIGH);
//    digitalWrite(GREEN_LED, LOW);
//    }
//  else{
//    digitalWrite(RED_LED, LOW);
//    digitalWrite(BLUE_LED, LOW);
//    digitalWrite(GREEN_LED, LOW);
//    }
//}
//
//void setGreenLEDformlight(){
//  if(per > 60){
//    digitalWrite(RED_LED, LOW);
//    digitalWrite(BLUE_LED, LOW);
//    digitalWrite(GREEN_LED, HIGH);
//    }
//  else{
//    digitalWrite(RED_LED, LOW);
//    digitalWrite(BLUE_LED, LOW);
//    digitalWrite(GREEN_LED, LOW);
//    }
//}

void setup() {
  // put your setup code here, to run once:
  pinMode(RED_LED, OUTPUT);
  per = 0;
  lcd.init();
  lcd.backlight();
  Blynk.begin(auth, ssid, pass);
//  pinMode(WHITE_LED,OUTPUT);
//  digitalWrite(WHITE_LED,LOW);
}
BLYNK_CONNECTED(){
  lcd.setCursor(9,1);
  lcd.print("ONLINE");
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(analogPin);
  per = 100-(val*100)/1024;

  Blynk.run();
  Blynk.virtualWrite(V1, val);
  Blynk.virtualWrite(V2, per);
  
  lcd.setCursor(0,0);
  lcd.print("Smart Plant Pot");
  lcd.setCursor(0,1);
  lcd.print(100-(val*100)/1024);
  lcd.setCursor(4,1);
  lcd.print(" %");
  delay(500);
  setRedLEDformlight();
//  setGreenLEDformlight();
//  setBlueLEDformlight();
}
