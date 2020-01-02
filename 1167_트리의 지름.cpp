#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int,int>> vec[100001];
int dp[100001];

int V;
int node = 0 ;
int maxlen;
int fuc(int index, int from) {
	/*cout << "index : " << index << "from : " << from << endl;*/

	bool first = false;

	int result = 0;

	for (const auto &x : vec[index]) {
		if (!first) {
			if (x.first != from) {
				result = x.second + fuc(x.first, index);
				first = true;
			}
		}
		else {
			if (x.first != from) {
				result = max(result, x.second + fuc(x.first, index));
			}
		}
	}
	return result;
}

void findNode(int index, int from, int lenth) {
	bool first = false;

	int result = 0;
	bool find = false;
	


	for (const auto &x : vec[index]) {
		if (x.first != from) {
			 findNode(x.first, index, x.second + lenth);
			 find = true;
		}
	}
	if (find == false) {
		if (vec[index].size() == 1) {
			if (node == 0) {
				node = index;
				maxlen = lenth;
			}
			else {
				if (maxlen < lenth) {
					node = index;
					maxlen = lenth;
				}
			}
		}
	}
}

int main() {
	int start, end, len;
	cin >> V;
	for (int i = 1; i <= V; i++) {
		cin >> start;
		while (true) {
			cin >> end;
			if (end == -1) break;
			cin >> len;
			vec[start].push_back(make_pair(end, len));
		}
	}
	findNode(1, 0, 0);
	//cout << "node : " << node << " | maxLen : " << maxlen << endl;
	cout << fuc(node, 0) << endl;
}