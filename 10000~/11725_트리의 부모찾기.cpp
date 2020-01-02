#include <iostream>
#include <vector>
using namespace std;


vector<int> vec[100001];
int root[100001];
vector < pair<int, int> >none;

void DFS(int par) {
	for (const auto &x : vec[par]) {
		if (root[x] == -1) {
			root[x] = par;
			DFS(x);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, data1, data2;
	cin >> N;
	int N2 = N;
	N--;
	while (N--) {
		cin >> data1 >> data2;
		vec[data1].push_back(data2);
		vec[data2].push_back(data1);
	}
	for (int i = 0; i <= N2; i++) {
		root[i] = -1;
	}
	DFS(1);
	for (int i = 2; i <= N2; i++) {
		cout << root[i] << "\n";
	}
}