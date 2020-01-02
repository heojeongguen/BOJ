#include <iostream>

using namespace std;
int n;

// ������ȸ
int inO[100001];
// ���� ��ȸ
int postO[1000001];
// ������ȸ���� �߰��� ������ �����ϴ� �迭
int position[100001];

// in_s : inorder�� start index
// in_e : inorder�� end index
// post_s : postOrder�� start index
// post_e : postOrder�� end index
void fuc(int in_s,int in_e,int post_s, int post_e) {
	// start�� end�� �����Ҽ� ����.
	if (in_s > in_e || post_s > post_e) return;

	// post_e : postOrder���� �����ȿ��ִ� ���� ������ index
	// root : ��µǴ� ��
	// p = position[root] : ���� ������ �ڱ⺸�� ���ʿ� �ִ�( �ڽĵ鸸 ) ��
	// p - in_s : (�����ȿ�) ���� ������ �ڱ⺸�� ���ʿ� �ִ�( �ڽĵ鸸 ) ��
	int root = postO[post_e];
	int p = position[root];
	int left = p - in_s;
	cout << root << " ";
	
	// inorder����) : �ش� �ε��� ����
	// postOrder ����) �ش���� ~ �ش���� + ���ʿ��ִ� �ڽİ���
	fuc(in_s, p - 1, post_s, post_s + left - 1);

	// inorder����) : �ش� �ε��� ����
	// postOrder ����) �ش���� + ���ʿ��ִ� �ڽİ��� ~ �ش��ε��� �� - 1
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
	// ó������ ������ Ž��
	fuc(0, n - 1, 0, n - 1);
}