#include "Sensor.h"
#include "Vibrator.h"
#include "Switcher.h"
#include "Calibrate.h"
using namespace std;

#define TRUE 1
#define TRIG1 2
#define ECHO1 3

#define A 4
#define B 5
#define C 7
#define VIB1 12
#define VIB2 13
#define VIB3 14

int duration = 0;
//float ave_data[6];
Sensor *sensor;
Switcher switcher;
Vibrator vibrator[3];
Calibrate calibrate;

void setup() {
	wiringPiSetup();
	pinMode(ECHO1, INPUT);
	pinMode(TRIG1, OUTPUT);
	digitalWrite(TRIG1, LOW);
	calibrate.setpin(TRIG1,ECHO1);
	
	sensor = new Sensor[6];
	for(int i=0;i<6;i++){
		sensor[i].setpin(TRIG1,ECHO1);
	}
	
//	vibrator[0].setpin(VIB);
	switcher.setpin(A,B,C);
	switcher.switchpin(5);
	calibrate.setup();
	vibrator[0].setpin(VIB1);
	vibrator[1].setpin(VIB2);
	vibrator[2].setpin(VIB3); 
//	digitalWrite(TRIG1, LOW);

	delay(5);
}

int main(void) {
	//	printf("Start\n");
	setup();
//	float distance[6];
	double precise = 0;
//	double data = 0;
	while (1){
		
		for(int i=0;i<6;i++){
			switcher.switchpin(i);
			
			delay(5);
			if(i<5){
				precise = sensor[i].getdistance();
				cout<<i<<"-"<<endl;
				if(i==0){
					if (precise <= 150 && precise > 100)
						vibrator[0].setDuration(100);
					else if (precise <= 100 && precise > 50)
						vibrator[0].setDuration(200);
					else if (precise <= 50 && precise > 25)
						vibrator[0].setDuration(500);
					else if (precise <= 25)
						vibrator[0].setDuration(700);
				} 
				delay(1);
			}
			else{
				cout<<i<<"-"<<calibrate.getwarn()<<endl;
			}
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

		delete[] sensor;

	return 0;
}