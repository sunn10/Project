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
public:
	void switchpin(int, int,int);
	void switchpin(int);
};

#endif