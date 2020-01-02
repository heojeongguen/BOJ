#include <iostream>
#include <vector>
#include <algorithm>
#define MMIN -1000000001
#define MMAX 1000000001

using namespace std;
int arr[4];
int N, D;
int mmax = MMIN, mmin = MMAX;
// + - * /
vector<int> vec;
void fuc(int now, int sum, int a, int b, int c, int d) {

	if (a < 0 || b < 0 || c < 0 || d < 0) return;

	if (now == N - 1) {
		mmax = max(mmax, sum);
		mmin = min(mmin, sum);
		return;
	}

	fuc(now + 1, sum + vec[now+1], a - 1, b, c, d);
	fuc(now + 1, sum - vec[now+1], a , b - 1, c, d);
	fuc(now + 1, sum * vec[now+1], a , b, c - 1, d);
	fuc(now + 1, sum / vec[now+1], a , b, c, d - 1);


}


int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		vec.push_back(D);
	}
	for (int i = 0; i < 4; i++) {
		cin >> arr[i];
	}
	fuc(0, vec[0], arr[0], arr[1], arr[2], arr[3]);
	cout << mmax << endl;
	cout << mmin << endl;
}