#ifndef SWITCHER_H
#define SWITCHER_H
#include <iostream>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
#include <pthread.h>
using namespace std;

class Switcher{
	
public:
	Switcher(int pin1, int pin2, int pin3);
	void switchpin(int num);
private:
	string DecimalToBinaryString(int a)
	int a, b, c;
};

#endif