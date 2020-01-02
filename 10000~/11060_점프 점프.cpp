#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int jump(int now) {

	// 이런식으로하면 끝에 따로 대입해주지 않고도 빠른 속도로 리턴 가능
	int &ret = dp[now];

	// 조건에서 나가는경우 0리턴 ( N 보다 커지는 경우도 어쩃든 0을 리턴함;
	// 그이유는 N을 넘어갔다는 말은 N도 이미 방문했다는 의미이기 때문임( 그전 점에서 N이상을 갈 수있다는 의미)
	if (now >= N) return 0;

	// 반복 횟수 줄이기
	if (dp[now] != -1) return dp[now];


	// 최솟값을 구하는 것이기 때문에
	// 나올수있는 값보다 큰 값으로 초기화
	ret = 1001;

	// 자신의 위치에서 갈수 없다면 1001로 바뀜
	// 가고 가고 가다보면 최솟값이 리턴됨
	for (int i = 1; i <= arr[now]; i++) {
		ret = min(ret, 1 + jump(now + i));
	}

	// 최종 리턴
	return ret;
}

int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// 범위를 벗어나면 0을 리턴할 것이기 때문에 -1로 초기화
	fill(dp, dp + 1001, -1);

	// DFS 실행
	int ans = jump(1);

	// 조건문 ( 한 점 방문시 최소 1 이상이기때문에 N == 1 이라면 0을 리턴 )
	if (N == 1) cout << 0 << endl;
	else if (ans == 1001)cout << -1 << endl;
	else cout << ans << endl;

	
	return 0;
}