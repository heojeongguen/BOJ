#include <iostream>
#include <vector>
using namespace std;
vector<pair<int, int> > vec[100001];
int DIV = 1000000007;
long long total;
long long dfs(int now, int prev) {
	long long tmp;
	long long ret = 1;

	for (const auto & x : vec[now]) {
		if (x.first != prev) {
			tmp =	dfs(x.first,now )* x.second % DIV;
			total += (tmp * ret) % DIV;
			ret += (tmp + ret) % DIV;
		}
	}
}


int main() {
	int N;	
	int a, b, wei;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> wei;
		vec[a].push_back(make_pair(b, wei));
		vec[b].push_back(make_pair(a, wei));
	}

}