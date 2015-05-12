#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <bitset>
#include <algorithm>
#include <pthread.h>
#include <String>
#include "Switcher.h"
using namespace std;

Switcher::Switcher(int pin1, int pin2, int pin3){
	a = pin1;
	b = pin2;
	c = pin3;
	pinMode(a, OUTPUT);
	pinMode(b, OUTPUT);
	pinMode(c, OUTPUT);
}

void Switcher::switchpin(int pin){
	string binary = bitset<3>(pin).to_string();
	digitalWrite(c, (int)binary[0] - '0');
	digitalWrite(b, (int)binary[1] - '0');
	digitalWrite(a, (int)binary[2] - '0');
}