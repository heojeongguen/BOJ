#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > vec[100001];
pair<int, int> tmp = { -1,-1 };
bool visit[100001];

void fuc(int now, int sum) {
	visit[now] = true;
	
	if (tmp.second < sum) {
		tmp.second = sum;
		tmp.first = now;
	}

	for (const auto & x : vec[now]) {
		if (visit[x.first] == false && sum <= tmp.second) {
			fuc(x.first, sum + x.second);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int a, b, wei;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		while (true) {
			cin >> b;
			if (b == -1) break;
			cin >> wei;
			vec[a].push_back({ b ,wei});

		}
	}


	fuc(1, 0);
	fill(visit, visit + N + 1, false);
	fuc(tmp.first, 0);
	cout << tmp.second << "\n";
}