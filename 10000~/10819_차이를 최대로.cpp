#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
bool visit[8];
int N, ans = -1;
vector<int> arr;
vector<int> vec;
void dfs(int cnt) {
	if (cnt == N) {
		int tmp = 0;
		for (int i = 1; i < N; i++) {
			tmp += abs(arr[i] - arr[i - 1]);
		}
		ans = max(ans, tmp);
		return;
	}

	for (int i =0; i < N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			arr.push_back(vec[i]);
			dfs(cnt + 1);
			arr.pop_back();
			visit[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int data; cin >> data;
		vec.push_back(data);
	}

	dfs(0);
	cout << ans << endl;
}