#include <iostream>
#include <queue>
using namespace std;

int main() {
	queue<int> que;
	int N, temp;
	cin >> N;
	for (int i = 0; i < N; i++) {
		que.push(i + 1);
	}
	int loop = 0;
	while(true){
		if (que.size() == 1) {
			break;
		}
		if (loop % 2 == 0) {
			que.pop();
		}
		else {
			que.push(que.front());
			que.pop();
		}
		loop++;
	}
	cout << que.front();
}
