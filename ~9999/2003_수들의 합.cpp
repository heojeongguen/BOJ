#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'
typedef long long ll;

int main() {
	int N, M; cin >> N >> M;
	vector<int> vec;
	for (int i = 0; i < N; i++) {
		int data; cin >> data; vec.push_back(data);
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		long long sum = 0;
		for (int j = i; j < N; j++) {
			sum += vec[j];
			if (sum == M) ans++;
			else if (sum > M) break;
			else continue;
		}
	}
	cout << ans << endl;
}