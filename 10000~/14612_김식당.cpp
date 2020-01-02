#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<pair<int, int> > vec;
//vector<pair<int, int> >::iterator iter;
bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

void print() {
	if (vec.empty()) cout << "sleep\n";
	else {
		for (const auto & x : vec) {
			cout << x.first << " ";
		}
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N, M;
	int n, t;
	string input;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> input;
		if (input == "order") {
			cin >> n >> t;
			vec.push_back(make_pair( n,t ));
			print();
		}else if(input == "sort"){
			sort(vec.begin(), vec.end(), cmp);
			print();
		}
		else if (input == "complete") {
			cin >> n;
			for (int i = 0; i < vec.size(); i++) {
				if (vec[i].first == n) {
					vec.erase(vec.begin() + i);
					break;
				}
			}
			print();
		}
		
	}
	return 0;
}





