#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>
unsigned long long fuc(unsigned long long N) {
	return (N * (N + 1)) / 2;
}

int main() {
	int N, L;
	int len = -1;
	vector<int > ans;
	cin >> N >> L;
	
	for (int i = L; i <= 101; i++) {
		ans.clear();

		int mid;
		int tmp;
		if (i % 2 == 1) {
			mid = N / i;
			ans.push_back(mid);
			tmp = mid;
			for (int j = 1; j <= i / 2; j++) {
				if (mid - j >= 0) {
					ans.push_back(mid - j);
					tmp += (mid - j);
				}

				ans.push_back(mid + j);
				tmp += (mid + j);
			}
		}
		else {
			mid = N / i;
			ans.push_back(mid);
			tmp = mid;
			int last = 0;
			for (int j = 1; j <= (i - 2) / 2; j++) {
				if (mid - j >= 0) {
					ans.push_back(mid - j);
					tmp += (mid - j);
				}
				ans.push_back(mid + j);
				tmp += mid + j;
				last = j;
			}
			ans.push_back(mid + last + 1);
			tmp += mid + last + 1;
		}

		if (tmp == N && ans.size() == i) {
			len = i;
			break;
		}
	}
	sort(ans.begin(), ans.end());
	if (len != -1) {
		if (ans.front() == 0) {
			if (len - 1 >= L) {
				len--;
				ans.erase(ans.begin());
			}
		}
		if (ans.size() > 100 || len < L) {
			cout << -1 << endl;
			return 0;
		}
		else {
			for (const auto & x : ans) {
				cout << x << " ";
			}
		}
	}
	else {
		cout << -1 << endl;
		return 0;
	}
}