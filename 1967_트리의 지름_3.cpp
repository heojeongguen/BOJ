#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > vec[10001];
bool visit[10001];

pair<int, int> tmp = { -1,-1 };
pair<int, int> tmp2 = { -1,-1 };
void find_node(int now,int sum) {
	visit[now] = true;


	if (tmp.second < sum) {
		tmp.first = now;
		tmp.second = sum;
	}
	
	for (const auto & x : vec[now]) {
		if (visit[x.first] == false) {
			find_node(x.first, sum + x.second);
		}
	}


}

void find_len(int now, int sum) {
	visit[now] = true;

	if (tmp2.second < sum) {
		tmp2.first = now;
		tmp2.second = sum;
	}

	for (const auto & x : vec[now]) {
		if (visit[x.first] == false) {
			find_len(x.first, sum + x.second);
		}
	}

	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	int a, b, wei;
	for (int i = 0; i < N-1; i++) {
		cin >> a >> b >> wei;
		vec[a].push_back({ b,wei });
		vec[b].push_back({ a,wei });
	}

	find_node(1, 0);
	fill(visit, visit + N + 1, false);
	find_len(tmp.first, 0);
	cout << tmp2.second << endl;
}