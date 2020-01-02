#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <set>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
vector<string> vec;
class Trie {
public:
	Trie *arr[26];
	int cnt;
	bool end;
	Trie() {
		cnt = 0; end = false;
		for (int i = 0; i < 26; i++) {
			arr[i] = 0;
		}
	}
	~Trie() {
		cnt = 0; end = false;
		for (int i = 0; i < 26; i++) {
			if (arr[i] != 0) delete arr[i];
		}
	}
	void push(string &str) {
		if (str.size() == 0) {
			// 문자열 처리가 완료되었다면
			// end flag를 갱신 시켜준다.
			end = true;
			return;
		}
		else {
			// 문자를 뒤에서 하나씩 빼면서 처리
			char data = str.back(); str.pop_back();
			int index = data - 'a';
			if (arr[index] == 0) {
				// 해당 문자에 대해서 존재하지 않는다면 trie 객체를 생성 하여 준다
				arr[index] = new Trie();
				// cnt를 증가를 통해 이번 문자열에서 뻗어나가는 가지수를 늘려준다
				cnt++;
			}
			arr[index]->push(str);
		}
	}
	int query(string &str, int sum) {
		if (str.size() == 0) return sum;
		else {
			if (cnt > 1 || end) {
				// 현재 객체에 대해서 2가지 이상의 가지가 더 존재한다면
				// 버튼 누른느 횟수를 증가시켜 준다.
				sum++;
			}
			char data = str.back(); str.pop_back();
			int index = data - 'a';
			return arr[index]->query(str, sum);
		}
	}
};


int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N;
	while (cin >> N) {
		Trie trie;
		vec.clear();
		for (int i = 0; i < N; i++) {
			string input;
			cin >> input;
			// string의 pop_back을 사용하기 위해 문자를 뒤짚어서 push 해줌
			reverse(input.begin(), input.end());
			vec.push_back(input);
			trie.push(input);
		}
		double ans = 0;
		// 첫문자에 대해서 하나만 가지고 있을경우를 따로 처리해줌
		if (trie.cnt == 1)
			ans += N;
		for (int i = 0; i < N; i++) {
			int tmp = trie.query(vec[i], 0);
			ans += tmp;
		}
		cout.precision(2);
		cout << fixed << ans / N << endl;
	}
}