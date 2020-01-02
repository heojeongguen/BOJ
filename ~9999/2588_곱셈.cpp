#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <cmath>
#include <algorithm>
int main() {
	string A, B;
	vector<int> result;
	cin >> A;
	cin >> B;
	for (int i = 0; i < 3; i++) {
		string ans;
		int up = 0;
		int tmp;
		for (int j = 0; j < 3; j++) {
			tmp = ((int)A.at(2 - j) - 48) * ((int)B.at(2 - i) - 48);

			tmp += up;

			if (tmp >= 10) {
				up = tmp/10;
				tmp %= 10;
			}
			else {
				up = 0;
			}
			ans.push_back((char)(tmp + 48));
		}
		if (up) ans.push_back((char)(up + 48));

		reverse(ans.begin(), ans.end());
		tmp = 0;
		for (int i = 0; i < ans.size(); i++) {
			tmp += pow(10, i)*(int)(ans[ans.size() - 1 - i] - 48);
		}
		result.push_back(tmp);
		cout << tmp << endl;
	}
	int a = 0;
	for (int i = 0; i < result.size(); i++) {
		a += pow(10, i) * result[i];
	}
	cout << a << endl;
}