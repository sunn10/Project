#ifndef VIBRATOR_H
#define VIBRATOR_H
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
using namespace std;

class Vibrator{
private:
	int pin;
	int duration;
	int pwmRange = 100;
public:
	void setDuration;
};

#endif