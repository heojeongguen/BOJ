#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int arr[40001];

// LCS (최장 증가 수열)
// 기본적인 LCS 기법은 O(N^2)

// lower_bound
// lower_bound를 이용 하면 O(NlogN)으로 줄 일 수있지만
// 과정과 어떤 수열을 만들었는지 알 수 없다.

// indexTree
// indexTree를 이용한 방법은 NlogN에서 N으로 줄일 수 가 있다.
// 그러나 이방법은 중복된 값이 있으면 안된다.
// 물론 이방법도 과정과 , 어떤 수열을 만들엇는지 알 수 없다.

bool compare(const pair<int, int> &a,const pair<int, int> & b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n ,d;
	cin >> n;
	vector<pair<int, int> > vvec;

	for (int i = 0; i < n; i++) {
		cin >> d;
		vvec.push_back(make_pair(i, d));
	}
	for (int i = 0; i < n; i++) {
		cin >> d;
		int tmp = 
		arr[i] = *max_element(arr, arr + i) + 1 ;
	}

	/*for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int mmax = 0;
	vec.push_back(arr[0]);

	for (int i = 1; i < n; i++) {
		d = arr[i];
		if (vec.back() < d) {
			vec.push_back(d);
		}
		else {
			auto iter = lower_bound(vec.begin(), vec.end(), d) - vec.begin();
			if (vec[iter] > d) vec[iter] = d;
		}
	}
	cout << vec.size() << endl;*/

}