#include <iostream>
#include <map>
#include <string>
#include <cstdlib>
using namespace std;
map<string, int> m;
map<int, string> mm;
map<string, int>::iterator m_iter;
map<int, string>::iterator mm_iter;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, Q;
	string str;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> str;
		m.insert(make_pair(str, i + 1));
		mm.insert(make_pair(i + 1, str));
	}


	for (int i = 0; i < Q; i++) {
		cin >> str;
		if ((int)str[0] - 48 <= 9 && (int)str[0] - 48 >= 0) {
			int id = atoi(str.c_str());
			mm_iter = mm.find(id);
			cout << mm_iter->second << "\n";
		}
		else {
			m_iter = m.find(str);
			cout << m_iter->second << "\n";
		}
	}
}