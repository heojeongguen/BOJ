#include <iostream>
#include <queue>
#include <stack>
#define cin std::cin
#define cout std::cout
#define endl '\n'

using namespace std;

int main() {
	queue<int> line;
	stack<int> waiting;
	int n, input;
	int last = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input;
		line.push(input);
	}
	while (!line.empty()) {
		int now = line.front(); line.pop();
		if (last + 1 == now) last = now;
		else waiting.push(now);
		

		while(!waiting.empty() && last + 1 == waiting.top()) {
			last = waiting.top(); waiting.pop();
		}
	}

	while (!waiting.empty() && last + 1 == waiting.top()) {
		last = waiting.top(); waiting.pop();
	}
	if (last == n) {
		cout << "Nice" << endl;
	}
	else {
		cout << "Sad" << endl;
	}
}