#ifndef PLANT_PLOT_H
#define PLANT_PLOT_H

#define RED_LED D4
#define WHITE_LED D3
#define GREEN_LED D5
#define BLUE_LED D6
#define LIGHT_SENSOR_PIN A0

int sensor_value;

void setBlueLEDformlight();

void blynk_led(int delay_time);

void getLightValue();

#endif
