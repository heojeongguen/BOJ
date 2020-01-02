#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
using namespace std;

int N, P, D1, D2;

vector<int> vec[7];


int main() {
	cin >> N >> P;
	int ans = 0;
	int cnt;
	for (int i = 0; i < N; i++) {
		cin >> D1 >> D2;
		vec[D1].push_back(D2);
	}
	for (int i = 1; i <= 6; i++) {
		stack<int> st;
		int move = 0;
		for (int j = 0; j < vec[i].size(); j++) {
			while (true) {
				if (st.empty()) {
					st.push(vec[i][j]);
					move++;
				}
				else if (st.top() < vec[i][j]) {
					st.push(vec[i][j]);
					move++;
					break;
				}
				else if (st.top() > vec[i][j]) {
					st.pop();
					move++;
				}
				else if (st.top() == vec[i][j]) {
					break;
				}
			}
		}
		ans += move;
	}
	cout << ans << endl;
}
