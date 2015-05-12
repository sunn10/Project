#ifndef SWITCHER_H
#define SWITCHER_H
#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
#include <pthread.h>
using namespace std;

class Switcher{
	int a, b, c;
public:Switcher(int pin1, int pin2, int pin3)
	void switchpin(int pin);
};

#endif