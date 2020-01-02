#include <iostream>
#include <string>
using namespace std;
bool haveTri(unsigned long long data);
int main() {
	int N;
	int size;
	cin >> N;
	int count = 0;
	unsigned long long ans  = 666;
	while (true) {
		if (haveTri(ans)) {
			count++;
		}
		if (count == N) {
			break;
		}
		ans++;
	}
	cout << ans << endl;

}

bool haveTri(unsigned long long data) {
	string str = to_string(data);
	int count = 0;
	for (const auto &x : str) {
		if ((int)x - 48 == 6) {
			count++;
		}
		else {
			count = 0;
		}
		if (count == 3){
			return true;
		}
	}
	return false;
}