#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
   double pi = 1;
   double x = 3, y = -1;
   for (int cnt = 0; cnt < 10e10; cnt++ ){
       pi += y/x;
       x+=2;
       y=-y;
   }
   cout << "pi = " <<setprecision(18)<< pi*4 << std::endl;
   cout << "er = " <<setprecision(18)<< 4.00 *atan(1.0L) - pi*4.0<< endl;
   return 0;
}

