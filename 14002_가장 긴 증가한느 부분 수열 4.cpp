#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int,int> > vec;
vector<pair<int, int> >::iterator iter;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.first < b.second;
}

int main() {
	int mmax = 0;
	int N,D;
	vector<pair<int, int>> ans;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		if (vec.empty()) {
			vec.push_back({ D, 0 });
			ans.push_back({ D,0 });
		}
		else if (vec.back().first < D) {
			int tmp = vec.back().second + 1;
			vec.push_back({ D, tmp });
			ans.push_back({ D, tmp });
			mmax = max(mmax, tmp);

		}
		else {
			pair<int, int> tmp = { D,0 };
			iter = lower_bound(vec.begin(), vec.end(), tmp, cmp);
			iter-> first = D;
			ans.push_back({ iter->first,iter->second });
			mmax = max(mmax, iter->second);
		}
	}

	for (const auto & x : ans) {
		cout << x.first << " " << x.second << endl;
	}
	vector<int> aans;
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i].second == mmax) {
			aans.push_back(ans[i].first);
			mmax--;
			if (mmax == -1) break;
		}
	}

	for (int i = aans.size() - 1; i >= 0; i--) {
		cout << aans[i] << " ";
	}
	
}