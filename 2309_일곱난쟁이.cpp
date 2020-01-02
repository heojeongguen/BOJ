#include <iostream>
using namespace std;
int arr[9] = { 0 };
	int result[7] = { 0 };

	void printReuslt();
	int total = 0;
int main() {
	int count = 0;
	int data = 0;
	for (int i = 0; i < 9; i++) {
		cin >> data;
		arr[i] = data;
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			for (int z = 0; z < 9; z++) {
				if (z == i || z == j) {
					continue;
				}
				else {
					count++;
					total += arr[z];
					if (total == 100 && count == 7) {
						count = 0;
						for (int y = 0; y < 9; y++) {
							if (y == i || y == j) {
								continue;
							}
							else {
								result[count] = arr[y];
								count++;

							}
						}
						printReuslt();					}
				}
			}
			count = 0;
			total = 0;
		}
	}


	
}

void printReuslt() {
	for (int i = 0; i < 7 - 1; i++) {
		for (int j = 0; j < 7 - i - 1; j++) {
			if (result[j] > result[j + 1]) {
				int temp = result[j];
				result[j] = result[j + 1];
				result[j + 1] = temp;
			}
		}
	}

	for (int i = 0; i < 7; i++) {
		cout << result[i] << endl;
	}
	exit(0);
}