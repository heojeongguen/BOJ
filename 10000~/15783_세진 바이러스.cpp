#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[100001];
int par[100001];
bool visit[100001];
bool find_visit[100001];
vector<int> canbeCycle;
bool ret;


//void find_par(int now) {
//	if (par[now].empty()) {
//		dfs(now);
//		return;
//	}
//
//	if (find_visit[now] == true) {
//		dfs(now);
//		return;
//	}
//	find_visit[now] = true;
//	for (int i = 0; i < par[now].size(); i++) {
//		find_par(par[now][i]);
//	}
//}

void setVisit(int now) {
	visit[now] = true;
	for (int i = 0; i < vec[now].size(); i++) {
		if(visit[vec[now][i]] == false)
		setVisit(vec[now][i]);
	}
}

void checkcycle(int now,int st, bool start) {

	visit[now] = true;

	if (now == st && start == false) {
		ret = true;
		return;
	}

	if (par[now] == 0) {
		ret = false;
		return;
	}
	
	if (start) start = false;
	checkcycle(par[now], st, start);
		
	
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int N, M, a, b;
	int cnt = 0;

	cin >> N >> M;


	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		vec[a+1].push_back(b+1);
		par[b+1] = a+1;
	}

	
	for (int i = 1; i <= N; i++) {
		if (par[i] == 0) {
			cnt++;
			setVisit(i);
		}
		else {
			canbeCycle.push_back(i);
		}
	}

	for (const auto & x : canbeCycle) {
		if (visit[x] == false) {
			ret = false;
			checkcycle(x, x, true);
			if (ret == true) {
				cnt++;
			}
		}
	}

	cout << cnt << "\n";
}