#include <iostream>
using namespace std;
void hanoi_print(int n, char from, char by, char to);
void hanoi_count(int n, char from, char by, char to);
int C = 0;
int main() {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	int N;
	cin >> N;
	hanoi_count(N, '1', '2', '3');
	cout << C << endl;
	hanoi_print(N, '1', '2', '3');
}

void hanoi_print(int n, char from, char by, char to) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	if (n == 1) {
		cout << from << " " << to << "\n";
	}
	else {
		hanoi_print(n-1,  from, to, by);
		cout << from << " " << to << "\n";
		hanoi_print(n - 1, by, from, to);
	}
}
void hanoi_count(int n, char from, char by, char to) {
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
	if (n == 1) {
		C++;
	}
	else {
		hanoi_count(n - 1, from, to, by);
		C++;
		hanoi_count(n - 1, by, from, to);
	}
}
