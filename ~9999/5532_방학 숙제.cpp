#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int L, A, B, C, D;
	int AA, BB;
	cin >> L >> A >> B >> C >> D;
	if (A % C == 0) AA = A / C;
	else AA = A / C + 1;

	if (B % D == 0) BB = B / D;
	else BB = B / D + 1;

	cout << L - max(AA,BB) << endl;
}