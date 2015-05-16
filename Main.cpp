#include "Sensor.h"
#include "Vibrator.h"
#include "Switcher.h"
using namespace std;

#define TRUE 1
#define TRIG1 2
#define ECHO1 3
#define VIB 7
#define A 4
#define B 5
#define C 6

int duration = 0;
//float ave_data[6];
Sensor *sensor;
Switcher switcher;
Vibrator vibrator[3];

void setup() {
	wiringPiSetup();
	pinMode(ECHO1, INPUT);
	pinMode(TRIG1, OUTPUT);
	digitalWrite(TRIG1, LOW);
	sensor = new Sensor[6];
	for(int i=0;i<6;i++){
		sensor[i]->setpin(TRIG1,ECHO1);
	}
	vibrator[0].setpin(VIB);
	switcher.setpin(A,B,C);
	switcher.switchpin(5);
//	sensor[0].printpin();
//	vibrator = Vibrator(VIB); 
//	digitalWrite(TRIG1, LOW);

	delay(10);
}

int main(void) {
	//	printf("Start\n");
	setup();
//	float distance[6];
//	double precise = 0;
//	double data = 0;
	while (1){

		
		for(int i=0;i<6;i++){
			switcher.switchpin(i);
			delay(5);
			cout<<i<<"-"<<sensor[i]->getdistance()<<endl;
			delay(1);
//
//		delay(500);
//		digitalWrite(TRIG1, HIGH);
//		delay(500);
//		digitalWrite(TRIG1, LOW);
		}
//		cout<<2<<"-"<<sensor[2].getdistance()<<endl;
//		if (precise <= 150 && precise > 100)
//			vibrator[0].setDuration(100);
//		else if (precise <= 100 && precise > 50)
//			vibrator[0].setDuration(200);
//		else if (precise <= 50 && precise > 25)
//			vibrator[0].setDuration(500);
//		else if (precise <= 25)
//			vibrator[0].setDuration(700); 
	}
		for(int i=0;i<6;i++){
		delete sensor[i];
	
	}
	return 0;
}