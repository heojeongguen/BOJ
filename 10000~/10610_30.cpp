#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
// 3�ǹ�� : ��� �ڸ����� ���� 3�� ���
// 4�� ��� : ��� �ڸ����� ���� 4�� ���
// ....
// 30�ǹ�� : 0�� �����ϰ� ����ڸ������� 3�� ���
using namespace std;
unsigned long long cnt;
int main() {
	string str;
	cin >> str;
	cnt = 0;
	bool find = false;
	vector<int> vec;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0' && find == false) {
			find = true;
			continue;
		}

		vec.push_back((int)str[i] - 48);
		cnt += (int)str[i] - 48;
	}
	if (cnt % 3 != 0 || find == false) {
		cout << -1 << endl;
	}
	else {
		sort(vec.begin(), vec.end(), greater<int>());
		for (const auto&x : vec) {
			cout << x;
		}
		cout << 0 << endl;
	}
}

//int arr[10];
//int tmp[10];
//int main() {
//	string str;
//	cin >> str;
//	for (int i = 0; i < str.size(); i++) {
//		arr[(int)str[i] - 48]++;
//	}
//	for (int i = 3; i <= 30; i = i + 3) {
//		vector<int> left;
//		for (int j = 0; j <= 9; j++) {
//			tmp[j] = arr[j];
//		}
//		string sstr = to_string(i);
//		int right = 0;
//		int fail = false;
//		for (int j = sstr.size() - 1; j >= 0; j--) {
//			if (tmp[(int)sstr[j] - 48] > 0) {
//				tmp[(int)sstr[j] - 48]--;
//				right += ((int)sstr[j] - 48) * pow(10, j);
//			}
//			else {
//				fail = true;
//				break;
//			}
//		}
//		if (fail == false) {
//			if (tmp[0] == 0) continue;
//			else {
//				tmp[0]--;
//				right = right * 10 + 0;
//				for (int j = 0; j <= 9; j++) {
//					for (int z = 0; z < tmp[j]; z++) {
//						left.push_back(j);
//					}
//				}
//				sort(left.begin(), left.end(), greater<int>());
//				for (const auto &x : left) {
//					cout << x;
//				}
//				cout << right << endl;
//				return 0;
//			}
//		}
//	}
//	cout << -1 << endl;
//}