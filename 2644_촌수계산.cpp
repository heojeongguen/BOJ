#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec[101];
int N, A, B, D1, D2,Q;
bool visited[101];
int DFS(int now,int find) {
	visited[now] = true;
	if (now == find) return 0;
	if (vec[now].empty()) return -1;
	int ret = -1;

	for (int i = 0; i < vec[now].size(); i++) {
		if (visited[vec[now].at(i)] == false) {
			int tmp = DFS(vec[now].at(i), find);
			if (tmp != -1) {
				ret = tmp + 1;
				return ret;
			}
			else {
				ret = -1;
			}
		}
	}
	return ret;
}

int main() {
	cin >> N;
	cin >> A >> B;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> D1 >> D2;
		vec[D1].push_back(D2);
		vec[D2].push_back(D1);
	}
	//for (int i = 0; i < N; i++) {
	//	if (visited[i] == false) {
	//		cout << DFS(A, B) << endl;
	//	}
	//}
	cout << DFS(A, B) << endl;

}