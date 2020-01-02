#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<>()> mmax;
priority_queue<int, vector<int>, less<>()> mmin;


int main() {
	int A, B;
	while (true) {
		cin >> A >> B;
		if (A == 0 && B == 0) break;
		int gap = B - A;
		int C = A - gap;
		cout << C << "\n";
	}

}