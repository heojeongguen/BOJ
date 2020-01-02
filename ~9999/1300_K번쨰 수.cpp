#include <iostream>
#include <algorithm>
using namespace std;

// 직접 배열 만들어서 숫자 써 나가다보면
// 왜 이분법으로 풀어야 하는지 알 수 있음
// 0 ~ N * N 의 정렬된 배열에서 N*N/2 번째 수는 배열의 가운데 있음


int main() {
	unsigned long long N, K;
	unsigned long long ans;
	cin >> N >> K;
	unsigned long long MIN = 0;
	unsigned long long MAX = N * N;
	while (MIN <= MAX) {
		unsigned long long MID = (MIN + MAX) / 2;
		unsigned long long cnt = 0;
		for (int i = 1; i <= N; i++) {
			cnt += min((unsigned long long)N, MID / i);
		}
		if (cnt == K) {
			// cnt == K 일지라도 멈추지 않는이유
			// MID라는 놈은 해당 index의 값이 아닌,
			// 배열의 index를 나타냄
			// 그래서 최종까지 탐색을 해야함.
			ans = MID;
			MAX = MID - 1;
		}
		else if (cnt < K) {
			MIN = MID + 1;
		}
		else {
			ans = MID;
			MAX = MID - 1;
		}
	}
	cout << ans << endl;
}