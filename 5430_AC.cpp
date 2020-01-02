#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	int n, c;
	int delCount = 0;
	string fuc;
	string str;
	deque<int> vec;
	bool error;
	cin >> T;
	for (int i = 0; i < T; i++) {
		bool right = true;
		error = false;
		bool prevNum = false;
		vec.clear();
		cin >> fuc;
		cin >> n;
		if (n >= 0) {
			cin >> str;
			for (const auto &x : str) {
				if ((int)x - 48 >= 0 && ((int)x - 48) <= 9) {
					if (!prevNum) {
						vec.push_back((int)x - 48);
						prevNum = true;
					}
					else {
						vec.at(vec.size() - 1) = vec.back() * 10 + (int)x - 48;
						prevNum = true;
					}
				}
				else {
					prevNum = false;
				}
			}
		}
			for (const auto &x : fuc) {
				if (x == 'R') {
					if (right) {
						right = false;
					}
					else {
						right = true;
					}
				}
				else if (x == 'D') {
					if (vec.size() == 0) {
						cout << "error" << "\n";
						error = true;
						vec.clear();
						break;
					}
					else {
						if (right) {
							vec.pop_front();
						}
						else {
							vec.pop_back();
						}
					}
				}
			}
		
		if (vec.size() == 0 && error == false) {
			cout << "[]" << endl;
		}
		else if (vec.size() == 1) {
			cout << "[" << vec.at(0) << "]" << endl;
		}
		else {
			if (right) {
				for (int j = 0; j < vec.size(); j++) {
					if (j == 0) {
						cout << "[" << vec.at(j) << ",";
					}
					else if (j == vec.size() - 1) {
						cout << vec.at(j) << "]" << "\n";
					}
					else {
						cout << vec.at(j) << ",";
					}
				}
			}
			else if (!right) {
				for (int j = vec.size() - 1; j >= 0; j--) {
					if (j == vec.size() - 1) {
						cout << "[" << vec.at(j) << ",";
					}
					else if (j == 0) {
						cout << vec.at(j) << "]" << "\n";
					}
					else {
						cout << vec.at(j) << ",";
					}
				}
			}
		}
	}
}