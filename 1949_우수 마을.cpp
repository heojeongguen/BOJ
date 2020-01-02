#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
using namespace std;
int N, D, A, B;
int wei[10001];
vector<int> vec[10001];
int mmax = -1;

vector<int> ans;
// BFS로 
// 점 하나넣고

int getSum(vector<int> v) {
	int ret = 0;
	for (int i = 0; i < v.size(); i++) {
		ret += wei[v[i]];
	}
	if (mmax < ret) {
		mmax = ret;
		ans = v;
	}
	return ret;
}

vector<int> fuc(int now, int prev_node, bool prev) {
	int data = -1;
	vector<int> ret1;
	vector<int> ret2;
	bool nothing = true;
	if (prev == false) {
		for (int i = 0; i < vec[now].size(); i++) {
			if (vec[now][i] != prev_node) {
				vector<int> tmp;
				tmp = fuc(vec[now][i], now, true);

				ret1.insert(ret1.end(), tmp.begin(), tmp.end());

				nothing = false;

			}

			if (vec[now][i] != prev_node) {
				vector<int> tmp;
				tmp = fuc(vec[now][i], now, false);

				ret2.insert(ret2.end(), tmp.begin(), tmp.end());


				nothing = false;
			}
		}
		if (nothing) {
			vector<int> ret_tmp;
			ret_tmp.push_back(now);
			return ret_tmp;
		}
		else {
			ret1.push_back(now);
			int sum1 = getSum(ret1);
			int sum2 = getSum(ret2);
			if (sum1 > sum2) {
				return ret1;
			}
			else {
				return ret2;
			}
		}

	}
	else {
		for (int i = 0; i < vec[now].size(); i++) {
			if (vec[now][i] != prev_node) {
				vector<int> tmp;
				tmp = fuc(vec[now][i], now, false);
				ret2.insert(ret2.end(), tmp.begin(), tmp.end());

				nothing = false;
			}
		}
		if (nothing) {
			vector<int> ret_tmp;
			return ret_tmp;
		}
		else {
			return ret2;
		}
	}
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		wei[i + 1] = D;
	}
	for (int i = 0; i < N - 1; i++) {
		cin >> A >> B;
		vec[A].push_back(B);
		vec[B].push_back(A);
	}
	for (int i = 1; i <= N; i++) {
		if (vec[i].size() == 1) {
			vector<int> bin;
			fuc(i, 0, false);
			break;
		}
	}
	cout << mmax << endl;
}