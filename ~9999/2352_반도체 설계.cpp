#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int arr[40001];

// LCS (���� ���� ����)
// �⺻���� LCS ����� O(N^2)

// lower_bound
// lower_bound�� �̿� �ϸ� O(NlogN)���� �� �� ��������
// ������ � ������ ��������� �� �� ����.

// indexTree
// indexTree�� �̿��� ����� NlogN���� N���� ���� �� �� �ִ�.
// �׷��� �̹���� �ߺ��� ���� ������ �ȵȴ�.
// ���� �̹���� ������ , � ������ ��������� �� �� ����.

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