#ifndef VIBRATOR_H
#define VIBRATOR_H
#include <iostream>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
using namespace std;

class Vibrator{
private:
	int pin;
	int duration;
	int pwmRange;
public:
	Vibrator(){};
	void setpin(int p);
	void setDuration(int dur);
};

#endif