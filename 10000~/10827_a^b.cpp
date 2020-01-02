#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main() {
	string str;
	string ans;
	double A, B;
	cin >> A >> B;
	str = to_string(A);
	cout << (str.size() - 2) * B << endl;
	cout.precision(((str.size() - 2) * B) + 2);
	cout << pow(A, B) << endl;
	
}
