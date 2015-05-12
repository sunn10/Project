#ifndef SENSOR_H
#define SENSOR_H
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
#include <pthread.h>
using namespace std;

class Sensor{
	float distance[3];
	float precise;
	int pin1, pin2;
	double data[3];
public:
	float getdistance(int trigger,int echo);
	void setpin(int n_pin1,int n_pin2);
private:
	double median(Iterator begin, Iterator end);
};

#endif