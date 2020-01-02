#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> map[100001];

long long multi = 0;
long long add = 0;
long long DIV = 1000000007;
long long total = 0;

// ���� �ڽ��� 3���̴�?
// ù���� subƮ�� ó��
// �ι��� subƮ������ ù��°���� ������ ���� ������ ��ħ
// ����°�� ù��°�� �ι�°�� ���������� ������ ��ħ
long long dfs(int now, int prev) {
	long long ret = 1;
	long long tmp;
	for (const auto & x : map[now]) {
		if (x.first != prev) {
			// ��� �ڽİ� �ڱ� node���� ��.
			tmp = dfs(x.first, now) * x.second % DIV;
			// ret �� 1�ΰ�� ù��° �ڽ��� ��찡�ɰ���.
			total = (total + tmp * ret) % DIV;
			// �ڽ� �ϳ��� ������ ret�� update ����.
			ret = (ret + tmp) % DIV;
		}
	}
	return ret % DIV;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, data1, data2, wei;
	cin >> n;
	for (int i = 1; i <= n - 1; i++) {
		cin >> data1 >> data2 >> wei;
		map[data1].push_back(make_pair(data2, wei));
		map[data2].push_back(make_pair(data1, wei));
	}

	// �ƹ��뼭�� �����ص���
	// �ڱ� �ڽ� �ϳ� �鸮�� �� ���� �ٸ� �ڽĿ��� �����ϴ¹��.
	dfs(1, -1);
	cout << total << "\n";
}