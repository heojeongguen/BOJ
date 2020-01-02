#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <set>
#include <string>
#define endl '\n'

using namespace std;

class Info {
public:
	int order;
	int mit;
	int jisu;
	Info(int order, int mit, int jisu) {
		this->order = order;
		this->mit = mit;
		this->jisu = jisu;
	}
	bool operator ==(Info b) const {

	}
};

set<string> s;
set<string>::iterator iter;
vector<Info> vecB;
vector<pair<int,int>> vecTotal;

int sosu[100001];
vector<int> vec;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i <= 100000; i++) {
		if (sosu[i] == 0) {
			sosu[i] = 1;
			vec.push_back(i);
			for (int j = 2; i * j <= 100000; j++) {
				sosu[j*i] = -1;
			}
		}
	}
	int N, A, B, C;
	string str;

	cin >> N;
	for (int i = 0; i < N; i++) {
		vecTotal.clear();
		vecB.clear();
		cin >> A >> B >> C;
		int order = 0;
		for (const auto & x : vec) {
			if (A <= 1 && B <= 1) break;
			int cntA = 0;
			int cntB = 0;
			while (A % x == 0) {
				A /= x;
				cntA++;
			}
			while (B % x == 0) {
				B /= x;
				cntB++;
			}
			if (cntB != 0) {
				vecB.push_back(Info(order, x, cntB));
			}
			if (cntA + cntB != 0) {
				vecTotal.push_back({x, cntA + cntB});
				order++;
			}
		}
		str.clear();
		for (int i = 0; i < vecTotal.size(); i++) {
			if (i == vecTotal.size() - 1) {
				str += to_string(vecTotal[i].first) + '^' + to_string(vecTotal[i].second) + '*';
			}
			else {
				str += to_string(vecTotal[i].first) + '^' + to_string(vecTotal[i].second);
			}
		}
		s.insert(str);
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < vecB.size(); j++) {
				vecTotal[vecB[j].order].second += vecB[j].jisu;
			}
			str.clear();
			for (int j = 0; j < vecTotal.size(); j++) {
				if (j == vecTotal.size() - 1) {
					str += to_string(vecTotal[j].first) + '^' + to_string(vecTotal[j].second) + '*';
				}
				else {
					str += to_string(vecTotal[j].first) + '^' + to_string(vecTotal[j].second);
				}
			}
			s.insert(str);
		}
	}
	cout << s.size() << endl;
}