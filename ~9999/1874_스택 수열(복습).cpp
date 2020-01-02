#include <iostream>
#include <stack>
#include <vector>

using namespace std;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	vector<int> vec;
	int N, D;
	cin >> N;
	stack<int> st;
	vector<char> ans;
	int cur = 1;
	int vec_cur = 0;
	for (int i = 1; i <= N; i++) {
		cin >> D;
		vec.push_back(D);
	}
	while (vec_cur < N) {
		if (st.empty()) {
			st.push(cur);
			cur++;
			ans.push_back('+');
		}
		else if (st.top() == vec[vec_cur]) {
			st.pop();
			ans.push_back('-');
			vec_cur++;
		}
		else if (st.top() > vec[vec_cur]) {
			ans.clear();
			ans.push_back('N');
			ans.push_back('O');
			break;
		}
		else if (st.top() < vec[vec_cur]) {
			st.push(cur);
			cur++;
			ans.push_back('+');
		}
	}
	for (const auto & x : ans) {
		if (x == 'N') {
			cout << "NO" << endl;
			break;
		}
		else {
			cout << x << "\n";
		}
	}
}