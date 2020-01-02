#include <iostream>
#include <vector>
// 진짜 100% 수학적인 문제
// 수학적 사고가없으면 풀 수 없다
using namespace std;
vector<int> vec;

// 컴퓨터공학적인 사고 xx
// A[0] = 0 일때, 1일때, 2일떄 ..... 하다보면 수열의 갯수가 나오는 공식을 만들 수 있다.
int main() {
	int N, data;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data;
		if (data == 4) {
			cout << 2 << endl;
		}
		else if (data == 1 || data == 2 || data == 3 || data == 6 ) {
			cout << 0 << endl;
		}else{
			cout << 1 << endl;
		}
	}
}