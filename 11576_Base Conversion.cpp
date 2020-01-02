#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> vec;
int main() { 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int A, B , N,D;
	cin >> A >> B >> N;
	for (int i = 0; i < N; i++) {
		cin >> D;
		vec.push_back(D);
	}

	int total = 0;
	int multi = 1;
	for (int i = vec.size() - 1; i >= 0; i--) {
		total += multi * vec[i];
		multi *= A;
	}
	vector<int> ans ;

	while (total > 0) {
		if (total % B == 0) {
			ans.push_back(0);
		}
		else {
			ans.push_back(total % B);
		}
		total /= B;
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
	return 0;
}