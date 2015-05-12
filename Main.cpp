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
Sensor sensor[6];
Switcher switcher;
Vibrator Vibrator[3];

void setup() {
	wiringPiSetup();
	pinMode(trigger, OUTPUT);

	printf("TRIG2 pin must start LOW\n");
	digitalWrite(trigger, LOW);
	digitalWrite(TRIG2, LOW);

	delay(30);
}

void switch_c(int num){
	int i = 0;
	while (num < 6){
<<<<<<< HEAD
		switch (num){
=======
		switch (num + 1){
>>>>>>> origin/master
		case 0:
			ave_data[0] = sensor[0].getdistance();
			break;
<<<<<<< HEAD
		default:
			break;
=======
		case 1:
		}
>>>>>>> origin/master
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
		if (precise <= 150 && precise > 100)
		duration = 100;
		else if (precise <= 100 && precise > 50)
		duration = 200;
		else if (precise <= 50 && precise > 25)
		duration = 500;
		else if (precise <= 25)
		duration = 700;
		printf("%f,%f,%f\n", distance[0],distance[3],precise);
	}
	digitalWrite(VIB, LOW);
	digitalWrite(trigger, LOW);
	digitalWrite(TRIG2, LOW);
	pthread_exit(NULL);
	return 0;
}