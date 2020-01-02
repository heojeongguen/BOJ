#include <iostream>
#include <vector>

using namespace std;

pair<char, char> map[27];

void pre(char now) {
	int now_id = (int)now - 65;
	cout << now;
	if (map[now_id].first != '.')
		pre(map[now_id].first);
	if (map[now_id].second != '.')
		pre(map[now_id].second);
}

void in(char now) {
	int now_id = (int)now - 65;
	if (map[now_id].first != '.')
		in(map[now_id].first);
	cout << now;
	if (map[now_id].second != '.')
		in(map[now_id].second);
}

void post(char now) {
	int now_id = (int)now - 65;
	if (map[now_id].first != '.')
		post(map[now_id].first);
	if (map[now_id].second != '.')
		post(map[now_id].second);
	cout << now;
}





int main() {
	int N;
	char root, left, right;
	cin >> N;
	for (int i = 0; i <= 26; i++) {
		map[i].first = '.';
		map[i].second = '.';
	}

	for (int i = 0; i < N; i++) {
		cin >> root >> left >> right;
		int id = (int)root - 65;
		map[id].first = left;
		map[id].second = right;

	}

	pre('A');
	cout << endl;
	in('A');
	cout << endl;
	post('A');
	cout << endl;
}