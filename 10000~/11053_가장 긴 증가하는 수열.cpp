#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
vector<int>::iterator iter;
int main() {
	int N,D;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		if (vec.empty()) {
			vec.push_back(D);
		}
		else if (vec.back() < D) vec.push_back(D);
		else {
			iter = lower_bound(vec.begin(), vec.end(), D );
			*iter = D;
		}
	}
	cout << vec.size() << endl;
}