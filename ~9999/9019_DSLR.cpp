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

int fuc(int x, int now_register) {
	int next_register = now_register;
	if (x == 0) {
		next_register *= 2;
		next_register %= 10000;
	}
	else if (x == 1) {
		if (next_register == 0) next_register = 9999;
		else next_register -= 1;
	}
	else if (x == 2) {
		int head = next_register / 1000;
		next_register *= 10;
		next_register %= 10000;
		next_register += head;
	}
	else if (x == 3) {
		int tail = next_register % 10;
		next_register /= 10;
		next_register += tail * 1000;
	}
	return  next_register;
}


pair<int, int> visit[10001];
char cmd[4] = { 'D','S','L','R' };
queue<pair<int, int>> q;

string bfs(int start, int end) {
	q.push({ start,-1 });
	visit[start] = { '-1',-1 };
	while (!q.empty()) {
		int now = q.front().first;
		int prev = q.front().second;
		q.pop();
		//cout << "now_register : " << now_register << endl;
		if (now == end) {
			string ret;
			for (int i = now; visit[i].second != -1; i = visit[i].second) {
				ret.push_back(cmd[visit[i].first]);
			}
			while (!q.empty()) q.pop();
			reverse(ret.begin(), ret.end());
			return ret;
		}
		for (int i = 0; i < 4; i++) {
			int next = fuc(i, now);
			if (visit[next].first == '!') {
				q.push({ next, now });
				visit[next].first = i;
				visit[next].second = now;
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	while (N--) {
		for (int i = 0; i <= 9999; i++) {
			visit[i].first = '!';
			visit[i].second = -1;
		}
		int A, B; cin >> A >> B;
		cout << bfs(A, B) << endl;
	}

}