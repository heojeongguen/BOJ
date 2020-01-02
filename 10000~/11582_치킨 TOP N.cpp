#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> vec;
void fuc(int size) {
	int ssize = vec.size();
	for (int i = 0; i + size <= ssize; i = i + size) {
		sort(vec.begin()+i, vec.begin()+i + size);
	}
}

void print() {
	for (const auto & x : vec) {
		cout << x << " ";
	}
	cout << "\n";
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N,D,K,cnt;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		vec.push_back(D);
	}
	cnt = 1;
	cin >> K;
	while (N != K) {
		N /= 2;
		cnt *= 2;
	}
	fuc(cnt);
	print();
}