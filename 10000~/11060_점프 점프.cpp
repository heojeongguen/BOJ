#include <iostream>
#include <algorithm>
using namespace std;
int N;
int arr[1001];
int dp[1001];
int jump(int now) {

	// �̷��������ϸ� ���� ���� ���������� �ʰ� ���� �ӵ��� ���� ����
	int &ret = dp[now];

	// ���ǿ��� �����°�� 0���� ( N ���� Ŀ���� ��쵵 ��� 0�� ������;
	// �������� N�� �Ѿ�ٴ� ���� N�� �̹� �湮�ߴٴ� �ǹ��̱� ������( ���� ������ N�̻��� �� ���ִٴ� �ǹ�)
	if (now >= N) return 0;

	// �ݺ� Ƚ�� ���̱�
	if (dp[now] != -1) return dp[now];


	// �ּڰ��� ���ϴ� ���̱� ������
	// ���ü��ִ� ������ ū ������ �ʱ�ȭ
	ret = 1001;

	// �ڽ��� ��ġ���� ���� ���ٸ� 1001�� �ٲ�
	// ���� ���� ���ٺ��� �ּڰ��� ���ϵ�
	for (int i = 1; i <= arr[now]; i++) {
		ret = min(ret, 1 + jump(now + i));
	}

	// ���� ����
	return ret;
}

int main() {
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	// ������ ����� 0�� ������ ���̱� ������ -1�� �ʱ�ȭ
	fill(dp, dp + 1001, -1);

	// DFS ����
	int ans = jump(1);

	// ���ǹ� ( �� �� �湮�� �ּ� 1 �̻��̱⶧���� N == 1 �̶�� 0�� ���� )
	if (N == 1) cout << 0 << endl;
	else if (ans == 1001)cout << -1 << endl;
	else cout << ans << endl;

	
	return 0;
}