#include <iostream>
#include <vector>
using namespace std;

bool N_to_C[100001];
bool One_to_C[100001];
vector<int> vec[100001];
vector<int> vec2[100001];

void DFS_N_to_C(int now) {
	N_to_C[now] = true;
	for (int i = 0; i < vec[now].size(); i++) {
		if (N_to_C[vec[now][i]] == false) {
			DFS_N_to_C(vec[now][i]);
		}
	}
}

void DFS_One_to_C(int now) {
	One_to_C[now] = true;
	for (int i = 0; i < vec2[now].size(); i++) {
		if (One_to_C[vec2[now][i]] == false) {
			DFS_One_to_C(vec2[now][i]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M, T;
	int a, b;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[b].push_back(a);
		vec2[a].push_back(b);
	}
	DFS_N_to_C(N);
	DFS_One_to_C(1);

	cin >> T;
	int C;
	// N_to_C
	//	One_to_C
	for (int i = 0; i < T; i++) {
		cin >> C;
		if (N_to_C[C] && One_to_C[C]) cout << "Defend the CTP\n";
		else cout << "Destroyed the CTP\n";
	}
	return 0;
}

