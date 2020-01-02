#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	pair<int,int> cur = { x , y };
	pair<int, int> squre{ w , h };
	cout << min({ abs(x - w), abs(y - h),x,y }) << endl;
}