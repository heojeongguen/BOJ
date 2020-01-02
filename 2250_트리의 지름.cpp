#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
pair<int, int> node[10001];
int par[10001];
int minarr[10003];
int maxarr[10003];
int pos = 1;
pair<int, int>  tmp;
void DFS(int now, int lev) {
	if (node[now].first != -1) {
		DFS(node[now].first, lev + 1);
	}
	tmp.first = lev;
	tmp.second = pos;
	
	// 현재 레벨에서 가장 왼쪽 노드 위치를 갱신
	if (minarr[tmp.first] > tmp.second)
		minarr[tmp.first] = tmp.second;

	// 현재 레벨에서 가장 오른쪽 노드 위치를 갱신
	if (maxarr[tmp.first] < tmp.second)
		maxarr[tmp.first] = tmp.second;

	pos++;
	if (node[now].second > 0)
		DFS(node[now].second, lev + 1);


}

int main() {
	int N, root, left, right;
	int tree_root;
	fill(minarr, minarr + 10002, INT_MAX);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> root >> left >> right;
		node[root].first = left;
		if (left != -1) {
			par[left] = root;
		}
		node[root].second = right;
		if (right != -1) {
			par[right] = root;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (par[i] == 0) {
			tree_root = i;
			break;
		}
	}
	DFS(tree_root , 1);
	int mmax = -1;
	int llev;
	for (int i = 1; i <= N; i++) {
		int sum = maxarr[i] - minarr[i] + 1;
		if (sum > mmax) {
			mmax = sum;
			llev = i;
		}
	}
	cout << llev << " " << mmax << endl;
	return 0;
}