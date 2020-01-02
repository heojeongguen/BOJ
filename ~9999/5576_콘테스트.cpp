#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	vector<int> vec;
	int d;
	int arr[2];
	for (int i = 0; i < 2; i++) {
		vec.clear();
		for (int j = 0; j < 10; j++) {
			cin >> d;
			vec.push_back(d);
		}
		sort(vec.begin(), vec.end());
		arr[i] = vec[9] + vec[8] + vec[7];
	}
	cout << arr[0] << " " << arr[1] << endl;
}