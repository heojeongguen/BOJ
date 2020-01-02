#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int *A;
int *B;
int *P;
vector<int> vec[1001];
bool compare(int a, int b) {
	return a > b;
}
int main() {
	int count = 0;
	int N, data;
	cin >> N;
	A = new int[N];
	B = new int[N];
	P = new int[N];
	for (int i = 0; i < N; i++) {
		cin >> data;
		A[i] = data;
		vec[data].push_back(i);
		sort(vec[data].begin(), vec[data].end(),compare);
	}
	sort(A, A + N);

	for (int i = 0; i < N; i++) {
		P[vec[A[i]].back()] = count;
		vec[A[i]].pop_back();
		count++;
	}
	
	for(int i = 0; i < N; i++) {
		cout << P[i] << " ";
	}
}