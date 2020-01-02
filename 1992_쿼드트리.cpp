#include <iostream>
#include <string>
using namespace std;
int arr[64][64];
void fuc(int row, int column, int size) {
	if (size == 0) {
		return;
	}
	int tmp = arr[row][column];
	bool find = false;
	for (int i = row; i < row + size; i++) {
		for (int j = column; j < column + size; j++) {
				if (arr[ i ][ j]  != tmp) {
					cout << "(";
					fuc(row, column, size/2);
					fuc(row, column + (size / 2), size / 2);
					fuc(row + (size / 2), column, size / 2);
					fuc(row + (size / 2), column + (size / 2), size / 2);
					find = true;
					break;
				}
		}
		if (find == true) {
			break;
		}
	}

	if (find == false) {
		cout << tmp;
	}
	else {
		cout << ")";
	}
}
int main() {
	int N, data;
	string str;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			arr[ i ][ j ] = (int)str.at( j ) - 48;
		}
	}
	fuc(0, 0, N);
}