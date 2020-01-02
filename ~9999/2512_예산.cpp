#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long arr[100000];
vector <unsigned long long> vec;
int main() {
	unsigned long long N, data, M, total, Max_element;
	total = 0;
	cin >> N;
	Max_element = 0;
	for (int i = 0; i < N; i++) {
		cin >> data;
		arr[i] = data;
		total += data;
		if (Max_element < data) {
			Max_element = data;
		}
	}
	cin >> M;
	unsigned long long Max = 1000000000;
	unsigned long long Min = 0;
	unsigned long long sum = 0;
	unsigned long long Mid;

	if (M >= total) {
		cout << Max_element << endl;
	}
	else {
		while (Min + 1 < Max) {
			Mid = (Max + Min) / 2;
			sum = 0;
			for (int i = 0; i < N; i++) {
				if (arr[i] > Mid) {
					sum += Mid;
				}
				else
					sum += arr[i];
			}
			if (M >= sum) {
				Min = Mid;
			}
			else {
				Max = Mid;
			}
		}
		cout << Min << endl;
	}
}

