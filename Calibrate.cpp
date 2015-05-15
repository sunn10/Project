#include "Calibrate.h"
using namespace std;

double Calibrate :: dif_distance(double precise){
	save_precise = precise;
	detect_distance = precise - save_precise;
	return detect_distance;
}