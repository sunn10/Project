#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
#include <pthread.h>
#include "Vibrator.h"
using namespace std;
void Vibrator::Vibrator(int pin){
	duration =0;
	softPwmCreate (pin, 0,  pwmRange);
}
void Vibrator::*vibrate(void *threadid){
	long tid;
	tid = (long)threadid;
	while (1){
		digitalWrite(VIB, HIGH);
		delay(duration);
		digitalWrite(VIB, LOW);
		delay(1000 - duration);
	}
	pthread_exit(NULL);
}

void setDuration(int dur){
	duration = dur;
}