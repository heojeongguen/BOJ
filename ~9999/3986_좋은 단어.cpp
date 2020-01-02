#include <iostream>
#include <string>
#include <stack>
#include <string>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string str;
	int n;
	cin >> n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> str;
		stack<char> st;
		stack<char> A;
		stack<char> B;
		for (size_t j = 0; j < str.size(); j++){
			if (st.empty()) st.push(str[j]);
			else if (st.top() == str[j]) st.pop();
			else if (st.top() != str[j]) st.push(str[j]);
		}
		if (st.empty()) ans++;
	}
	cout << ans << endl;
}