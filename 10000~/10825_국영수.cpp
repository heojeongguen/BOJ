#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

vector<tuple<string, int, int, int>> vec;

bool compare(tuple<string, int, int, int> a, tuple<string, int, int, int> b) {
	if (get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b) && get<3>(a) == get<3>(b)) return get<0>(a) < get<0>(b);
	else if(get<1>(a) == get<1>(b) && get<2>(a) == get<2>(b)) return get<3>(a) > get<3>(b);
	else if (get<1>(a) == get<1>(b)) return get<2>(a) < get<2>(b);
	else return  get<1>(a) > get<1>(b);
}

int main() {
	int N;
	string str;
	int A, B, C;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str >> A >> B >> C;
		vec.push_back(make_tuple(str, A, B, C));
	}
	sort(vec.begin(), vec.end(), compare);
	for (const auto &x : vec) {
		cout << get<0>(x) << "\n";
	}
}