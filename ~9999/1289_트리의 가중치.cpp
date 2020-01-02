#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> map[100001];

long long multi = 0;
long long add = 0;
long long DIV = 1000000007;
long long total = 0;

// 만약 자식이 3명이다?
// 첫번쨰 sub트리 처리
// 두번쨰 sub트리에는 첫번째에서 가져온 값이 영향을 미침
// 세번째는 첫번째와 두번째가 합쳐진값이 영향을 미침
long long dfs(int now, int prev) {
	long long ret = 1;
	long long tmp;
	for (const auto & x : map[now]) {
		if (x.first != prev) {
			// 어느 자식과 자기 node와의 값.
			tmp = dfs(x.first, now) * x.second % DIV;
			// ret 이 1인경우 첫번째 자식의 경우가될것임.
			total = (total + tmp * ret) % DIV;
			// 자식 하나가 끝나면 ret을 update 해줌.
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

	// 아무대서나 시작해도됨
	// 자기 자식 하나 들리고 그 값을 다른 자식에게 전달하는방식.
	dfs(1, -1);
	cout << total << "\n";
}