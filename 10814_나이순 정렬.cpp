#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
using namespace std;

vector< tuple<int, string, int> > vec;

bool compare(tuple<int, string, int> a, tuple<int, string, int> b) {
	if (get<0>(a) == get<0>(b)) return get<2>(a) < get<2>(b);
	else return get<0>(a) < get<0>(b);
}

int main() {
	int N;
	int age;
	string name;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> age >> name;
		vec.push_back(make_tuple(age, name,i));
	}
	sort(vec.begin(), vec.end(), compare);
	for (const auto &x : vec) {
		cout << get<0>(x) << " " << get<1>(x) << "\n";
	}


}