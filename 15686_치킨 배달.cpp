#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
vector<pii> origin_chi;
vector<pii> chi;
vector<pii> house;
int N, M;
bool check[14];


int ans = 1e9;
void fuc(int now) {
	
	if (chi.size() == M) {
		/*cout << "삭제 : ";
		for (int i = 0; i < M; i++) {
			cout << "{" << chi[i].first << "," << chi[i].second << "} ";
		}
		cout << endl;*/
		int tmp_ans = 0;
		for (int i = 0; i < house.size(); i++) {
			int tmp = 1e9;
			for (int j = 0; j < chi.size(); j++) {
				int hx = house[i].first;
				int hy = house[i].second;
				int cx = chi[j].first;
				int cy = chi[j].second;
				tmp = min(tmp,abs(cx - hx) + abs(cy - hy));
			}
			tmp_ans += tmp;
			if (tmp_ans > ans) break;
		}
		ans = min(ans, tmp_ans);
		return;
	}
	if (now >= origin_chi.size()) return;

	chi.push_back({ origin_chi[now].first,origin_chi[now].second });
	check[now] = true;
	fuc(now + 1);
	chi.pop_back();
	check[now] = false;
	fuc(now + 1);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	// 그냥 13CM이니까 해볼까낭
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int data; cin >> data;
			if (data == 2)
				origin_chi.push_back({ i,j });
			else if (data == 1)
				house.push_back({ i,j });
		}
	}
	fuc(0);
	cout << ans << endl;
}