#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string w[7] = { "SUN", "MON","TUE","WED","THU","FRI","SAT" };
	int X, Y, x= 1,y =1,index=1;
	cin >> X >> Y;
	while (x != X || y != Y) {
		if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12) {
			y = max(1, (y + 1) % 32);
			if (y == 1) {
				x++;
			}
		}
		else if (x == 4 || x == 6 || x == 9 || x == 11) {
			y = max(1, (y + 1) % 31);
			if (y == 1) {
				x++;
			}
		}else{
			y = max(1, (y + 1) % 29);
			if (y == 1) {
				x++;
			}
		}
		index = (index + 1) % 7;
	}
	cout << w[index];
}