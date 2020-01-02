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
			// ���ڿ� ó���� �Ϸ�Ǿ��ٸ�
			// end flag�� ���� �����ش�.
			end = true;
			return;
		}
		else {
			// ���ڸ� �ڿ��� �ϳ��� ���鼭 ó��
			char data = str.back(); str.pop_back();
			int index = data - 'a';
			if (arr[index] == 0) {
				// �ش� ���ڿ� ���ؼ� �������� �ʴ´ٸ� trie ��ü�� ���� �Ͽ� �ش�
				arr[index] = new Trie();
				// cnt�� ������ ���� �̹� ���ڿ����� ������� �������� �÷��ش�
				cnt++;
			}
			arr[index]->push(str);
		}
	}
	int query(string &str, int sum) {
		if (str.size() == 0) return sum;
		else {
			if (cnt > 1 || end) {
				// ���� ��ü�� ���ؼ� 2���� �̻��� ������ �� �����Ѵٸ�
				// ��ư ������ Ƚ���� �������� �ش�.
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
			// string�� pop_back�� ����ϱ� ���� ���ڸ� ��¤� push ����
			reverse(input.begin(), input.end());
			vec.push_back(input);
			trie.push(input);
		}
		double ans = 0;
		// ù���ڿ� ���ؼ� �ϳ��� ������ ������츦 ���� ó������
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