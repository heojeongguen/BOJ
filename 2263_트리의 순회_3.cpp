#include <iostream>

using namespace std;

int in[100001];
int post[100001];
int arr[100001];


void fuc(int in_s, int in_e, int post_s, int post_e) {
	if (in_s > in_e || post_s > post_e) return;

	int root = post[post_e];
	int left = arr[root];
	left = left - in_s;
	cout << root << " ";

	fuc(in_s, arr[root] - 1, post_s, post_s + left - 1);
	fuc(arr[root] + 1, in_e, post_s + left, post_e - 1);


}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> in[i];
		arr[in[i]] = i;
	}
	for (int j = 0; j < N; j++) {
		cin >> post[j];
	}
	fuc(0, N - 1, 0, N - 1);
}