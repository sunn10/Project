#include "Sensor.h"
#include "Vibrator.h"
#include "Switcher.h"
using namespace std;

#define TRUE 1
#define TRIG1 2
#define ECHO1 3
#define TRIG2 
#define ECHO2 
#define VIB 7
#define A 4
#define B 5
#define C 6

int duration = 0;
//float ave_data[6];
Sensor sensor[6];
Switcher switcher;
Vibrator vibrator[3];

void setup() {
	wiringPiSetup();
	sensor[0].setpin(TRIG1,ECHO1);
	vibrator[0].setpin(VIB);
	switcher.setpin(A,B,C);
	switcher.switchpin(0);
//	sensor[0].printpin();
//	vibrator = Vibrator(VIB); 
//	digitalWrite(TRIG1, LOW);

	delay(10);
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
//	float distance[6];
	double precise = 0;
//	double data = 0;
	while (1){
		delay(10);
		precise = sensor[0].getdistance();
		cout<<precise<<endl;
		if (precise <= 150 && precise > 100)
			vibrator[0].setDuration(100);
		else if (precise <= 100 && precise > 50)
			vibrator[0].setDuration(200);
		else if (precise <= 50 && precise > 25)
			vibrator[0].setDuration(500);
		else if (precise <= 25)
			vibrator[0].setDuration(700); 
	}
	return 0;
}