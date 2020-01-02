#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------

bool visit[9];
int N;
vector<int> vec;
void fuc() {

	if (vec.size() == N) {
		for (const auto &x : vec) {
			cout << x << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= N; i++) {
		if (visit[i] == false) {
			visit[i] = true;
			vec.push_back(i);
			fuc();
			visit[i] = false;
			vec.pop_back();
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	fuc();
}