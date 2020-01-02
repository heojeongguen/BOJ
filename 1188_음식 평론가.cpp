#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int lcd(int a, int b, int g){
	return a * b / g;
}



int main() {
	int n, m;
	cin >> n >> m;
	cout << m - gcd(n, m);

	
}