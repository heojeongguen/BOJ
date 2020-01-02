#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;
int N; int cost[17][17];
bool visited[17];
int lowCost = INT_MAX;

void tsp(int node, int costSum, int count,int start) {
	visited[node] = true;
	if (count == N) {
		if (cost[node][start] != 0) {
			lowCost = min(lowCost, costSum + cost[node][start]);
			visited[node] = false;
		}
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visited[i] && cost[node][i] != 0) {
			if (costSum + cost[node][i] < lowCost) { //여기 코드로 횟수 줄임
				tsp(i, costSum + cost[node][i], count + 1,start);
			}
		}
	}
	visited[node] = false;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		visited[i] = false;
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		tsp(i, 0, 1,i);
	}
	cout << lowCost << "\n";
	return 0;
}