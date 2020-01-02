#include <iostream>
using namespace std;

int parent[100001];
bool check[100001];
int n;

int main() {
	cin >> n;
	check[1] = true;
	parent[1] = 0;
	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		if (check[a] == true) {
			check[b] = true;
			parent[b] = a;
		}
		else if (check[b] == true) {
			check[a] = true;
			parent[a] = b;
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << parent[i] << "\n";
	}

	return 0;
}