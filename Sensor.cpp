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
	delayMicroseconds(10);
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
	
	data3 = data2;
	data2 = data1;
	data1 = distance;
	cout<<distance<<" ,";

//	precise = median(data + 0, data + sizeof(data) / sizeof(data[0]));
	precise = median(data1,data2,data3);
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

int Sensor::find_max(double i1,double i2,double i3){
	if(i1>i2)
	    if(i1>i3)
			return 1;
	if(i3>i2)
	    return 3;
	return 2;
}

int Sensor::find_min(double i1,double i2,double i3){
	if(i1<i2)
	    if(i1<i3)
			return 1;
	if(i3<i2)
	    return 3;
	return 2;
}

double Sensor::median(double i1,double i2,double i3){
	double max=find_max(i1,i2,i3);
	double min=find_min(i1,i2,i3);
	if(min+max ==4) return i2;
	else if(min+max ==5) return i1;
	else return i3;	
}

void Sensor::printpin(){
	cout<<echo<<","<<trig<<endl;
}

