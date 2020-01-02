#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int fuction(int i, int j,char [][50],int ,char);
int boundaryCheck(int i, int j, char arr[][50], int count);
char arr[50][50];
int M, N;
int main() {

	string str;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < M; j++) {
			arr[i][j] = str.at(j);
		}
	}
	/*for (int i = 0; i < N ; i++) {
		for (int j = 0; j < M; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}*/
	char origin[50][50];
	int MIN = 999999;
	int loop = 0;
	for (int i = 0; i + 8 <= N; i++) {
		for (int j = 0; j + 8 <= M; j++) {
			for (int k = 0; k < N; k++) {
				for (int z = 0; z < M; z++) {
					origin[k][z] = arr[k][z];
				}
			}
			MIN = min(MIN,fuction(i, j, origin, 0, 'B'));
			for (int k = 0; k < N; k++) {
				for (int z = 0; z < M; z++) {
					origin[k][z] = arr[k][z];
				}
			}
			MIN = min(MIN, fuction(i, j, origin, 0, 'W'));

			loop++;
		}
	}
	cout << MIN;
}

int fuction(int row, int col, char charArray[][50], int count, char start) {
	//for (int i = 0; i + 8 < N; i++) {
	//	for(int j =0; j +)
	//}
	if (charArray[row][col] != start) {
		charArray[row][col] = start;
		count++;
	}
	/*cout << "-------------------------------" << endl;
	cout << "------------origin-------------" << endl;
	cout << " row : " << row << " ~ " << row + 7 << endl;
	cout << " col : " << col << " ~ " << col + 7 << endl;
	for (int i = row; i < row + 8; i++) {
		for (int j = col; j < col + 8; j++) {
			cout << charArray[i][j] << " ";
		}
		cout << endl;
	}*/
	for (int i = row; i < row + 8; i++) {
		for (int j = col; j < col + 8; j++) {
			char it = charArray[i][j];
			if (i + 1 < row + 8) {
				if (charArray[i + 1][j] == it) {
					if (it == 'B') {
						charArray[i + 1][j] = 'W';
						//cout << "[ " << i + 1 << " ]" << "[ " << j << " ] : From 'B to 'W' " << endl;
					}
					else {
						charArray[i + 1][j] = 'B';
						//cout << "[ " << i + 1 << " ]" << "[ " << j  << " ] : From 'B to 'W' " << endl;
					}
					count++;
				}
			}
			if (i - 1 >= row) {
				if (charArray[i -1][j] == it) {
					if (it == 'B') {
						charArray[i - 1][j] = 'W';
						//cout << "[ " << i - 1 << " ]" << "[ " << j << " ] : From 'B to 'W' " << endl;
					}
					else {
						charArray[i - 1][j] = 'B';
						//cout << "[ " << i - 1 << " ]" << "[ " << j  << " ] : From 'B to 'W' " << endl;
					}
					count++;
				}
			}
			if (j + 1 < col + 8) {
				if (charArray[i][j + 1] == it) {
					if (it == 'B') {
						charArray[i][j + 1] = 'W';
						//cout << "[ " << i << " ]" << "[ " << j + 1 << " ] : From 'B to 'W' " << endl;
					}
					else {
						charArray[i][j + 1] = 'B';
						//cout << "[ " << i << " ]" << "[ " << j + 1 << " ] : From 'B to 'W' " << endl;
					}
					count++;
				}

			}
			if (j - 1 >= col) {
				if (charArray[i][j - 1] == it) {
					if (it == 'B') {
						charArray[i][j - 1] = 'W';
						//cout << "[ hihi " << i << " ]" << "[ " << j-1 << " ] : From 'B to 'W' << by" << endl;
					}
					else {
						charArray[i][j - 1] = 'B';
						//cout << "[ " << i << " ]" << "[ " << j-1 << " ] : From 'W' to 'B' " << endl;
					}
					count++;
				
				}
			}
		}
	}
	//cout << "------count : " <<count << "-------------" << endl;
	//for (int i = row; i < row + 8; i++) {
	//	for (int j = col; j < col + 8; j++) {
	//		cout << charArray[i][j] << " ";
	//	}
	//	cout << endl;
	//}
	//cout << endl;
	bool suc = true;
	for (int i = row; i < row + 8; i++) {
		for (int j = col; j < col + 8; j++) {
			char it = charArray[i][j];
			if (i + 1 < row + 8) {
				if (charArray[i + 1][j] == it) {
					suc = false;
					break;
				}
			}
			if (i - 1 >= row) {
				if (charArray[i - 1][j] == it) {
					suc = false;
					break;
				}
			}
			if (j + 1 < col+8) {
				if (charArray[i][j + 1] == it) {
					suc = false;
					break;
				}

			}
			if (j - 1 >= col) {
				if (charArray[i][j - 1] == it) {
					suc = false;
					break;
				}
			}
		}
		if (suc) {
			return count;
			break;
		}
		else {
			return 99999;
		}
	}
	

}
