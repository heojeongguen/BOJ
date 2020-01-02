#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B, T;
	int heo;
	int kim;
	int mini;
	cin >> T;
	while (T--) {
		cin >> A >> B;
		mini = min(A, B);
		for (int i = mini; i >= 1; i--) {
			if (A % i == 0 && B % i == 0) {
				heo = i;
				break;
			}
		}
		kim = A * B / heo;
		cout  << kim << endl;
	}
}