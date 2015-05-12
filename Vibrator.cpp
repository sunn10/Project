#include "Vibrator.h"
using namespace std;

Vibrator::Vibrator(int p){
	pin=p;
	duration = 0;
	softPwmCreate (pin, 0,  pwmRange);
}

void Vibrator::setDuration(int dur){
	if(duration!=dur){
		duration = dur;
		softPwmWrite (pin, duration) ;
	}
}