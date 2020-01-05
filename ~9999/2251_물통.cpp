#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

#define endl '\n'
typedef long long ll;

bool visit[201][201];
set<int> ans;

void bfs(int A, int B, int C) {
	visit[0][0] = true;
	int arr[3] = { A,B,C };
	// 한번의 하나씩의 일만 일어난다고 보면 된다
	// 1번이 2개한테 주는경우
	// 2번이 2개한테 주는경우
	// 3번이 2개한테 주는경우
	queue<pair<int, int> > que;
	que.push({ 0,0 });
	int nextA, nextB, nextC, gap;
	while (!que.empty()) {
		int nowA = que.front().first;
		int nowB = que.front().second;
		que.pop();
		int nowC = C - nowA - nowB;
		if (nowA == 0) {
			ans.insert(nowC);
		}
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				int tmp[3] = { nowA,nowB,nowC };
				if (i == j) continue;
				gap = arr[j] - tmp[j];
				gap = min(gap, tmp[i]);
				tmp[i] = tmp[i] - gap;
				tmp[j] = tmp[j] + gap;
				if (!visit[tmp[0]][tmp[1]]) {
					que.push({ tmp[0],tmp[1] });
					visit[tmp[0]][tmp[1]] = true;
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int A, B, C;
	cin >> A >> B >> C;
	bfs(A, B, C);
	for (const auto& x : ans) {
		cout << x << " ";
	}
}