#include <bits/stdc++.h>
#include <wiringPiI2C.hpp>
#include <wiringPi.h>

using namespace std;

int main(){

    if (wiringPiSetup () == -1) 
        exit (1);
    int fad = wiringPiI2CSetup(0x76);
    cout << wiringPiI2CRead(fad) << endl;

    return 0;
}
