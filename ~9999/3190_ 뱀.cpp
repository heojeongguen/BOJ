#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 스택 ? 으로 풀면 되러같은데
queue<pair<int,int>> que;
int N, A, Q;
int arr[101][101];
vector<pair<int, char > >L;
pair<int, int> dxdy[4] = { {-1,0},{0,1},{1,0},{0,-1} };
int direc = 1;
int time = 0;
int R = 1, C = 1;
bool dead = false;

void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void move() {
	for (int i = 0; i < L.size(); i++) {
		pair<int, char> top = L[i];
		int st = time;
		for (int j = st; j < top.first; j++) {
			time++;
			R = R + dxdy[direc].first;
			C = C + dxdy[direc].second;


			if (R < 1 || R > N || C < 1 || C > N) {
				dead = true;
				break;
			}

			if (arr[R][C] == 2) {
				arr[R][C] = 1;
				que.push({ R,C });
			}
			else if (arr[R][C] == 1) {
				dead = true;
				break;
			}
			else {
				arr[R][C] = 1;
				pair<int, int> tail = que.front(); que.pop();
				arr[tail.first][tail.second] = 0;
				que.push({ R,C });
			}
			
		}
		if (dead) break;
		else {
			// 왼쪽
			if (top.second == 'L') {
				direc--;
				if (direc < 0) direc = 3;
			}
			else {
				direc++;
				if (direc > 3) direc = 0;
			}
		}
	}
	while(true) {
		if (dead) break;
		time++;
		R = R + dxdy[direc].first;
		C = C + dxdy[direc].second;
		if (R < 1 || R > N || C < 1 || C > N) {
			dead = true;
			break;
		}

		if (arr[R][C] == 2) {
			arr[R][C] = 1;
			que.push({ R,C });
		}
		else if (arr[R][C] == 1) {
			dead = true;
			break;
		}
		else {
			arr[R][C] = 1;
			pair<int, int> tail = que.front(); que.pop();
			arr[tail.first][tail.second] = 0;
			que.push({ R,C });

		}

	}
}

int main() {
	cin >> N;
	cin >> A;
	int a, b;
	for (int i = 0; i < A; i++) {
		cin >> a >> b;
		arr[a][b] = 2;
	}
	char c;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> a >> c;
		L.push_back({ a,c });
	}
	arr[1][1] = 1;
	que.push({ 1,1 });
	move();
	cout << time << endl;
}