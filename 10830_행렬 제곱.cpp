#include <iostream>

using namespace std;
unsigned long long N, A ,b;
unsigned long long  arr[5][5];
unsigned long long  multi[5][5];
unsigned long long DIV = 1000;
void powA(unsigned long long B) {
	unsigned long long tmp[5][5];
	unsigned long long temp;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			tmp[i][j] = arr[i][j];
			arr[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++) {
		arr[i][i] = 1;
	}
	unsigned long long ret[5][5];
	while (B > 0) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret[i][j] = arr[i][j];
			}
		}
		if (B % 2 == 1) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					temp = 0;
					for (int z = 0; z < N; z++) {
						temp += ret[ i ][z] * tmp[z][j] % DIV;
					}
					arr[i][j] = temp;
				}
			}
		}
		B = B / 2;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ret[i][j] = tmp[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				temp = 0;
				for (int z = 0; z < N; z++) {
					temp += ret[i][z] * ret[z][j] % DIV;
				}
				tmp[i][j] = temp;
			}
		}
	}
}


int main() {
	unsigned long long data;
	cin >> N >> b;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> data;
			arr[ i ][ j ] = data;
		}
	}
	powA(b);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] % DIV  << " ";
		}
		cout << endl;
	}
}