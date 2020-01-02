#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
char arr[2201][2201];
int S;
int N;

// 공백생성 함수
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
	// 초기값 설정 모든범위 '*' 로 설정
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			arr[i][j] = '*';
		}
	}

	// N이 1또는 0일때 : 밑 for문에 의하여 자동으로 예외처리됨
	// 3x3의 테두리 두께 == (공백의 넓이/2) == 1;
	// 9x9의 테두리 두께 == (공백의 넓이/2) == 3;
	// 27x27의 테두리 두께 == (공백의 넓이/2) == 9;
	for (int i = 1; i < N; i = i * 3) {
		makeHole(i);
	}

	//출력
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}