#include "Calibrate.h"
using namespace std;

double Calibrate :: dif_distance(double precise){
	save_precise = precise;
	detect_distance = precise - save_precise;
	return detect_distance;
}

int Calibrate :: getwarn(){
	 if(dif_distance(getdistance())<10){
		 return 0;
	 }
	 else return 1;
}

void Calibrate ::  setup(){
	getdistance();
	getdistance();
	save_precise = getdistance();
}