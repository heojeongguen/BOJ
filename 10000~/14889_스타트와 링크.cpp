#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int arr[21][21];
bool visit[21];
int N;
int NN;
int total = 0;
int mmin = 1000000000;
int ans = 1000000000;
void fuc(int now, int cnt, vector<int> vec) {
	if (now > N) return;

	if (cnt == NN) {
		bool A[21];
		int tmp = 0;
		fill(A, A + 21, false);

		for (int i = 0; i < vec.size(); i++) {
			A[vec[i]] = true;
			for (int j = 0; j < vec.size(); j++) {
				tmp += arr[ vec[i] ][ vec[j] ];
			}
		}
		vector<int> vec2;
		for (int i = 0; i < N; i++) {
			if (A[i] == false) {
				vec2.push_back(i);
			}
		}
		int tmp2 = 0;

		for (int i = 0; i < vec2.size(); i++) {
			for (int j = 0; j < vec2.size(); j++) {
				tmp2 += arr[vec2[i]][vec2[j]];
			}
		}
		ans = min(ans, abs(tmp - tmp2));
		return;
	}


	fuc(now + 1, cnt,vec);
	vec.push_back(now);
	fuc(now + 1, cnt + 1, vec);


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> N;
	NN = N / 2;
	for (int i =0 ; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			total += arr[i][j];
		}
	}
	vector<int> vec;
	fuc(0, 0,vec);
	cout << ans << "\n";
	
	
}