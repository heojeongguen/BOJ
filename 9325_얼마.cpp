#include <iostream>
using namespace std;

int main() {
	int T, A, B, Car,N;
	cin >> T;
	while (T--) {
		cin >> Car;
		cin >> N;
		while (N--) {
			cin >> A >> B;
			Car += A * B;
		}
		cout << Car << endl;
	}
}