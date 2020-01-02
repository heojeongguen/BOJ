#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long int ll;
#define MMAX 65535
#define NMAX 250001
#define LEFT(i) (i * 2)
#define RIGHT(i) (i*2+1)
// *3인 이유? (l == r) 즉 , 리프노드가 우선 n 개 있다
// 반씩 합쳐나가다보면 루트기준 왼쪽에서 n개 루트기준 오른쪾에 n개 총 3n개가 된다.
int tree[NMAX * 3];
int arr[NMAX];

// nowNode의 의미 : 현재 노드번호 ( 1번노드는 0 ~ MMAX의 범위)
// leftnode : 자기가 가지고 있는 범위의 왼쪽 ~ 중간
// righnode : 자기가 가지고 있는 범위의 중간 + 1 ~ 오른쪾
// l : 자기 범위 왼쪽끝
// r : 자기 범위 오른쪽 끝;
// ADD : ture => 데이터 insert
// ADD : false => 데이터 delete
void updateTree(int nowNode, int num, int l, int r, bool ADD) {
	// 현재 자기구간의 중간 값 m
	int m = (l + r) / 2;

	// 숫자가 자신의 범위에 포함된다면 자기의 값을늘려줘야함.
	if (num >= l && num <= r) {
		if (ADD) tree[nowNode]++;
		else tree[nowNode]--;
	}
	else {
		return;
	}

	// (리프노드의 경우) 리턴
	if (l == r) return;

	// 왼쪽자식에 대해서 l ~ m
	updateTree(nowNode * 2, num, l, m, ADD);
	// 오른쪽 자식에 대해서 m + 1 ~ r
	updateTree(nowNode * 2 + 1, num, m + 1, r, ADD);
}

void deleteTree(int deleteNum, int insertNum) {
	// 삭제
	updateTree(1, deleteNum, 0, MMAX, false);
	// 삽입
	updateTree(1, insertNum, 0, MMAX, true);
}

int getMedian(int nowNode, int k, int l, int r) {
	// 파라미터 k는 고정된값임 ( 처음 입력에 k를 입력받았다면. ((1+k)/2) -> 파라미터 k가 된다.
	int mid = (l + r) / 2;

	// 리프노드에 도착하면 리턴 l.
	if (l == r) return l;


	// 자기 왼쪽자식 노드의 값이 k 보다 작다 -> 오른쪽에 중간값이 있겠구나.
	// 자기 왼쪽자식 노드의 값이 k 보다 크다 -> 왼쪽에 중간값이 있겠구나.
	if (tree[nowNode * 2] < k)
		getMedian(nowNode * 2 + 1, k - tree[nowNode * 2], mid + 1, r);
	else
		getMedian(nowNode * 2, k, l, mid);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;
	ll tot = 0;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < k; i++) {
		updateTree(1, arr[i], 0, MMAX, true);
	}
	tot += getMedian(1, (k + 1) / 2, 0, MMAX);

	for (int i = 0; i < n - k; i++) {
		deleteTree(arr[i], arr[i + k]);
		tot += getMedian(1, (k + 1) / 2, 0, MMAX);
	}
	cout << tot << "\n";
}