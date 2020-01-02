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
int arr[5];
int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			int data; cin >> data;
			arr[i] += data;
		}
	}
	int mmax = -1;
	int num = -1;
	for (int i = 0; i < 5; i++) {
		if (mmax < arr[i]) {
			mmax = arr[i];
			num = i;
		}
	}
	cout << ++num << " " << mmax << endl;
}