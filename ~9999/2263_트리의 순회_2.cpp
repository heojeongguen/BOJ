#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int post[100001];
int in[100001];
int arr[100001];
vector<int> L;
vector<int> R;

void fuc(int in_s, int in_e, int post_s, int post_e) {
	// start가 end를 역전할수 없다.
	if (in_s > in_e || post_s > post_e) return;

	// post_e : postOrder에서 범위안에있는 제일 오른쪽 index
	// root : 출력되는 값
	// p = position[root] : 현재 노드기준 자기보다 왼쪽에 있는( 자식들만 ) 값
	// p - in_s : (범위안에) 현재 노드기준 자기보다 왼쪽에 있는( 자식들만 ) 값
	int root = post[post_e];
	int p = arr[root];
	int left = p - in_s;
	cout << root << " ";

	// inorder기준) : 해당 인덱스 좌측
	// postOrder 기준) 해당범위 ~ 해당범위 + 왼쪽에있는 자식갯수
	fuc(in_s, p - 1, post_s, post_s + left - 1);

	// inorder기준) : 해당 인덱스 우측
	// postOrder 기준) 해당범위 + 왼쪽에있는 자식갯수 ~ 해당인덱스 끝 - 1
	fuc(p + 1, in_e, post_s + left, post_e - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int N,D;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> in[i];
		arr[in[i]] = i;
	}
	for (int i = 1; i <= N; i++) {
		cin >> post[i];
	}

	fuc(1,N,1,N);
	


}