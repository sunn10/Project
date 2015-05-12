#include "Switcher.h"
using namespace std;

Switcher::Switcher(int pin1, int pin2, int pin3){
	a = pin1;
	b = pin2;
	c = pin3;
	pinMode(a, OUTPUT);
	pinMode(b, OUTPUT);
	pinMode(c, OUTPUT);
}

void Switcher::switchpin(int num){
	string binary = DecimalToBinaryString(num)
	digitalWrite(c, (int)binary[0] - '0');
	digitalWrite(b, (int)binary[1] - '0');
	digitalWrite(a, (int)binary[2] - '0');
}

string Switcher::DecimalToBinaryString(int a)
{
    string binary = "";
    int mask = 1;
    for(int i = 0; i < 3; i++)
    {
        if((mask&a) >= 1)
            binary = "1"+binary;
        else
            binary = "0"+binary;
        mask<<=1;
    }
    return binary;
}