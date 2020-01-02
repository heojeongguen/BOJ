#include <iostream>

using namespace std;

char arr[6143][6143];
int N, mid;

void makeHole(int lineSize,int jumpsize, int r, int c) {

	if (r >= N || c < 0 || c >= 2 * N - 1 || arr[r][c] == ' ') {
		return;
	}
	int count = 0;
		for (int j = r + (lineSize) * 2 - 1; j >= r + lineSize; j--) {
			for (int z = c - count; z <= c + count; z++){
			arr[j][z] = ' ';
			}
			count++;
		}
	makeHole(lineSize, jumpsize, r + jumpsize, c - jumpsize);
	makeHole(lineSize, jumpsize, r + jumpsize, c + jumpsize);
}

int main(){
	cin >> N;
	// 공백설정
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2*N -1; j++) {
			arr[i][j] = ' ';
		}
	}

	mid = (2 * N - 1)/2;
	for (int i = 0; i < N; i++) {
		for (int j = mid - i;  j <= mid + i; j++) {
			arr[i][j] = '*';
		}
	}
	int linsize;
	for (int jumpsize = N ;  jumpsize >= 3; jumpsize = jumpsize  / 2) {
		if (jumpsize % 2 == 0) {
			linsize = jumpsize / 2;
		}
		else {
			linsize = 1;
		}

		makeHole(linsize, jumpsize, 0, mid);



	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
	
}