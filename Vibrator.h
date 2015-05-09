#ifndef VIBRATOR_H
#define VIBRATOR_H
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
#include <pthread.h>
using namespace std;

class Vibrator{
	
public:
	void *vibrate(void *int);
};

#endif