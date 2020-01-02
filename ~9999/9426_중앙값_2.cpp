#include <iostream>
#include <algorithm>
using namespace std;
typedef unsigned long long int ll;
#define MMAX 65535
#define NMAX 250001
#define LEFT(i) (i * 2)
#define RIGHT(i) (i*2+1)
// *3�� ����? (l == r) �� , ������尡 �켱 n �� �ִ�
// �ݾ� ���ĳ����ٺ��� ��Ʈ���� ���ʿ��� n�� ��Ʈ���� �����U�� n�� �� 3n���� �ȴ�.
int tree[NMAX * 3];
int arr[NMAX];

// nowNode�� �ǹ� : ���� ����ȣ ( 1������ 0 ~ MMAX�� ����)
// leftnode : �ڱⰡ ������ �ִ� ������ ���� ~ �߰�
// righnode : �ڱⰡ ������ �ִ� ������ �߰� + 1 ~ �����U
// l : �ڱ� ���� ���ʳ�
// r : �ڱ� ���� ������ ��;
// ADD : ture => ������ insert
// ADD : false => ������ delete
void updateTree(int nowNode, int num, int l, int r, bool ADD) {
	// ���� �ڱⱸ���� �߰� �� m
	int m = (l + r) / 2;

	// ���ڰ� �ڽ��� ������ ���Եȴٸ� �ڱ��� �����÷������.
	if (num >= l && num <= r) {
		if (ADD) tree[nowNode]++;
		else tree[nowNode]--;
	}
	else {
		return;
	}

	// (��������� ���) ����
	if (l == r) return;

	// �����ڽĿ� ���ؼ� l ~ m
	updateTree(nowNode * 2, num, l, m, ADD);
	// ������ �ڽĿ� ���ؼ� m + 1 ~ r
	updateTree(nowNode * 2 + 1, num, m + 1, r, ADD);
}

void deleteTree(int deleteNum, int insertNum) {
	// ����
	updateTree(1, deleteNum, 0, MMAX, false);
	// ����
	updateTree(1, insertNum, 0, MMAX, true);
}

int getMedian(int nowNode, int k, int l, int r) {
	// �Ķ���� k�� �����Ȱ��� ( ó�� �Է¿� k�� �Է¹޾Ҵٸ�. ((1+k)/2) -> �Ķ���� k�� �ȴ�.
	int mid = (l + r) / 2;

	// ������忡 �����ϸ� ���� l.
	if (l == r) return l;


	// �ڱ� �����ڽ� ����� ���� k ���� �۴� -> �����ʿ� �߰����� �ְڱ���.
	// �ڱ� �����ڽ� ����� ���� k ���� ũ�� -> ���ʿ� �߰����� �ְڱ���.
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