#include <iostream>

using namespace std;
long D, H, M, mmin; //day, hour, minutes, Martian minutes, respectively
int main (void)
{
    double ratio = (24.0 * 60 * 60) / (24 * 60 * 60 + 37 * 60 + 22.663);
    while (cin >> D >> H >> M) {
          mmin =  ( M + 60* ( H + 24* (D-1))) * ratio;		//convert D,H,M to martian time in minutes. minus one since days start at 1
          M = mmin%60;
          mmin/=60;
          H=mmin%24;
          D=mmin/24+1;
          cout << "Day " << D << ", " << ((H < 10)?('0'):('\0')) << H << ":" << ((M < 10)?('0'):('\0')) << M << endl;
    }
}
