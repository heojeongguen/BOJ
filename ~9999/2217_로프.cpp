#include <iostream>
#include <algorithm>
#include <vector>
using namespace  std;
int N;

int dp[10001];
int A[10001];
vector<int> vec;
int main() {
	int D;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> D;
		vec.push_back(D);
	}
	int prev = -1;
	sort(vec.begin(), vec.end()); 
	for(int i = 0 ; i < vec.size(); i++){
			prev = max(prev,(int)(vec.size() - i) * vec.at(i));

	}
	cout << prev << endl;
}