#include <iostream>
#include <vector>
using namespace std;
long arr[20];
long N, S;
int C = 0;
void add(int, int);
int main() {
	// N���� �̷���� ����
	// �����Ծƴ� �κ������� �� �κ������� ���Ҹ� �ٴ��� ���� S�� �Ǵ� ����� ��
	long  data;
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> data;
		arr[i] = data;
	}
	add(0, 0);
	if (S == 0) {
		C--;
	}
	cout << C << endl;
}

void add(int n, int prevSum) {
	if (n == N) {
		if (prevSum == S) {
			C++;
		}
		return;
	}
	else {
		add(n + 1, prevSum);
		add(n + 1, prevSum + arr[n]);
	}
}
