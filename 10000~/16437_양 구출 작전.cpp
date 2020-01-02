#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<long long > vec[123458];
long long s[123458];
long long w[123458];

long long tmp;
long long ans;

long long dfs(int now) {
	long long ret = 0;

	if (vec[now].empty()) {
		if (s[now] != 0) {
			return s[now];
		}	
	}
	else {
		for (int i = 0; i < vec[now].size(); i++) {
			ret += dfs( vec[now][i] );
		}
	}

	if (s[now] != 0) {
		ret += s[now];
	}
	else {
		ret -= w[now];
	}
	return max((long long) 0, ret);
}



int main() {
	int N;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	char tag;
	int par;
	long long cnt, data;
	ans = 0;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		cin >> tag >> cnt >> par;
		if (tag == 'S') {
			vec[par].push_back(i);
			s[i] = cnt;
			
		}
		else {
			vec[par].push_back(i);
			w[i] = cnt;
		}
	}

	cout << dfs(1) << endl;

}