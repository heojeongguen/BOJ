#include <iostream>
#include <string>
using namespace std;

int main() {
	//3 1 , 2 2 -> 2, 2, 2, 2;·Î¸ÂÃçÁØ´Ù
	int T;
	
	cin >> T;
	while (T--) {
		int A_zeroCnt = 0, A_oneCnt = 0;
		int B_zeroCnt= 0, B_oneCnt=0;
		int size;
		int dif = 0;
		int ans = 0;
		string A, B;
		cin >> A >> B;
		size = A.size();
		for (int i = 0; i < size; i++) {
			if (A[i] != B[i]) {
				dif++;
			}
			if (A[i] == '0') {
				A_zeroCnt++;
			}
			else {
				A_oneCnt++;
			}

			if (B[i] == '0') {
				B_zeroCnt++;
			}
			else {
				B_oneCnt++;
			}
		}
		if (abs(A_zeroCnt - B_zeroCnt) > 0) {
			ans += abs(A_zeroCnt - B_zeroCnt);
			dif -= abs(A_zeroCnt - B_zeroCnt);
		}
		ans += dif / 2;
		cout << ans << endl;
	}
}