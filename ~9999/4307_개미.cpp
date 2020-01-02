#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 아이디어 적인 부분부터 생각해보고 문제를 풀자

vector<int> vec;

int main() {
	int total_num = 0;
	int weight = 0;
	cin >> total_num;

	double total_length, ant_num;
	int min, max;

	for (int i = 0; i < total_num; i++) {
		// initialize
		vec.clear();
		min = -1;
		max = -1;

		cin >> total_length >> ant_num;

		for (int j = 0; j < ant_num; j++) {
			int sub;
			cin >> sub;
			vec.push_back(sub);
		}
		sort(vec.begin(), vec.end());

		// min getter
		for (int j = 0; j < vec.size(); j++) {
			int sub;
			if ((total_length / 2) > vec[j])
				sub = vec[j];
			else
				sub = total_length - vec[j];

			if (min == -1) {
				min = sub;
			}
			if (min < sub) {
				min = sub;
			}
		}

		// max getter
		for (int j = 0; j < vec.size(); j++) {
			int sub;
			if ((total_length / 2) > vec[j])
				sub = total_length - vec[j];
			else
				sub = vec[j];

			if (max == -1) {
				max = sub;
			}
			if (max < sub) {
				max = sub;
			}
		}

		cout << min << " " << max << endl;
	}
	return 0;
}