#include <iostream>
using namespace std;

int arr[3000][3000];

int zero = 0;
int minuss = 0;
int pluss = 0;

void fuc(int row, int column ,int size){
	int tmp = arr[row][column];
	if (size == 1) {
		if (tmp == -1) minuss++;
		else if (tmp == 0) zero++;
		else pluss++;
		return;
	}
	for (int i = row; i < row + size; i++) {
		for (int j = column; j < column + size; j++) {
			if (tmp != arr[i][j]) {
				int ssize = size / 3;
				fuc(row + ssize, column, ssize);
				fuc(row + ssize, column + ssize, ssize);
				fuc(row + ssize, column + (2 * ssize), ssize);
				fuc(row + (2* ssize), column, ssize);
				fuc(row + (2 * ssize), column + ssize, ssize);
				fuc(row + (2 * ssize), column + (2 * ssize), ssize);
				fuc(row, column, ssize);
				fuc(row, column +  ssize, ssize);
				fuc(row, column + (2 * ssize), ssize);
				return;
			}
		}
	}
	if (tmp == -1) minuss++;
	else if (tmp == 0) zero++;
	else pluss++;
}

int main() {
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}
	fuc(1,1, N);
	cout << minuss << endl << zero << endl << pluss << endl;
}