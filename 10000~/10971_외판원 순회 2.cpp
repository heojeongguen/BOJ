#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef long long ll;

vector<pair<int,int>> vec[11];

// 어디서 출발하던지 크게 상관없으므로 0번도시에서부터 출발해도 될 것같다
// 모든도시를 잇는 고리형태가 만들어지므로..

bool visit[11];
int ans = 1e9;
int N;
void fun(int now,int cost, int cnt) {
	if (cnt == N) {
		for (int i = 0; i < vec[now].size(); i++) {
			if (vec[now][i].first == 0) {
				ans = min(cost + vec[now][i].second, ans);
			}
		}
		return;
	}
	visit[now] = true;
	for (int i = 0; i < vec[now].size(); i++) {
		int next_node = vec[now][i].first;
		int next_cost = vec[now][i].second;
		if (!visit[next_node]) {
			fun(next_node, cost + next_cost, cnt + 1);
		}
	}
	visit[now] = false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int data; cin >> data;
			if (data != 0) {
				vec[i].push_back({ j,data });
			}
		}
	}
	fun(0, 0, 1);
	cout << ans << endl;
}