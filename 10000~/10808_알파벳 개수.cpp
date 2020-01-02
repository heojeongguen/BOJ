#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
int arr[26];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string input; cin >> input;
	for (int i = 0; i < input.size(); i++) {
		arr[input[i] - 97]++;
	}
	for (int i = 0; i < 26; i++) {
		cout << arr[i] << " ";
	}
}