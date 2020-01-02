#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 커스텀 sort를 위한 함수
// sort( 포인터 시작, 포인터 끝 , 함수) 를 통해서 사용
// 함수를통해서 비교하고있는 대상을 통해 bool값을 리턴.
bool compare(string a, string b) {
	if (a.size() == b.size()) {
		return (a < b);
	}
	else {
		return a.size() < b.size();
	}
}
int main() {
	int N;
	string str,prev;
	vector<string> vec;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		vec.push_back(str);
	}
	sort(vec.begin(), vec.end(), compare);
	prev = "*";
	for (const auto & x : vec) {
		if (prev == "*") {
			prev = x;
			cout << x << "\n";
		}
		else {
			if (prev != x) {
				cout << x << "\n";
				prev = x;
			}
		}
	}
}