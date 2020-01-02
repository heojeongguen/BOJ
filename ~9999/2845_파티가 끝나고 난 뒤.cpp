#include <iostream>

using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	for (int i = 0; i < 5; i++) {
		int data;
		cin >> data;
		cout << data - (A * B) << " ";
	}
	
}