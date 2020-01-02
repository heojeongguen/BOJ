#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;


unsigned long long arr[100001];
stack <int> st;
unsigned long long N;
unsigned long long histo() {
	unsigned long long ret = 0;
	unsigned long long index = -1;
	unsigned long long i;
	st.push(-1);
	for (i = 0; i < N; i++) {
		while (!st.empty() && arr[i] < arr[st.top()]) {
			unsigned long long tmp = st.top(); st.pop();
			if (!st.empty())
				ret = max(ret, arr[tmp] * (i - st.top() - 1));
		}
		st.push(i);
	}

	while (!st.empty()) {
		unsigned long long tmp = st.top();	st.pop();

		if (!st.empty()) 
			ret = max(ret, arr[tmp] * (i - st.top() -1));
	
	}
	return ret;
}

int main() {

	while (true) {
		cin >> N;
		if (N == 0) {
			break;
		}
		else {
			for (int i = 0; i < N; i++) {
				cin >> arr[i];
			}
			cout << histo() << endl;
		}
	}
}