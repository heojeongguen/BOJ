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

// 소수 체크를 위해 소수 리스트 생성
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

// 이분매칭 DFS
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

	// 간선 생성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			if (sosu[vec[i] + vec[j]]) {
				map[i].push_back(j);
			}
		}
	}


	vector<int> ans;
	// 0번점과 가능한 모든점을 연결하면서
	// flow를 흘려보내서 N개의 점을 채울 수 있는지 확인 한다.
	for (int i = 0; i < map[0].size(); i++) {
		// 연결정보 초기화
		memset(connected, -1, sizeof(connected));
		// 0번점은 이미 연결되있음
		int tmp = 1;
		// 0번점과 연결되는 점에대해서 0번점과 연결됬다고 체크
		connected[map[0][i]] = 0;
		for (int j = 1; j < N; j++) {
			memset(visit, false, sizeof(visit));
			// 0번점을 제외한 j점에대해서 flow발생이 가능한지 체크
			// 단 visit[0] 은 true : map[0][i]가 대체되어선 안되기 때문에)
			visit[0] = true;
			if (dfs(j)) tmp++;
		}
		// flow를 N개의 노드에 모두 흘려보낼 수 있다면
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