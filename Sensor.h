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
	float getdistance(int,int){ return distance; }
	void setpin(int,int);
private:
	double median(Iterator, Iterator){ return *middle; }
};

#endif