#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
#include <pthread.h>
#include "Sensor.h"
#include "Vibrator.h"
#include "Switcher.h"
using namespace std;

#define TRUE 1
#define TRIG1 0
#define ECHO1 1
#define TRIG2 4
#define ECHO2 5
#define PWM 6
#define VIB 3

int duration = 0;
float ave_data[6];
Sensor sensor;
//Switcher switcher;
//Vibrator vibrator;

void setup() {
	wiringPiSetup();
	sensor.setpin(TRIG1,ECHO1);
	sensor.printpin();
//	vibrator = Vibrator(VIB); 
	printf("TRIG2 pin must start LOW\n");
	digitalWrite(TRIG2, LOW);

	delay(30);
}

void switch_c(int num){
	while (num < 6){
		switch (num){
		case 0:
//			ave_data[0] = sensor[0].getdistance();
			break;

		default:
			break;
		}
	}
}

int main(void) {
	//	printf("Start\n");
	setup();
	float distance[6];
	double precise = 0;
	double data = 0;
	while (1){
		delay(100);
		
	}
	digitalWrite(VIB, LOW);
	digitalWrite(TRIG2, LOW);
	return 0;
}