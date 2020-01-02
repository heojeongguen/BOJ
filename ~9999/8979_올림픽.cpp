#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class nation {
public:
	int id;
	int gold;
	int silver;
	int dong;
	nation(int id, int gold, int silver, int dong) {
		this->id = id;
		this->gold = gold;
		this->silver = silver;
		this->dong = dong;
	}
};

vector<nation> vec;

bool cmp(const nation & a, const nation & b) {
	if (a.gold == b.gold && a.silver == b.silver) {
		return a.dong > b.dong;
	}
	else if (a.gold == b.gold) {
		return a.silver > b.silver;
	}
	else {
		return a.gold > b.gold;
	}
}

bool operator ==(const nation & a, const nation & b) {
	if (a.gold == b.gold && a.silver == b.silver && a.dong == b.dong) {
		return true;
	}
	else false;
}

int main() {
	int N, Q;
	int id, A, B, C;
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		cin >> id >> A >> B >> C;
		vec.push_back(nation(id, A, B, C));
	}
	sort(vec.begin(), vec.end(), cmp);


	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].id == Q) {
			int ret = i + 1;
			for (int j = i - 1; j >= 0; j--) {
				if (vec[i].gold == vec[j].gold && vec[i].silver == vec[j].silver &&vec[i].dong == vec[j].dong) ret--;
				else break;
			}
			cout << ret << endl;
			break;
		}
	}

}