#include "Vibrator.h"
using namespace std;

void Vibrator::setpin(int p){
	pin=p;
	duration = 0;
	pwmRange=1000;
	softPwmCreate (pin, 0,  pwmRange);
}

void Vibrator::setDuration(int dur){
	if(duration!=dur){
		duration = dur;
		softPwmWrite (pin, duration) ;
	}
}