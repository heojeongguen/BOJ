#include <iostream>
#include <math.h>
#define M_PI   3.14159265358979323846
using namespace std;

int main() {
	double r;
	cin >> r;
	cout.precision(6);

	cout  << fixed << r * r * M_PI << endl;
	cout  << fixed << r * r * 2.0 << endl;
}