#include <iostream>
#include <deque>
using namespace std;

int main() {
	int arr[100];
	deque<unsigned long long> bq;
	deque<unsigned long long> wq;
	bool blue = true;
	int T,N;
	cin >> T;
	for (int i = 0; i < T; i++) {
		unsigned long long arr[101];
		bq.clear();
		wq.clear();
		arr[0] = 1;
		arr[1] = 1;
		arr[2] = 1;
		arr[3] = 2;
		arr[4] = 2;
		arr[5] = 3;
		bq.push_back(1);
		bq.push_back(2);
		wq.push_back(1);
		wq.push_back(2);
		wq.push_back(3);
		
		blue = true;
		cin >> N;
		if (N <= 5) {
			cout << arr[N - 1] << endl;
		}
		else {
			for (int i = 6; i < N; i++) {
				if (blue) {
					arr[i] = wq.front() + wq.back();
					bq.push_back(arr[i]);
					wq.pop_front();
					blue = false;
				}
				else {
					arr[i] = bq.front() + bq.back();
					wq.push_back(arr[i]);
					bq.pop_front();
					blue = true;
				}
			}
			cout << arr[N - 1] << endl;
		}
		
	}
}