#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> UP;
vector<int> DOWN;
vector<int> UUP;
vector<int> DDOWN;
int main() {
	int W, H, D;
	cin >> W >> H;
	for (int i = 0; i < W; i++) {
		cin >> D;
		if (i % 2 == 0) {
			UP.push_back(D);
		}
		else {
			DOWN.push_back(H - D);
		}
	}
	sort(DOWN.begin(), DOWN.end());
	sort(UP.begin(), UP.end());

	for (int i = 0; i < UP.size(); i++) {
		UUP.push_back((UP.size() - i));
	}



	for (int i = 0; i < UP.size(); i++) {
		UUP.push_back((DOWN.size() - i));
	}
}