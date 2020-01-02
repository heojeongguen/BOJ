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
	// start�� end�� �����Ҽ� ����.
	if (in_s > in_e || post_s > post_e) return;

	// post_e : postOrder���� �����ȿ��ִ� ���� ������ index
	// root : ��µǴ� ��
	// p = position[root] : ���� ������ �ڱ⺸�� ���ʿ� �ִ�( �ڽĵ鸸 ) ��
	// p - in_s : (�����ȿ�) ���� ������ �ڱ⺸�� ���ʿ� �ִ�( �ڽĵ鸸 ) ��
	int root = post[post_e];
	int p = arr[root];
	int left = p - in_s;
	cout << root << " ";

	// inorder����) : �ش� �ε��� ����
	// postOrder ����) �ش���� ~ �ش���� + ���ʿ��ִ� �ڽİ���
	fuc(in_s, p - 1, post_s, post_s + left - 1);

	// inorder����) : �ش� �ε��� ����
	// postOrder ����) �ش���� + ���ʿ��ִ� �ڽİ��� ~ �ش��ε��� �� - 1
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