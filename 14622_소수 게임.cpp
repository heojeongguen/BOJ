#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#define endl '\n'
using namespace std;
int arr[5000001];
vector<int> a_list;
vector<int> b_list;
set<int> s;
set<int>::iterator iter;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	int a, b;
	long long a_point = 0;
	long long b_point = 0;
	for (int i = 2; i <= 5000000; i++) {
		if (arr[i] == 0) {
			arr[i] = 1;
			for (int j = 2; i * j <= 5000000; j++) {
				arr[j * i] = -1;
			}
		}
		
	}
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		//cout << a << " : " << arr[a] << " " << b << " : " << arr[b] << endl;
		if (arr[a] != 1) {
			if (b_list.size() < 3) b_point += 1000;
			else b_point += b_list[2];
		}
		else {
			iter = s.find(a);
			if (iter == s.end()) {
				s.insert(a);
				a_list.push_back(a);
				sort(a_list.begin(), a_list.end(),greater<int>());
				if (a_list.size() == 4) a_list.pop_back();
			}
			else {
				a_point -= 1000;
			}
		}

		if (arr[b] != 1) {
			if (a_list.size() < 3) a_point += 1000;
			else a_point += a_list[2];
		}
		else {
			iter = s.find(b);
			if (iter == s.end()) {
				s.insert(b);
				b_list.push_back(b);
				sort(b_list.begin(), b_list.end(), greater<int>());
				if (b_list.size() == 4) b_list.pop_back();
			}
			else {
				b_point -= 1000;
			}
		}
		//cout << a_point << " " << b_point << endl;
	}
	if (a_point > b_point) cout << "소수의 신 갓대웅" << endl;
	else if(a_point < b_point) cout << "소수 마스터 갓규성" << endl;
	else cout << "우열을 가릴 수 없음" << endl;
}