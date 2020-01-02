#include <iostream>
#include <map>
using namespace std;
unsigned long long byQ(unsigned long long, unsigned long long, unsigned long long);
unsigned long long byP(unsigned long long, unsigned long long, unsigned long long);
map<unsigned long long, unsigned long long> m;
unsigned long long byP(unsigned long long n, unsigned long long p, unsigned long long q) {
	if (m.count(n) == 1) {
		return m.find(n)->second;
	}
	if (n == 0){
		return 1;
	}
	else if (n == 1) {
		return 2;
	}
	else {
		unsigned long long result = byP(n / p, p, q) + byQ(n / q, p, q);
		m.insert(make_pair(n, result));
		return result;
	}
}

unsigned long long byQ(unsigned long long n, unsigned long long p, unsigned long long q) {
	if (m.count(n) == 1) {
		return m.find(n)->second;
	}
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return 2;
	}
	else {
		unsigned long long result = byP(n / p, p, q) + byQ(n / q, p, q);
		m.insert(make_pair(n, result));
		return result;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	unsigned long long N, P, Q;
	cin >> N >> P >> Q;
	if (N == 0) {
		cout << 1 << "\n";
	}
	else if (N == 1) {
		cout << 2 << "\n";
	}
	else {
		cout << byP(N / P, P, Q) + byQ(N / Q, P, Q) << "\n";
	}
}