#include <iostream>
#include <vector>

using namespace std;
vector<string> vec;
vector<string> tmp;
int main() {
	int N, kim, im;
	int ans;
	cin >> N >> kim >> im;
	for (int i = 1; i <= N; i++) {
		if (i == kim) {
			vec.push_back("kim");
		}
		else if (i == im) {
			vec.push_back("im");
		}
		else {
			vec.push_back("*");
		}
	}
	ans = 1;
	while (vec.size() > 1) {
		tmp.clear();
		int size = vec.size();
		if (vec.size() % 2 != 0) {
			size--;
		}
		for (int i = 0; i < size; i += 2) {
			if (vec.at(i) != "*" && vec.at(i + 1) != "*") {
				cout << ans << endl;
				return 0;
			}
			else if (vec.at(i + 1) == "kim" || vec.at(i+1) == "im") {
				tmp.push_back(vec.at(i+1));
			}
			else {
				tmp.push_back(vec.at(i));
			}
		}
		if (vec.size() % 2 == 1) {
			tmp.push_back(vec.back());
		}
		ans++;
		vec = tmp;
	}
	cout << -1 << endl;
}