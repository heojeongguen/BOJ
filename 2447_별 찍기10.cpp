#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
char arr[2201][2201];
int S;
int N;

// ������� �Լ�
void makeHole(int lineSize) {
	for (int i = 0; i < N; i = i + (lineSize * 3)) {
		for (int j = 0; j < N; j = j + (lineSize * 3)){
			for (int z = i + lineSize; z < i + lineSize + lineSize; z++) {
				for (int y = j + lineSize; y < j + lineSize + lineSize; y++) {
					arr[z][y] = ' ';
				}
			}
		}
	}
}


int main() {
	cin >> N;
	// �ʱⰪ ���� ������ '*' �� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = '*';
		}
	}

	// N�� 1�Ǵ� 0�϶� : �� for���� ���Ͽ� �ڵ����� ����ó����
	// 3x3�� �׵θ� �β� == (������ ����/2) == 1;
	// 9x9�� �׵θ� �β� == (������ ����/2) == 3;
	// 27x27�� �׵θ� �β� == (������ ����/2) == 9;
	for (int i = 1; i < N; i = i * 3) {
		makeHole(i);
	}

	//���
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}