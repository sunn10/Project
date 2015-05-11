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
	float precise;
	int echo, trig;
	double data[3];
public:
	Sensor(int n_pin1,int n_pin2);
	float getdistance(int trigger,int echo);
private:
	template <typename Iterator>
	double median(Iterator begin, Iterator end);
};

#endif