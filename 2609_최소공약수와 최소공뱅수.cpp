#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A, B;
	int ans1, ans2;
	cin >> A >> B;
	int mini = min(A, B);
	for (int i = mini; i >= 1; i--) {
		if (A % i == 0 && B % i == 0) {
			ans1 = i;
			break;
		}
	}
	// �ּҰ������ ( �μ��� �� / �ִ����� )
	ans2 = A * B / ans1;
	cout << ans1 << endl << ans2 << endl;
}