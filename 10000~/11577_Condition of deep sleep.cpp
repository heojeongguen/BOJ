#include <iostream>
#include <vector>
using namespace std;
vector<int> vec;
void print() {
	cout << " print : ";
	for (int i = 0;i< vec.size(); i++) {
		cout << vec[i] << " ";
	}
	cout << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, K,D;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> D;
		vec.push_back(D);
	}
	int cnt = 0;
	int size = vec.size();
	bool fail = false;
	for (int i = 0; i < size; i++) {
		if (vec[i] == 1) {p
			for (int j = i; j < i + K; j++) {
				if (j >= N) break;
				else {
					vec[j] = (vec[j] + 1) % 2;
				}
			}
			cnt++;
		}
		if (i == size - K) {
			for (int j = i; j < N; j++) {
				if (vec[j] == 1) {
					fail = true;
					break;
				}
			}
		}
		//print();
		if (fail) break;
	}
	if (fail) cout << "Insomnia\n";
	else cout << cnt << "\n";
}