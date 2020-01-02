#include <iostream>
#include <vector>

using namespace std;

bool dp[1001];

int main() {
	int N, K;
	int visit = 0;
	cin >> N >> K;
	for (int i = 2; i <= N; i++) {
		if (dp[i] == false) {
			dp[i] = true;
			visit++;
			if (visit == K) {
				cout << i << endl;
				return 0;
			}
			for (int j = 2; j * i <= N; j++) {
				if (dp[i * j] == false) {
					dp[j * i] = true;
					visit++;
					if (visit == K) {
						cout << i * j << endl;
						return 0;
					}
				}
			}
		}
	}
}