#ifndef PLANT_PLOT_H
#define PLANT_PLOT_H

#define BLUE_LED D4
#define LIGHT_SENSOR_PIN A0

int sensor_value;

void setBlueLEDformlight();

void blynk_led(int delay_time);

void getLightValue();

#endif
