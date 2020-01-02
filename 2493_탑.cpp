#include <iostream>
#include <stack>
#include <vector>;
using namespace std;

stack<pair<int, int>> st;
vector<pair<int,int>> vec;
int arr[500001];
int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int N,D;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> D;
		vec.push_back(make_pair(i,D));
	}

	for (int i = 0; i < vec.size(); i++) {
		if (st.empty()) {
			arr[vec[i].first] = 0;
			st.push(vec[i]);
		}
		else {
			while (true) {
				if (st.empty()) {
					st.push(vec[i]);
					break;
				}
				else if (st.top().second >= vec[i].second) {
					arr[vec[i].first] = st.top().first;
					st.push(vec[i]);
					break;
				}
				else if (st.top().second < vec[i].second) {
					st.pop();
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << arr[i] << " ";
	}
}