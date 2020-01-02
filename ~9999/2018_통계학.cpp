#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
int arr[8001];
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, data;
	cin >> N;
	vector<int> vec;
	double avg = 0.0;
	int med, most, scope;
	most = -4001;
	for (int i = 0; i < N; i++) {
		cin >> data;
		arr[data + 4000]++;
		vec.push_back(data);
	}

	sort(vec.begin(), vec.end());
	bool first = true;

	for (int i = 0; i < 8001; i++) {
		if (most == -4001) {
			if (arr[i] > 0) {
				most = i;
			}
		}
		else {
			if (arr[most] < arr[i]) {
				most = i;
				first = true;
			}
			else if (arr[most] == arr[i]) {
				if (first) {
					first = false;
					most = i;
				}
			}
		}
	}

	for (const auto &x : vec) {
		avg += x;
	}
	if (avg < 0) {
		avg = -1 * round((abs(avg) / vec.size()));
		
	}
	else {
		avg = round((abs(avg) / vec.size()));
	}


	med = vec.at(vec.size() / 2);
	scope = abs(vec.at(0) - vec.at(vec.size() - 1));
	cout << avg << endl;
	cout <<med << endl;
	cout << most - 4000<< endl;
	cout << scope << endl;

}