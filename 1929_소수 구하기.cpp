#include <iostream>

using namespace std;
int arr[10000007];
int main() {

	for (int i = 2; i <= 10000007; i++) {
		if (arr[i] == 0) {

			for (int j = 2; i * j <= 10000007; j++) {
				if (i * j == 1000007) cout << i << " ·Î ³ª´²Áü " << endl;
				arr[j * i] = 1;
			}
		}
	}
}