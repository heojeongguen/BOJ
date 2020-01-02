#include <iostream>

using namespace std;

int A[100][100];
int B[100][100];
int C[100][100];
int main() {
	int N, M, K;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> A[i][j];
		}
	}
	cin >> M >> K;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			cin >> B[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int z = 0; z < M; z++) {
				C[i][j] += A[i][z] * B[z][j];
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			cout << C[i][j] << " ";
		}
		cout << endl;
	}
}