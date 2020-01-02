#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> ans;
int main() {
	int t, n,d;
	cin >> t;
	while (t--) {
		ans.clear();
		priority_queue<int, vector<int>, less<> > mmax;
		priority_queue<int, vector<int>, greater<> > mmin;

		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> d;
			
			if (mmax.empty()) mmax.push(d);
			else if (mmax.top() <= d) mmin.push(d);
			else mmax.push(d);

			if (mmax.size() < mmin.size()) {
				int tmp = mmin.top();
				mmin.pop();
				mmax.push(tmp);
			}
			else if (mmax.size() > mmin.size() + 2) {
				int tmp = mmax.top();
				mmax.pop();
				mmin.push(tmp);;
			}
			if((i + 1 )% 2 == 1) ans.push_back(mmax.top());
		}
		cout << ans.size() << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
			if ((i + 1) % 10 == 0) cout << "\n";
		}
		cout << "\n";
	}
}
