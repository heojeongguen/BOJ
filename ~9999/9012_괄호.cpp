#include <iostream>
#include <vector>
using namespace std;
#include <string>
int main() {
	int N;
	string str,tag;
	cin >> N;
	vector<string> vec;
	for (int i = 0; i < N; i++) {
		cin >> str;
		vec.clear();
		tag = "YES";
		for (const auto &x : str) {
			if (x == ')') {
				if (vec.size() == 0) {
					tag = "NO";
				}
				else {
					vec.pop_back();
				}
			}
			else {
				vec.push_back("(");
			}
		}
		if (tag == "NO") {
			cout << tag << endl;
		}
		else {
			if (vec.size() == 0) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
	}
}
