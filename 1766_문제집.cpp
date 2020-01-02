#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// �켱����ť�� �̿��� �������� ����
// ���� �������� ������ ť�� ����ص� �����ϳ�, 
// ������ ������ �����϶� �������ں��� ������ Ǯ����� ������, �켱���� ť�� �̿��ؾ� �Ѵ�. 
int indegree[32001];
vector<int> vec[32001];
vector<int> vec;



int main() {
	// �켱���� ť�� ���̺귯�� <queue>�� Ȯ�����̶�� ���� �ȴ�.
	// priority_queue< ������, ����ü, Compare > ������ ; 
	// push�� compare �Լ������� ���ĵǸ鼭 push�ȴ�.
	priority_queue< int , vector<int> , greater<int> > pq;

	int N, M, d1, d2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> d1 >> d2;
		vec[d1].push_back(d2);
		// ���������� ���� indegree ����
		indegree[d2]++;
	}
	for (int i = 1; i <= N; i++) {
		// �θ𰡾��� ( root Ǫ�� )
		if (!indegree[i]) pq.push(i);
	}

	while (!pq.empty()) {
		int now = pq.top(); pq.pop();
		cout << now << " ";
		for( const auto &x : vec[now] ) {
			// ���� now(�θ�) �� x(�ڽ�) ���� ���踦 --indegree�� ����
			//  0�̵Ǹ� push ( �������� )
			if (--indegree[x] == 0) {
				pq.push(x);
			}
		}
	}
	return 0;
}