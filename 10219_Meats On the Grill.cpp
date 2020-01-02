#include <iostream>
using namespace std;

char A[12][12];
char gogi[27];
int main() {
	int N;
	int H, W;
	char data;
	cin >> N;
	while (N--) {
		for (int i = 1; i <= 11; i++) {
			for (int j = 1; j <= 11; j++) {
				A[i][j] = ' ';
			}
		}
		cin >> H >> W;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> data;
				A[i][j] = data;
			}
		}
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W / 2; j++) {
				char tmp = A[i][j];
				A[i][j] = A[i][W - j+1];
				A[i][W - j +1] = tmp;
			}
		}
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cout << A[i][j];
			}
			cout << endl;
		}
	}
}