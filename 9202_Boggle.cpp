#pragma warning(disable:4996)
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
#include <stdio.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define endl '\n'
//--------------------------------------------------------------------------------------
set<string> s;
set<string> word[9];
char arr[4][4];
int maxSize = 0;
int maxScore = 0;
int cnt = 0;

int getPoint(int size) {
	if (size == 1 || size == 2) return 0;
	else if (size == 3 || size == 4) return 1;
	else if (size == 5) return 2;
	else if (size == 6) return 3;
	else if (size == 7) return 5;
	else if (size == 8) return 11;
}

pair<int, int> dxdy[8] = { {1,0}, {-1,0},{0,1},{0,-1},{-1,1},{1,-1},{-1,-1},{1,1} };
bool visit[4][4];
class Trie {
public:
	Trie *arr[26];
	bool end;
	Trie() {
		end = false;
		for (int i = 0; i < 26; i++) {
			arr[i] = 0; 
		}
	}

	void push(const char * key) {
		if (*key == '\0') {
			end = true;
			return;
		}
		int index = *key - 'A';
		if (arr[index] == 0) {
			arr[index] = new Trie();
		}
		arr[index]->push(key+1);
	}

	bool query(const char * key) {
		if (*key == '\0') {
			if (end == true) {
				return true;
			}
			else {
				return false;
			}
		}
		int index = *key - 'A';

		if (arr[index] == 0) {
			return false;
		}
		
		return arr[index]->query(key+1);
	}
};


Trie trie;
int pos = 0; char str[10];
void dfs(int r, int c) {
	visit[r][c] = true;
	str[pos++] = arr[r][c];

	if (pos > 0) {
		bool tmp = trie.query(str);
		if (tmp == true) {
			auto iter = word[pos].find(str);
			if (iter == word[pos].end()) {
				//cout << "find : " << str << endl;
				maxScore += getPoint(pos);
				maxSize = max(maxSize, pos);
				word[pos].insert(str);
				cnt++;
			}
		}
	}

	if (pos == 8) {
		visit[r][c] = false;
		str[pos--] = '\0';
		return;
	}

	
	for (int i = 0; i < 8; i++) {
		int nr = r + dxdy[i].first;
		int nc = c + dxdy[i].second;
		if (nr < 0 || nr >= 4 || nc < 0 || nc >= 4) continue;
		if (visit[nr][nc] == false) {
			dfs(nr, nc);
		}
	}
	str[pos--] = '\0';
	visit[r][c] = false;
}


int main() {
	//ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int w; scanf("%d", &w);
	while (w--) {
		char c[10];
		scanf("%s", &c);
		trie.push(c);
	}
	int b; cin >> b;
	while (b--) {
		for (int i = 1; i <= 8; i++) {
			word[i].clear();
		}
		maxScore = 0;
		maxSize = 0;
		cnt = 0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> arr[i][j];
			}
		}

		for (int j = 0; j < 4; j++) {
			for (int z = 0; z < 4; z++) {
				memset(visit, false, sizeof(visit));
				for (int y = 0; y < 10; y++) {
					str[y] = '\0';
				}
				pos = 0;
				dfs(j, z);
			}
		}
		cout << maxScore << " " << *word[maxSize].begin() << " " << cnt << endl;
	}
	
}