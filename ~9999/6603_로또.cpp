#include <iostream>
#include <vector>
using namespace std;

int N, K;

int arr[13];

void fuc(int now, int cnt, vector<int> vec ) {
	if (cnt == 6) {
		for (const auto &x : vec) {
			cout << x << " ";
		}
		cout << endl;
		return;
	}

	if (now >= N) return;

	vec.push_back(arr[now]);
	fuc(now + 1, cnt + 1, vec);

	vec.pop_back();
	fuc(now + 1, cnt, vec);

}

int main() {
	while (true) {
		cin >> N;
		if (N == 0) break;

		for(int i = 0 ; i < N; i++){
			cin >> arr[i];
		}
		vector<int> vec;
		fuc(0, 0, vec);
		cout << endl;
	}
}