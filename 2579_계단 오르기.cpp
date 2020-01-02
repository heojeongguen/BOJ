#include <iostream>
#include <algorithm>
using namespace std;
pair<int, bool> score[300] = { {0, false}, };
int arr[300];
int N;
int ans = 0;
void fuc(int index, int total, bool prev) {

	ans = max(ans, total);
	if (index < 0) {
		return;
	}
	else if (score[index].second == prev) {
		if (score[index].first >= total + arr[index]) {
			return;
		}
		else {
			score[index].first = total + arr[index];
			score[index].second = prev;
			if (prev) {
				fuc(index - 2, total + arr[index], false);
			}
			else {
				fuc(index - 1, total + arr[index], true);
				fuc(index - 2, total + arr[index], false);
			}
		}
	}
	else {

		if (prev) {
			fuc(index - 2, total + arr[index], false);
		}
		else {
			fuc(index - 1, total + arr[index], true);
			fuc(index - 2, total + arr[index], false);
		}
	}
}

int main() {
	cin >> N;
	int data;
	for (int i = 0; i < N; i++) {
		cin >> data;
		arr[i] = data;
	}

	fuc(N - 1, 0, false);
	cout << ans << endl;
	//for (int i = 0; i < N; i++) {
	//	cout << score[i].first << " " << score[i].second << endl;
	//}
}