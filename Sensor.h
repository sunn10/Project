#ifndef SENSOR_H
#define SENSOR_H
#include <iostream>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
#include <pthread.h>
using namespace std;

class Sensor{
public:
	Sensor(){};
	double getdistance();
	void printpin();
	void setpin(int n_echo, int n_trig);
private:
	template <typename Iterator>
	double median(Iterator begin, Iterator end);
	float precise;
	int echo, trig;
	double data[3];
};

#endif