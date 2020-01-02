#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

// 우선순위큐를 이용한 위상정렬 문제
// 기존 위상정렬 문제는 큐만 사용해도 가능하나, 
// 문제에 동일한 조건일때 작은숫자부터 문제를 풀으라고 했으니, 우선순위 큐를 이용해야 한다. 
int indegree[32001];
vector<int> vec[32001];
vector<int> vec;



int main() {
	// 우선순위 큐는 라이브러리 <queue>의 확장판이라고 보면 된다.
	// priority_queue< 변수형, 구조체, Compare > 변수명 ; 
	// push가 compare 함수에의해 정렬되면서 push된다.
	priority_queue< int , vector<int> , greater<int> > pq;

	int N, M, d1, d2;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> d1 >> d2;
		vec[d1].push_back(d2);
		// 위상정렬을 위한 indegree 증가
		indegree[d2]++;
	}
	for (int i = 1; i <= N; i++) {
		// 부모가없는 ( root 푸쉬 )
		if (!indegree[i]) pq.push(i);
	}

	while (!pq.empty()) {
		int now = pq.top(); pq.pop();
		cout << now << " ";
		for( const auto &x : vec[now] ) {
			// 현재 now(부모) 와 x(자식) 관의 관계를 --indegree로 끊고
			//  0이되면 push ( 위상정렬 )
			if (--indegree[x] == 0) {
				pq.push(x);
			}
		}
	}
	return 0;
}