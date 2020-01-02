#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T, N, M, data,ans;
	bool find, print;
	cin >> T;
	for (int i = 0; i < T; i++) {
		ans = 0;
		cin >> N >> M;
		find = false;
		vector<pair<int, int>> vec;
		for (int j = 0; j < N; j++) {
			cin >> data;
			vec.push_back({ j,data });
		}
		while (!find) {
			print = false;
			for (unsigned i = 0; i < vec.size(); i++) {
				if (vec.at(0).second < vec.at(i).second) {
					break;
				}
				if (i == vec.size() - 1) {
					if (vec.at(0).first == M) {
						find = true;
						ans++;
					}
					else {
					/*	cout << "출력 |  first : " << vec.at(0).first << " | second : " << vec.at(0).second << endl;*/
						ans++;
						print = true;
						vec.erase(vec.begin());
					}
				}
			}
			if (find) {
				break;
			}
			else {
				if (!print) {
					//cout << "뒤로 |  first : " << vec.at(0).first << " | second : " << vec.at(0).second << endl;
					vec.push_back(vec.at(0));
					vec.erase(vec.begin());
				}
			}
		}
		cout << ans << endl;
	}
}