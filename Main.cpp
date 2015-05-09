#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
#include <algorithm>
#include <pthread.h>
#include "Sensor.h"
#include "Vibrator.h"
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
void setup() {
	wiringPiSetup();
	softPwmCreate(PWM, 0, 100);
	pinMode(trigger, OUTPUT);
	pinMode(echo, INPUT);
	pinMode(TRIG2, OUTPUT);
	pinMode(ECHO2, INPUT);
	pinMode(VIB, OUTPUT);

	printf("TRIG2 pin must start LOW\n");
	digitalWrite(trigger, LOW);
	digitalWrite(TRIG2, LOW);

	delay(30);
}

void switch_c (int num){
	int i = 0;
	while (num < 6){
		switch (num+1){
		case 0:
			ave_data[0] = sensor[0].getdistance();

			break;
		case 1:

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		}
	}
}

int main(void) {
	//	printf("Start\n");
	setup();
	pthread_t threads;
	pthread_create(&threads, NULL, vibrate, (void *)1);
	float distance[6];
	double precise = 0;
	double data = 0;
	while (1){
		delay(100);
		precise = median(distance + 0, distance + sizeof(distance) / sizeof(distance[0]));
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