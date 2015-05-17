#include "Calibrate.h"
#define DANGER 10
using namespace std;

double Calibrate :: dif_distance(double precise){
	detect_distance = precise - save_precise;
	return detect_distance;
}

int Calibrate :: getwarn(){
	double dis = getdistance();
	double difdis = dif_distance(dis);
//	cout<< dis<<", "<<difdis<<endl;
	 if(difdis>DANGER) return 1;	 
	 else if (difdis<-DANGER) return -1;
	 else return 0;
}

void Calibrate ::  setup(){
	getdistance();
	getdistance();
	save_precise = getdistance();
//	cout<<save_precise<<endl;
}