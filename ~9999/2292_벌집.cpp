#include <iostream>

using namespace std;

int main() {
	unsigned long long N;
	unsigned long long layer = 1;
	cin >> N;
	
	unsigned long long prev, cur;
	int total = 1;
	while (total < N) {
		if (total == 1) {
			total = 7;
			layer++;
		}
		else {
			layer++;
			total = total + ((layer - 1) * 6);
	
		}
	}
	cout << layer;
}