#include "Sensor.h"
using namespace std;

void Sensor::setpin(int n_trig, int n_echo){
	echo = n_echo;
	trig = n_trig;
	pinMode(echo, INPUT);
	pinMode(trig, OUTPUT);
	digitalWrite(trig, LOW);
}

double Sensor::getdistance(){
	//	printf("Send TRIG2 pulse\n");
	digitalWrite(trig, HIGH);
	delayMicroseconds(15);
	digitalWrite(trig, LOW);

	//	printf("Wait for ECHO2 start\n");
	while (digitalRead(echo) == LOW);

	//	printf("Wait for ECHO2 end\n");
	int startTime = micros();
	//printf("starttime = %d\n",startTime);
	int travelTime = 0;
	while (digitalRead(echo) == HIGH){
		if ((micros() - startTime)>23000){
			break;
		}
	}

	travelTime = micros() - startTime;
	//printf("travelTime = %d\n",travelTime);
	//printf("Get distance in cm\n");
	double distance = travelTime / 58.0;
	
	data[2] = data[1];
	data[1] = data[0];
	data[0] = distance;

	precise = median(data + 0, data + sizeof(data) / sizeof(data[0]));
	return precise;
}

// inputs must be random-access iterators of doubles
// Note: this function modifies the input range
template <typename Iterator>

double Sensor::median(Iterator begin, Iterator end) {
	// this is middle for odd-length, and "upper-middle" for even length
	Iterator middle = begin + (end - begin) / 2;

	// This function runs in O(n) on average, according to the standard
	std::nth_element(begin, middle, end);

	if ((end - begin) % 2 != 0) { // odd length
		return *middle;
	}
	else { // even length
		// the "lower middle" is the max of the lower half
		Iterator lower_middle = std::max_element(begin, middle);
		return (*middle + *lower_middle) / 2.0;
	}
}

void Sensor::printpin(){
	cout<<echo<<","<<trig<<endl;
}

