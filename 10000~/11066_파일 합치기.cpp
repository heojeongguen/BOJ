#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
// dp테이블에 절대 올수 없는 최대값을 위한 define 값
#define INF 0x7fffffff/2 
using namespace std;
int arr[501];
int dp[501][501];
int sum[501];

// s(start) ,e(end)
int fuc(int s, int e) {
	// start == end : 자기 자신과 합치는경우는 0
	if (s >= e) return 0;

	// 이미 테이블이 채워져있는 경우
	if (dp[s][e] != -1) return dp[s][e];

	// e와 s가 1차이 자신과 다음을 합침
	if (e == s + 1) return arr[s] + arr[e];

	// 최대값으로 설정
	dp[s][e] = INF;

	// 예를들어 총 4개의 부록이 있고 처음 함수 호출시
	// (1)(2,3,4) , (1, 2)(3, 4) , (1, 2 ,3)(4) 가호출
	// (1)(2,3,4)일경우 (1) -> 0, (2,3,4) -> (2)(3,4) or (2,3)(4)
	// 과정반복하면서 dp[s][e]에 최솟값으로 계속해서 대체됨
	for (int i = s; i <= e; i++) {
		// (1)(2,3,4) 경우 4개의 부록을 모두 합치는 경우이므로 sum[4]와 fuc(2,3,4)의 의 값이 tmp값이 됨.
		int tmp = fuc(s, i) + fuc(i + 1, e) + sum[e] - sum[s - 1];
		// 각 반복마다 최솟값으로 대체.
		dp[s][e] = min(dp[s][e], tmp);
	}
	// 위과정을 모두끝내고나서 리턴
	return dp[s][e];
}


int main() {
	int T, N, data, ans, cur, mean;
	cin >> T;
	while(T--){
		cin >> N;

		// dp테이블, sum배열 초기화
		for (int i = 0; i <= 501; i++) {
			for (int j = 0; j <= 501; j++) {
				dp[i][j] = -1;
			}
			sum[i] = 0;
		}

		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
			// sum[i] = arr[1] ~ arr[N] 까지의 총합
			sum[i] = sum[i - 1] + arr[i];
		}
		

		cout << fuc(1, N) << endl;

	}
	return 0;
}