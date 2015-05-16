#ifndef CALIBRATE_H
#define CALIBRATE_H
#include <iostream>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
#include "Sensor.h"
using namespace std;

class Calibrate:public Sensor{
private:
	double save_precise;
	double detect_distance;
	
	double dif_distance(double precise);
public:
	Calibrate(){};
	int getwarn();
	void setup();
};

#endif