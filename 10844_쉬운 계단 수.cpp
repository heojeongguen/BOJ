#include <iostream>

using namespace std;


unsigned long long dp[101][10];

// dp[index][num] : index길이의 num으로 끝나는 수
unsigned long long fuc(int index, int num) {
	// 길이는 1 이상
	if (index <= 0) return 0;

	// 숫자범위는 0 ~ 9
	if (num < 0 || num > 9) return 0;

	// 이미 채워진 테이블 탈출
	if (dp[index][num] != 0) return dp[index][num];

	// 한자리 수 이면서 0인 수는 없다 즉 dp[1][0] = 0 이다.
	if (index == 1) {
		if(num != 0) 	return 1;
		else return 0;
	}

	// index 길이의 num 으로 끝나는 수는 index-1 의 길이의 수보다 1 크거나 작은 수이다.
	// 예 ) dp[2][2] : 2길이의 2로 끝나는수
	// dp[2][2] = dp[1][1] + dp[1][3] -> 한자리수 1 와 3 다음에 2가 오는 경우 -> 12 32 
	dp[index][num] = (fuc(index - 1, num - 1) + fuc(index - 1, num + 1)) % 1000000000;

	return dp[index][num] % 1000000000;

}


int main() {
	int N;
	unsigned long long ans = 0;
	cin >> N;
	for (int i = 0; i <= 9; i++) {
		ans += fuc(N, i);
		ans %= 1000000000;
	}
	cout << ans << endl;
	return  0;
}