#include <iostream>
#include <vector>
// ��¥ 100% �������� ����
// ������ ��������� Ǯ �� ����
using namespace std;
vector<int> vec;

// ��ǻ�Ͱ������� ��� xx
// A[0] = 0 �϶�, 1�϶�, 2�ϋ� ..... �ϴٺ��� ������ ������ ������ ������ ���� �� �ִ�.
int main() {
	int N, data;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> data;
		if (data == 4) {
			cout << 2 << endl;
		}
		else if (data == 1 || data == 2 || data == 3 || data == 6 ) {
			cout << 0 << endl;
		}else{
			cout << 1 << endl;
		}
	}
}