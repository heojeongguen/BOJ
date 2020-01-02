#include <iostream>
#include <iostream>
using namespace std;

unsigned long long dp[1001][10];
int N;
// dp[index][num] : index 길이를 갖는 num으로 끝나는 수의 갯수
int fuc(int index, int num) {
	// 0길이의 수는 없다
	if (index <= 0) return 0;

	// 0미만의 수로 끝나는 수는 없다
	if (num < 0) return 0;

	// 이미 채워진 테이블이면 탈출
	if (dp[index][num] != 0) return dp[index][num];

	// dp[1][?] = 1 즉, dp[1][0], dp[1][1], dp[1][2] , dp[1][3] , ... , dp[1][9] 의 합은 10 이된다. -> 한자리 수의 총합 10
	if (index == 1) return 1;

	// dp 테이블을 채워나가며 조건인 10007 로 div 해준다.
	for (int i = 0; i <= num; i++) {
		dp[index][num] += fuc(index - 1, i);
		dp[index][num] %= 10007;
	}
	return dp[index][num] % 10007;
}

int main() {
	int N;
	unsigned long long ans = 0;
	cin >> N;
	// N자리수의 0,1,2...9 로끝나는 수를 ans에 더해준다
	// 과정에서 10007로 나누어 준다.
	for (int i = 0; i <= 9; i++) {
		ans += fuc(N, i);
		ans %= 10007;
	}
	cout << ans  << endl;
	return 0;
}