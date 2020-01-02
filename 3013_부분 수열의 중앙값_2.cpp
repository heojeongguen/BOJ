#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
int arr[100001];
int main() {
	int G, g;
	int N, B,D, pos;
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] == B) pos = i;
	}

	vector<int> L[2];
	vector<int> R[2];
	for (int i = 0; i < 2; i++) {
		L[i].resize(2 * N + 1);
		R[i].resize(2 * N + 1);
	}
	L[0][N] = 1;
	R[0][N] = 1;

	for(int i = pos - 1, G = g = 0; i >=0 ; i--){
		if (arr[i] > B) G++;
		else g++;
		L[(pos - i) % 2][N + G - g]++;
	}

	for (int i = pos + 1, G = g = 0; i < N; i++) {
		if (arr[i] > B) G++;
		else g++;
		R[(i - pos) % 2][N + G - g]++;
	}
	int ans = 0;
	for (int i = 0; i <= 2 * N; i++) {
		ans += L[0][i] * R[0][2 * N - i] + L[1][i] * R[1][2 * N - i];
	}
	cout << ans << endl;

}