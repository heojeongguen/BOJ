#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	unsigned long long x, y, dis, location, day, cur, ans;
	vector<unsigned long long> ansVec;
	int N;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		dis = y - x; // �̵��ؾ��� �Ÿ�
		location = 0; // ������ġ
		day = 0; // �̵��� ��¥
		cur = 0; // ����ӵ�
		while (true) {
			// �������� ����� ���ʿ��� ��� �ؼ� ����� ������ ����
			// 0 ���� �ӵ�1�� -> �������� �̵�
			// dis( ������ ) ���� �ӵ� 1��  <- �������� �̵�
			// ���� ����� �̵��ϴٰ�, ���� �̵��� �������� loop Ż��
			if (dis - (cur + 1) < location + (cur + 1)) {
				cur++;
				break;
			}
			else {
				cur++;
				dis = dis - cur;
				location = location + cur;
				day += 2;
			}
		}

		// loop Ż�� �� ) dis : B�༺���� ������� ��ġ
		// loop Ż�� �� ) location : A�༺���� ������� ��ġ
		// loop Ż�� �� ) cur : �����̵��ӵ� + 1
		// �����Ÿ� : dis - location
		// loop Ż�� �� ) ���� �������
		if (dis == location) {
			ans = day;
		}
		else {
			// �����̵��ӵ� + 1  ==  ���� �Ÿ�
			// �����̵��ӵ� + 1�� A�Ǵ� B�� �̵��ϸ�ȴ�.
			if (cur == dis - location) {
				ans = day + 1;
			}
			// �����̵��ӵ� + 1  >  ���� �Ÿ�
	     	// �����̵��ӵ� + 1�� A�Ǵ� B�� �̵�
			// �׷� ���� �Ÿ��� ( �����Ÿ� - cur ) �̵ȴ�.
			// �� ���� �Ÿ��� ���߿� �Ѹ��� 2�Ͽ��� � �ӵ��� �̵��ߴٰ� �����ϸ� + 1 �� ���ָ��.
			else if (cur > dis - location) {
				ans = day + 1;
			}
			// ���� ������ �����ϸ� + 2
			else if (cur < dis - location) {
				ans = day + 2;
			}
		}
		cout << ans << endl;
	}
}