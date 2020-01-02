#include <iostream>
#include <algorithm>
using namespace std;

int N, L;
int arr[101][101];
bool verticalLeg[101];
bool horizentalLeg[101];
int cnt = 0;
void checkVertical(int nowR) {
	int nowC = 0;
	bool fail = false;
	while(nowC < N && !fail){
		if (nowC == N - 1) {
			break;
		}
		if (nowC + L < N) {
			if (abs(arr[nowR][nowC + L] - arr[nowR][nowC]) == 1) {
				if (arr[nowR][nowC + L] > arr[nowR][nowC]) {
					if (verticalLeg[nowC]) {
						fail = true;
						break;
					}
					for (int i = nowC + 1; i < nowC + L; i++) {
						if (arr[nowR][nowC] < arr[nowR][i]) {
							fail = true;
							break;
						}
					}

				}
				else {
					for (int i = nowC + 1; i < nowC + L; i++) {
						if (arr[nowR][nowC] <= arr[nowR][i]) {
							fail = true;
							break;
						}
					}
					if(!fail)
					verticalLeg[nowC + L] = true;
				}

				if (!fail) {
					nowC = nowC + L;
					continue;
				}
				else {
					fail = false;
				}
		
			}
		}

		if (nowC + 1 < N) {
			if (arr[nowR][nowC] == arr[nowR][nowC + 1]) {
				nowC++;
				continue;
			}
			else {
				fail = true;
			}
		}
	}
	if (!fail) {
		cnt++;
	}

}

void checkHorizen(int nowC) {
	int nowR = 0;
	bool fail = false;
	while (nowR < N && !fail) {
		if (nowR == N - 1) {
			break;
		}
		if (nowR + L < N) {
			if (abs(arr[nowR + L][nowC] - arr[nowR][nowC]) == 1) {
				
				if (arr[nowR + L][nowC] > arr[nowR][nowC]) {
					if (horizentalLeg[nowR]) {
					fail = true;
					break;
				}
					for (int i = nowR + 1; i < nowR + L; i++) {
						if (arr[nowR][nowC] < arr[i][nowC]) {
							fail = true;
							break;
						}
					}

				}
				else {
					for (int i = nowR + 1; i < nowR + L; i++) {
						if (arr[nowR][nowC] <= arr[i][nowC]) {
							fail = true;
							break;
						}
					}
					if(!fail)
					horizentalLeg[nowR + L] = true;
				}
				
				if (!fail) {
					nowR = nowR + L;
					continue;
				}
				else {
					fail = false;
				}
				
			}
		}
		if (nowR + 1 < N) {
			if (arr[nowR][nowC] == arr[nowR + 1][nowC]) {
				nowR++;
				continue;
			}
			else {
				fail = true;
			}
		}
		
	}
	if (!fail) {
		cnt++;
	}

}
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < N; i++) {
		fill(verticalLeg, verticalLeg + 101, false);
		checkVertical(i);
		
	}
	for (int i = 0; i < N; i++) {
		fill(horizentalLeg, horizentalLeg + 101, false);
		checkHorizen(i);

	}

	cout << cnt << endl;
}

