#include <iostream>
#include <algorithm>
using namespace std;

// 볼륨
int v[101];

// dp테이블
int dp[101][1001];

// ans는 초기값 -1로 설정
// ( ans가 어떠한 영향도 받지않은경우 : 중간에 어떠한 경우라도 최종값에 도달하지 못하기때문에 -1이 출력됨)
int N, M, S, ans = -1;

// c(count) : c번째 곡( index 라고봐도 무방 )
// b(before) : 이전곡에서 현재(c) 곡으로 넘어왔을때 볼륨
int fuc(int c, int b) {
	// N번째 곡이 최대
	if (c > N) return 0;

	// 0보다 작아지는 경우
	if (b < 0) return 0;

	// M보다 커지는 경우
	if (b > M) return 0;

	// 마지막곡에 도달했을 때
	// 조건에 만족 한다면 ans값 대체
	if (c == N) {
		if (b + v[c] <= M && b + v[c] >= 0) {
			ans = max(b + v[c], ans);
			return b + v[c];
		}
		if (b - v[c] >= 0 && b - v[c] <= M) {
			ans = max(ans, b - v[c]);
			return b - v[c];
		}
		// 실수 ! : -1으로 리턴해주게 되면 이미 방문한 테이블을 초기화 시켜버리는 꼴이 되기때문에 ,반복 횟수가 엄청나게 많아진다.
		return 0;
	}

	if (dp[c][b] != -1) return dp[c][b];
	
	
	dp[c][b] = max(fuc(c + 1, b + v[c]), fuc(c + 1, b - v[c]));

	return dp[c][b];

}

int main() {
	int data;
	cin >> N >> S >> M;

	for (int i = 0; i <= 100; i++) {
		for (int j = 0; j <= 1000; j++) {
			dp[i][j] = -1;
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> v[i];
	}
	fuc(1, S);
	cout << ans << endl;
}