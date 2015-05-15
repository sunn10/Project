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
	float precise;
	void printpin();
	void setpin(int n_echo, int n_trig);
protected:
	template <typename Iterator>
	double median(Iterator begin, Iterator end);
	int find_max(double i1,double i2,double i3);
	int find_min(double i1,double i2,double i3);
	double median(double i1,double i2,double i3);
	int echo, trig;
	double data1;
	double data2;
	double data3;
};

#endif