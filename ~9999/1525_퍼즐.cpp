#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

#define endl '\n'
typedef long long ll;

// 1차원으로 어디로 이동해야하는지 알수있긴함
// 브루트포스를 하되 현재상태를 어떤방법으로 저장하지?
// bfs돌면서 map에 저장하면 시간초과?
// string으로 저장하게되면 분명 시간초과
// int형으로 저장하려면 0을 처리해줘야대니까 0을 9로

int arr[3][3];

int arrtoi() {
	int ret = 0;
	int tmp = 1;
	for (int i = 2; i >= 0; i--) {
		for (int j = 2; j >= 0; j--) {
			ret += tmp * arr[i][j];
			tmp *= 10;
		}
	}
	return ret;
}

string itos(int x) {
	string ret;
	while (x > 0) {
		ret.push_back(char(x % 10 + '0'));
		x /= 10;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

set<int> s;
string ans = "123456789";
queue<pair<int, int>> que;

vector<int> vec[9];
int bfs() {
	// 0 : 1, 3
	vec[0].push_back(1);
	vec[0].push_back(3);

	// 1 : 0, 2, 4
	vec[1].push_back(0);
	vec[1].push_back(2);
	vec[1].push_back(4);

	// 2 : 1, 5
	vec[2].push_back(1);
	vec[2].push_back(5);
	
	// 3 : 0, 4, 6
	vec[3].push_back(0);
	vec[3].push_back(4);
	vec[3].push_back(6);

	// 4 : 1, 3, 5, 7
	vec[4].push_back(1);
	vec[4].push_back(3);
	vec[4].push_back(5);
	vec[4].push_back(7);

	// 5 : 2, 4, 8
	vec[5].push_back(2);
	vec[5].push_back(4);
	vec[5].push_back(8);

	// 6 : 3, 7
	vec[6].push_back(3);
	vec[6].push_back(7);

	// 7 : 4, 6, 8
	vec[7].push_back(4);
	vec[7].push_back(6);
	vec[7].push_back(8);

	// 8 : 5, 7
	vec[8].push_back(5);
	vec[8].push_back(7);


	int start = arrtoi();
	que.push({ start,0 });
	s.insert(start);
	while (!que.empty()) {
		int now = que.front().first;
		int cnt = que.front().second;
		que.pop();
		string str = itos(now);
		if (str == ans) {
			//cout << str << " == " << ans << endl;
			while (!que.empty()) que.pop();
			return cnt;
		}
		int pos = 0;
		for (int i = 0; i < str.size(); i++) {
			if (str[i] == '9') {
				pos = i;
				break;
			}
		}
		for (int i = 0; i < vec[pos].size(); i++) {
			string tmp = str;
			swap(tmp[pos], tmp[vec[pos][i]]);
			int x = stoi(tmp);
			if (s.find(x) == s.end()) {
				que.push({x,cnt+1});
				s.insert(x);
			}
		}

	}
	return -1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			int data; cin >> data;
			if (data == 0) arr[i][j] = 9;
			else arr[i][j] = data;
		}
	}
	cout << bfs() << endl;
}