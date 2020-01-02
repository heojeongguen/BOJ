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

char arr[51];

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < 51; i++) {
		arr[i] = '!';
	}
	string input; 
	for (int i = 0; i < n; i++) {
		cin >> input;
		for (int i = 0; i < input.size(); i++) {
			if (arr[i] == '!') {
				arr[i] = input[i];
			}
			else {
				if (arr[i] == input[i]) continue;
				else arr[i] = '?';
			}
		}
	}
	for (int i = 0; i < input.size(); i++) {
		cout << arr[i];
	}
	cout << endl;
	
}