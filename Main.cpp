#include "Sensor.h"
#include "Vibrator.h"
#include "Switcher.h"
using namespace std;

#define TRUE 1
#define TRIG1 4
#define ECHO1 5
#define TRIG2 4
#define ECHO2 5
#define VIB 6

int duration = 0;
//float ave_data[6];
Sensor sensor;
//Switcher switcher;
//Vibrator vibrator;

void setup() {
	wiringPiSetup();
	sensor.setpin(TRIG1,ECHO1);
	sensor.printpin();
//	vibrator = Vibrator(VIB); 
	cout<<"TRIG2 pin must start LOW\n";
	digitalWrite(TRIG1, LOW);

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
//	float distance[6];
//	double precise = 0;
//	double data = 0;
	while (1){
		delay(100);
		cout<<sensor.getdistance()<<endl;
	}
	return 0;
}