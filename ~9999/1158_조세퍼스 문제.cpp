#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	int M, N, cur ,count, done;
	done = 0;
	vector<int> ans;
	vector<int> vec;
	cin >> M >> N;
	for (int i = 0; i < M; i++) {
		vec.push_back(i + 1);
	}
	cur = 0;
	count = 1;
	bool end = false;
	
	while (true) {
		if (done == M) {
			break;
		}
		if (count == N) {
			ans.push_back(vec.at(cur));
			vec.erase(vec.begin() + cur);
			count = 1;
			done++;
		}
		else {
			cur = (cur + 1) % vec.size();
			count++;
		}
	}
	
	if (ans.size() == 1) {
		cout << "<" << ans.at(0) << ">";
	}
	else {
		for (int i = 0; i < ans.size(); i++) {
			if (i == 0) {
				cout << "<" << ans.at(i) << ", ";
			}
			else if (i == ans.size() - 1) {
				cout << ans.at(i) << ">";
			}
			else {
				cout << ans.at(i) << ", ";
			}
		}
	}
}
