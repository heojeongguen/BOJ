#include <iostream>
#include <cmath>
using namespace std;

void findIndex(unsigned long long, unsigned long long, unsigned long long);
unsigned long long result = 0;
int main() {
	unsigned long long N, R, C;
	cin >> N >> R >> C;
	unsigned long long size = pow(2.0, N);
	findIndex(size, R, C);
}

void findIndex(unsigned long long size, unsigned long long R, unsigned long long C) {
	if (size == 1) {
		cout << result;
		return;
	}
	else {
		unsigned long long MID = (size / 2) - 1;
		if (R <= MID && C <= MID) {
			//1锅备开
			findIndex((size / 2), R, C);
		}
		else if(R <= MID && C > MID){
			//2锅备开
			result = result + (size / 2) * (size / 2);
			findIndex((size / 2), R, C - (size / 2));
		}
		else if (R > MID && C <= MID) {
			//3锅备开
			result = result + ((size / 2) * (size / 2) * 2);
			findIndex((size / 2), R - (size / 2), C);
		}
		else if (R > MID && C > MID) {
			//4锅备开
			result = result + ((size / 2) * (size / 2) * 3);
			findIndex((size / 2), R - (size / 2), C- (size / 2));
		}
	}
}