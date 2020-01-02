#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
vector<pair<int,int>> ans;

void fuc(int A, int B) {
	int result;
	int mini = min(A, B);
	int aa;
	int bb;
	for (int i = mini; i >= 1; i--) {
		if (A % i == 0 && B % i == 0) {
			aa = A / i;
			bb = B / i;
			break;
		}
	}
	cout << aa << "/" << bb << endl;
}

int main() {
	int N, data;
	cin >> N;
	while (N--) {
		cin >> data;
		vec.push_back(data);
	}
	int s = vec.front();
	for (int i = 1; i < vec.size(); i++) {
		if (vec.at(i) > s) {
			ans.push_back(make_pair(s,vec.at(i)));
		}
		else {
			ans.push_back(make_pair(s, vec.at(i)));
		}
	}
	for (const auto &x : ans) {
		fuc(x.first, x.second);
	}
	return 0;
}