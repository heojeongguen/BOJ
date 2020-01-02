#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <cmath>
using namespace std;

int main() {
	int N, gap, size, count,temp;
	cin >> N;
	int loop = N;
	count = 0;
	for (int i = 0; i < loop; i++) {
		gap = 0;
		size = log10(N) + 1;
		if (size == 1 || size == 2) {
			count++;
		}
		else {
			bool suc = true;
			vector<int> vec;
			int div = 1;
			int origin = N;
			vec.clear();
			for (int i = size; i >= 0; i--) {
				temp = origin;
				origin = (temp % (int)(pow(10.0, i)));
				temp = temp - (temp % (int)(pow(10.0, i)));
				vec.push_back(temp / (pow(10.0, i)));
			}
			gap = vec.at(1) - vec.at(2);
			for (int i = 1; i < vec.size() - 1; i++) {
				if (gap != vec.at(i) - vec.at(i+1)) {
					suc = false;
					break;
				}
			}
			/*cout << "[ " << N << " ] : { ";
			for (const auto &x : vec) {
				cout << x << ",";
			}
			cout << " } " << suc << endl;*/
			if (suc) {
				count++;
			}
		}
		N--;
	}
	cout << count;
}