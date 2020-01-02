#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int arr[1001];
int dp[1001];
vector<int> vec[100001];
int M = -1;
int T, N, K, data1, data2, W, ans;
bool find = false;
int fuc(int index) {
	if (vec[index].empty()) {
		return arr[index];
	}
	if (dp[index] != -1)  return dp[index];
	int MAX = -1;
	for (int i = 0; i < vec[index].size(); i++) {
		if (MAX == -1) {
			MAX = fuc(vec[index].at(i));
		} {
			MAX = max(MAX, fuc(vec[index].at(i)));
		}
	}
	dp[index] = MAX + arr[index];
	
	return dp[index];
}


int main() {

	deque<int> deq;
	cin >> T;
	while (T--) {
		ans = 0;
		M = -1;
		cin >> N >> K;
		deq.clear();
		for (int i = 1; i <= K; i++) {
			vec[i].clear();
		}
		for (int i = 0; i <= N; i++) {
			arr[i] = 0;
			dp[i] =  -1;
		}


		for (int i = 1; i <= N; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < K; i++) {
			cin >> data1 >> data2;
			vec[data2].push_back(data1);
		}
		
		cin >> W;
		deq.push_back(W);
		int MAX;
		int max_index;
		
		cout << fuc(W) << endl;
	}
}