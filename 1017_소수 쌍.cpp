#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
#define MAX_N 51
vector<int> vec;
vector<int> map[MAX_N];
int connected[MAX_N];
bool visit[MAX_N];
bool sosu[2001];

// �Ҽ� üũ�� ���� �Ҽ� ����Ʈ ����
void make_sosu() {
	memset(sosu, true, sizeof(sosu));
	for (int i = 2; i <= 2000; i++) {
		if (sosu[i] == true) {
			for (int j = 2; j * i <= 2000; j++) {
				sosu[j * i] = false;
			}
		}
	}
}

// �̺и�Ī DFS
bool dfs(int x) {
	if (visit[x]) return false;
	visit[x] = true;
	for (int i = 0; i < map[x].size(); i++) {
		int y = map[x][i];
		if (connected[y] == -1 || dfs(connected[y])) {
			connected[y] = x;
			return true;
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		int data; cin >> data;
		vec.push_back(data);
	}
	make_sosu();

	// ���� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (sosu[vec[i] + vec[j]]) {
				map[i].push_back(j);
			}
		}
	}


	vector<int> ans;
	// 0������ ������ ������� �����ϸ鼭
	// flow�� ��������� N���� ���� ä�� �� �ִ��� Ȯ�� �Ѵ�.
	for (int i = 0; i < map[0].size(); i++) {
		// �������� �ʱ�ȭ
		memset(connected, -1, sizeof(connected));
		// 0������ �̹� ���������
		int tmp = 1;
		// 0������ ����Ǵ� �������ؼ� 0������ �����ٰ� üũ
		connected[map[0][i]] = 0;
		for (int j = 1; j < N; j++) {
			memset(visit, false, sizeof(visit));
			// 0������ ������ j�������ؼ� flow�߻��� �������� üũ
			// �� visit[0] �� true : map[0][i]�� ��ü�Ǿ �ȵǱ� ������)
			visit[0] = true;
			if (dfs(j)) tmp++;
		}
		// flow�� N���� ��忡 ��� ������� �� �ִٸ�
		if (tmp == N) 
			ans.push_back(vec[map[0][i]]);
	}

	if (ans.empty()) cout << -1 << endl;
	else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}