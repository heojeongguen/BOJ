#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

// dp[ i ][ j ] = 맨 앞숫자가 j인 i 자리 숫자
unsigned long long dp[11][10];
// vec[ i ][ j ] = 맨 앞숫자가 j인 i 자리 숫자인 숫자들
vector<unsigned long long> vec[11][10];

// x^y 함수
long pow(unsigned long long a, unsigned long long b) {
	unsigned long long ret = 1;
	unsigned long long aa = a;
	while (b > 0) {
		if (b % 2 == 1) ret = ret * aa;
		b = b / 2;
		aa = (aa * aa);
	}
	return ret;
}

int main() {
	tuple<int, int, int> prev;
	unsigned long long ans;
	int n;
	int count = 0;
	for (int i = 0; i <= 9; i++) {
		dp[1][i] = 1;
		vec[1][i].push_back(i);
	}
	// 위 for문 실행후 2자리 수 부터
	int size = 2;
	cin >> n;


	bool find = false;
	if (n <= 9) {
		ans = n;
	}
	else if (n >= 1023) {
		ans = -1;
	}
	else {
		count += 10;
		while (true) {
			for (int i = size - 1; i <= 9; i++) {
				for (int j = size - 2; j <= i - 1; j++) {
					dp[size][i] += dp[size - 1][j];
					count += dp[size - 1][j];
					for (const auto &x : vec[size - 1][j]) {
						vec[size][i].push_back(i * pow(10, size - 1) + x);
					}
					if (count > n) {
						prev = make_tuple(size, i, j);
						find = true;
						break;
					}
					prev = make_tuple(size, i, j);
				}

				if (find) break;
			}
			if (find) break;
			size++;
		}
		// 1이 1번째 숫자이므로
		// 위 과정은 0이1번째 숫자임.
		count--;

		// vector의 맨뒤가 제일 나중에 추가된 숫자.
		int gap = count - n;
		ans = vec[get<0>(prev)][get<1>(prev)].at(vec[get<0>(prev)][get<1>(prev)].size() - 1 - gap);
	}
	cout << ans << endl;
}