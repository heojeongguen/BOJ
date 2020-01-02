#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
#define MAX_N 51
class Shark {
public:
	int size, speed, intel;
	Shark(int size, int speed, int intel) :
		size(size), speed(speed), intel(intel) {}

	bool operator < (const Shark  & b) const {
		if (this->size == b.size && this->speed == b.speed) 
			return this->intel > b.intel;
		else if (this->size == b.size) 
			return this->speed > b.speed;
		else 
			return this->size > b.size;
	}

	bool operator >= (const Shark  & b) const {
		if (this->size >= b.size && this->speed >= b.speed && this->intel >= b.intel) 
			return true;
		else 
			return false;
	}
}; vector<Shark> shark;

int A[MAX_N];
int B[MAX_N];
bool visit[MAX_N];
int N;

bool fun(int x) {
	visit[x] = true;
	for (int y = x + 1; y < N; y++) {
		if (shark[x] >= shark[y]) {
			if (B[y] == -1 || (!visit[B[y]] && fun(B[y]))) {
				A[x] = y;
				B[y] = x;
				return true;
			}
		}
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b, c; cin >> a >> b >> c;
		shark.push_back(Shark(a, b, c));
	}
	sort(shark.begin(), shark.end());
	int ans = N;
	memset(A, -1, sizeof(A));
	memset(B, -1, sizeof(B));
	for (int i = 0; i < N; i++) {
		if (A[i] == -1) {
			memset(visit, false, sizeof(visit));
			if (fun(i)) ans--;
			if (fun(i)) ans--;
		}
	}
	cout << ans << endl;
}