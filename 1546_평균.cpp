#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
	int N, m;
	double Max,d, total = 0;
	vector<double> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> d;
		vec.push_back(d);
	}
	Max = *max_element(vec.begin(), vec.end());
	for (unsigned int i = 0; i < vec.size(); i++) {
		vec.at(i) = (vec.at(i) / Max) * 100;
	}
	
	for (const auto & x : vec) {
		total += x;
	}
	cout.precision(2);
	cout << fixed << total / N;
}