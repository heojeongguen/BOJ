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
vector<int> vec;
vector<int> ans[11];
void fuc(int s, int e, int depth) {
	int mid = (s + e) / 2;
	ans[depth].push_back(vec[mid]);
	if (s >= e) {
		return;
	}
	else {
		fuc(s, mid-1, depth + 1);
		fuc(mid+1, e, depth + 1);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int K; cin >> K;
	int size = pow(2, K) - 1;
	for (int i = 0; i < size; i++) {
		int data; cin >> data;
		vec.push_back(data);
	}
	fuc(0, size - 1,0);
	for (int i = 0; i < K; i++) {
		for (const auto &x : ans[i]) {
			cout << x << " ";
		}
		cout << endl;
	}
}