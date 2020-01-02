#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Ŀ���� sort�� ���� �Լ�
// sort( ������ ����, ������ �� , �Լ�) �� ���ؼ� ���
// �Լ������ؼ� ���ϰ��ִ� ����� ���� bool���� ����.
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