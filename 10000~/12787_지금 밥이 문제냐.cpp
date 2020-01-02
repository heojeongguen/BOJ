#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;
#include <vector>
int main() {
	int N,order;
	cin >> N;
	while (N--) {
		cin >> order;
		if (order == 1) {
			string str, tmp , ans ,total;
			cin >> str;

			for (int i = 0; i < str.size(); i++) {
				if (str[i] == '.') {
					int data = atoi(tmp.c_str());
					while (data > 0) {
						if (data % 2 == 0) {
							ans.push_back('0');
						}
						else {
							ans.push_back('1');
						}
						data /= 2;
					}
					int size = ans.size();
					for (int i = 0; i < 8 - size; i++) {
						ans.push_back('0');
					}
					reverse(ans.begin(), ans.end());
					total += ans;
					tmp.clear();
					ans.clear();
				}
				else {
					tmp.push_back(str[i]);
				}
				
			}
			int data = atoi(tmp.c_str());
			while (data > 0) {
				if (data % 2 == 0) {
					ans.push_back('0');
				}
				else {
					ans.push_back('1');
				}
				data /= 2;
			}
			int size = ans.size();
			for (int i = 0; i < 8 - size; i++) {
				ans.push_back('0');
			}
			reverse(ans.begin(), ans.end());
			total += ans;
			tmp.clear();
			ans.clear();
			unsigned long long output = 0;
			unsigned long long multi = 1;
			for (int i = total.size() - 1; i >= 0; i--) {
				output += multi * ((int)total[i] -'0');
				multi *= 2;
			}
			cout << output << "\n";
		}
		else if (order == 2) {
			unsigned long long input;
			vector<int> vec;
			string str, ans;
			str.clear();
			ans.clear();
			vec.clear();
			cin >> input;
			while (input > 0) {
				if (input % 2 == 1) {
					str.push_back('1');
				}
				else {
					str.push_back('0');
				}
				input /= 2;
			}
			int size = str.size();
			for (int i = 0; i < 64 - size; i++) {
				str.push_back('0');
			}
			reverse(str.begin(), str.end());
			int multi = 1;
			int tmp = 0;

			for (int i = str.size() - 1; i >= 0; i--) {
				tmp += ((int)str[i] - '0') * multi;
				multi *= 2;
				if (i % 8 == 0) {
					vec.push_back(tmp);
					multi = 1;
					tmp = 0;
				}
			}
			for (int i = vec.size() - 1; i >= 0; i--) {
				if (i == 0) cout << vec[i];
				else cout << vec[i] << ".";
			}
			cout << endl;
		}
	}
}