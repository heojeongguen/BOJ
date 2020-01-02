#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define _USE_MATH_DEFINES
#define M_PI 3.14159265358979323846

using namespace std;

vector< pair<double, double> > vec;

double getDegree(double x, double y) {
	return atan(y / x) * 180 / M_PI;
}

int main() {
	int N;
	double x1, y1, x2, y2;
	double mmax = -1;
	double mmin = -1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> x1 >> y1 >> x2 >> y2;
		double deg1 = getDegree(x1, y1);
		double deg2 = getDegree(x2, y2);
		vec.push_back({ min(deg1, deg2), max(deg1, deg2) });
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> x1 >> y1;
		double deg = getDegree(x1, y1);
		if (mmax == -1) mmax = deg;
		else mmax = max(mmax, deg);
		
		if (mmin == -1) mmin = deg;
		else mmin = min(mmin, deg);
	}

	/*for (const auto & x : vec) {
		cout << "deg1 : " << x.first << "  deg2 : " << x.second << endl;
	}
	cout << "mmax : " << mmax << "  mmin : " << mmin << endl;*/

	int ans = N;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].first <= mmax && vec[i].second >= mmax)ans--;
		else if (vec[i].second >= mmin && vec[i].first <= mmin) ans--;
		else if (vec[i].second >= mmax && vec[i].first <= mmin) ans--;
	}
	cout << ans << "\n";
}