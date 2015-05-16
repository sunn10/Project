#include "Calibrate.h"
#include <cmath> 
using namespace std;

double Calibrate :: dif_distance(double precise){
	save_precise = precise;
	detect_distance = abs(precise - save_precise);
	return detect_distance;
}

int Calibrate :: getwarn(){
	double dis = getdistance();
	double difdis = dif_distance(dis);
	cout<< dis<<", "<<difdis<<endl;
	 if(difdis<10){
		 return 0;
	 }
	 else return 1;
}

void Calibrate ::  setup(){
	getdistance();
	getdistance();
	save_precise = getdistance();
	cout<<save_precise<<endl;
}