#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int sumDigits(int);
int main() {
	int N, size, data, result, temp;
	data = 0;
	result = -1;
	int c;
	cin >> N;
	for (int i = N; i >= 0; i--){
		data = 0; 
		temp = i;
		size = (int)(log10(i) + 1);

		data += sumDigits(i);
		data += i;
		//cout << "[ i ] : " << i << "data : " << data << endl;
		if (data == N) {
			if (result == -1) {
				//cout << " ------ " << data << endl;
				result = temp;
			}else {
				if(result > i) {
				result = temp;
			}
			}
		}
	}
	if (result == -1) {
		cout << 0;
	}
	else {
		cout << result;
	}
}
int sumDigits(int n) {
	int r, sum;
	sum = 0;
	while (n != 0) {
		r = n % 10; //1의 자리의 값
		sum += r; // 각 자리의 합을 구하기 위한 변수
		n = n / 10; //10의 자리씩 줄여가는 방법
	}
	return sum;
}