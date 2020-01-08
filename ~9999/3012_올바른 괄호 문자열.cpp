#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define endl '\n'
typedef long long ll;

const ll mod = 100000;
int N;
char arr[201];
ll dp[201][201];
bool check[201][201];

char open[5] = "({[";
char close[5] = ")}]";
bool overMod;

ll fun(int s, int e) {
	if (s > e) return 1;
	if (check[s][e]) return dp[s][e];
	ll& ret = dp[s][e];
	check[s][e] = true;
	ret = 0;
	for (int i = s + 1; i <= e; i ++) {
		for (int l = 0; l < 3; l++) {
			if (arr[s] == open[l] || arr[s] == '?') {
				if (arr[i] == close[l] || arr[i] == '?') {
					ll temp = fun(s + 1, i - 1) * fun(i + 1, e);
					ret += temp;
					if (ret >= mod) overMod = true;
					ret %= mod;
				}
			}
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		char c; cin >> c;
		arr[i] = c;
	}
	ll ret = fun(0, N - 1);
	if (overMod) {
		int size = (int)(log10(ret) + 1);
		for (int i = 0; i < 5 - size; i++) {
			cout << 0;
		}
		cout << ret << endl;
	}
	else {
		cout << ret << endl;
	}
}