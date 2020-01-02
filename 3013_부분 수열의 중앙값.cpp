#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
using namespace std;
unsigned long long cnt = 0;
vector<int> vec;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, B, D;
	int pos = -1;
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> D;
		vec.push_back(D);
		if (D == B) pos = i;
	}
	int **L, **R;
	L = (int**)malloc(sizeof(int*) * (2*N + 1));
	R = (int**)malloc(sizeof(int*) * (2 * N + 1));
	for (int i = 0; i < 2*N + 1; i++) {
		L[i] = (int*)malloc(sizeof(int) * 2);
		R[i] = (int*)malloc(sizeof(int) * 2);
	}
	for (int i = 0; i < 2 * N + 1; i++) {
		for (int j = 0; j < 2; j++) {
			L[i][j] = 0;
			R[i][j] = 0;
		}
	}
	L[N][0]++;
	R[N][0]++;
	int G = 0, g = 0;
	for (int i = pos - 1; i >= 0; i--) {
		if (vec[i] > B) G++;
		else g++;
		L[N + G - g][(pos - i) % 2]++;
	}
	G = 0; g = 0;
	for (int i = pos+ 1; i < N; i++) {
		if (vec[i] > B) G++;
		else g++;
		R[N + G - g][(i - pos) % 2]++;
	}
	int ans = 0;
	for (int i = 0; i <= 2 * N; i++) {
		ans += L[i][0] * R[2 * N - i][0] + L[i][1] * R[2 * N - i][1];
	}
	cout << ans << endl;
}
