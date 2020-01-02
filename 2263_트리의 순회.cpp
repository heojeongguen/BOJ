#include <iostream>

using namespace std;
int n;

// 중위순회
int inO[100001];
// 후위 순회
int postO[1000001];
// 중위순회에서 추가된 순서를 저장하는 배열
int position[100001];

// in_s : inorder의 start index
// in_e : inorder의 end index
// post_s : postOrder의 start index
// post_e : postOrder의 end index
void fuc(int in_s,int in_e,int post_s, int post_e) {
	// start가 end를 역전할수 없다.
	if (in_s > in_e || post_s > post_e) return;

	// post_e : postOrder에서 범위안에있는 제일 오른쪽 index
	// root : 출력되는 값
	// p = position[root] : 현재 노드기준 자기보다 왼쪽에 있는( 자식들만 ) 값
	// p - in_s : (범위안에) 현재 노드기준 자기보다 왼쪽에 있는( 자식들만 ) 값
	int root = postO[post_e];
	int p = position[root];
	int left = p - in_s;
	cout << root << " ";
	
	// inorder기준) : 해당 인덱스 좌측
	// postOrder 기준) 해당범위 ~ 해당범위 + 왼쪽에있는 자식갯수
	fuc(in_s, p - 1, post_s, post_s + left - 1);

	// inorder기준) : 해당 인덱스 우측
	// postOrder 기준) 해당범위 + 왼쪽에있는 자식갯수 ~ 해당인덱스 끝 - 1
	fuc(p + 1, in_e, post_s + left, post_e  - 1);
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> inO[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> postO[i];
	}
	for (int i = 0; i < n; i++) {
		position[inO[i]] = i;
	}
	// 처음부터 끝까지 탐색
	fuc(0, n - 1, 0, n - 1);
}