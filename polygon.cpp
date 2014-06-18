//find area of polygon, given sorted vertices (based on angle)
#include <iostream>
#include <cmath>
using namespace std;

int N;
double cx,cy,area;

double cross(double x, double y, double u, double v) {
	return (x) * (v) - (y) * (u);
}

int main() {
	cin >> N;
	double x,y,lx,ly;
	scanf("%lf %lf",&cx,&cy);
	lx = cx, ly = cy;
	for(int i = 1; i < N; ++i) {
		scanf("%lf %lf",&x,&y);
		area += cross(lx,ly,x,y);
		lx = x, ly = y;
	}
	area += cross(x,y,cx,cy);
	cout << abs(area/2.0) << endl;
}