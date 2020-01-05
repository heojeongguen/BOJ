#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

#define endl '\n'
typedef long long ll;

bool check[10001];
bool sosu[10001];
// ã�ƾ��ϴ� �������� ũ�� �ʰ�, �ش� ������ �ּ����� ��� Ȥ�� ����� ����Ҷ�
// BFS�� �̿��� �� �ִ�.
// BFS�� ��� �������� ������ ���ٰ��ص� 1000~10000������ �Ҽ��� ���⶧���� �����ϴ�.

string itos(int x) {
	string ret = "";
	while (x > 0) {
		ret.push_back(char(x % 10) + '0');
		x /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int ans[10001];

void bfs(int s) {
	queue<int> que;
	que.push(s);
	int cnt = 0;
	ans[s] = 0;
	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			int f = que.front(); que.pop();
			string s = itos(f);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j <= 9; j++) {
					if (i == 0 && j == 0) continue;
					string ss = s;
					ss[i] = j + '0';
					int x = stoi(ss);
					if (ans[x] == -1 && sosu[x] == true) {
						ans[x] = cnt + 1;
						que.push(x);
					}
				}
			}
		}
		cnt++;
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 2; i <= 9999; i++) {
		if (check[i] == false) {
			sosu[i] = true;
			for (int j = 2; j * i <= 9999; j++) {
				check[j * i] = true;
			}
		}
	}
	int N; cin >> N;
	while (N--) {
		memset(ans, -1, sizeof(ans));
		int a, b; cin >> a >> b;
		bfs(a);
		if (ans[b] == -1) cout << "Impossible" << endl;
		else cout << ans[b]  << endl;
	}
}