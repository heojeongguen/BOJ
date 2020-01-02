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
		r = n % 10; //1�� �ڸ��� ��
		sum += r; // �� �ڸ��� ���� ���ϱ� ���� ����
		n = n / 10; //10�� �ڸ��� �ٿ����� ���
	}
	return sum;
}