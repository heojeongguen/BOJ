#include <iostream>
#include <vector>
using namespace std;

bool flag[3][101];
bool score[3][101];
vector<int> person[201];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int a, b, c;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		person[i].push_back(a);
		person[i].push_back(b);
		person[i].push_back(c);

		if (flag[0][a] == false) {
			flag[0][a] = true;
			score[0][a] = true;
		}
		else {
			score[0][a] = false;
		}

		if (flag[1][b] == false) {
			flag[1][b] = true;
			score[1][b] = true;
		}
		else {
			score[1][b] = false;
		}

		if (flag[2][c] == false) {
			flag[2][c] = true;
			score[2][c] = true;
		}
		else {
			score[2][c] = false;
		}
	}

	for (int i = 0; i < N; i++) {
		int tmp = 0;
		if (score[0][ person[i][0] ]) tmp += person[i][0];
		if (score[1][ person[i][1] ]) tmp += person[i][1];
		if (score[2][ person[i][2] ]) tmp += person[i][2];
		cout << tmp << "\n";
	}
	return 0;
}