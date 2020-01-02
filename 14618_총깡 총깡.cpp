/*
	플로마샬 알고리즘
	다익스트라 알고리즘
	일단 skip;
*/

#include <iostream>
#include <vector>
using namespace std;

char house[5001];
vector<pair<int, int> > vec[5001];
int main() {
	int N, M, J, K;
	int a ,b ,c;
	cin >> N >> M >> J >> K;
	for (int i = 0; i < K; i++) {
		cin >> a;
		house[a] = 'A';
	}

	for (int i = 0; i < K; i++) {
		cin >> a;
		house[a] = 'B';
	}
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		vec[a].push_back({ b,c });
		vec[b].push_back({ a,c });
	}
}
