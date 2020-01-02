#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

// dp[ i ][ j ] = �� �ռ��ڰ� j�� i �ڸ� ����
unsigned long long dp[11][10];
// vec[ i ][ j ] = �� �ռ��ڰ� j�� i �ڸ� ������ ���ڵ�
vector<unsigned long long> vec[11][10];

// x^y �Լ�
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
	// �� for�� ������ 2�ڸ� �� ����
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
		// 1�� 1��° �����̹Ƿ�
		// �� ������ 0��1��° ������.
		count--;

		// vector�� �ǵڰ� ���� ���߿� �߰��� ����.
		int gap = count - n;
		ans = vec[get<0>(prev)][get<1>(prev)].at(vec[get<0>(prev)][get<1>(prev)].size() - 1 - gap);
	}
	cout << ans << endl;
}