#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'
typedef long long ll;

#define MAX_N 1000000
vector<int> sosu;
bool check[MAX_N+1];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	sosu.push_back(-1);
	for (int i = 2; i <= MAX_N; i++) {
		if (!check[i]) {
			if(i != 2) 
				sosu.push_back(i);
			for (int j = 1; j * i <= MAX_N; j++) {
				check[j * i] = true;
			}
		}
	}
	sosu.push_back(MAX_N + 1);
	sosu.push_back(MAX_N + 2);

	int n;
	while (1) {
		cin >> n;
		if (n == 0) break;
		auto r = lower_bound(sosu.begin(), sosu.end(), n);
		bool find = false;
		for (auto r = lower_bound(sosu.begin(), sosu.end(), n); *r != -1; r--) {
			for (auto l = lower_bound(sosu.begin(), sosu.end(), n - *r); *l <= *r; l++) {
				if (*l == -1) continue;

				if (*r + *l == n) {
					cout << n << " = " << *l << " + " << *r << endl;
					find = true;
					break;
				}
				else if(*r + *l < n){
					break;
				}
				else {
					continue;
				}
			}
			if (find) break;
		}
		if (!find) cout << "Goldbach's conjecture is wrong." << endl;
	}
}