#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	string str;
	set<string> string_set;
	int ans = 0;
	cin >> str;
	for (int jump = 0; jump < str.size(); jump++) {
		for (int start = 0; start + jump <= str.size(); start++) {
			string sub_string(str.begin() + start, str.begin() + start + jump);
			string_set.insert(sub_string);
		}
	}
	cout << string_set.size() << endl;
}