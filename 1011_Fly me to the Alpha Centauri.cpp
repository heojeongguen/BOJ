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
		dis = y - x; // 이동해야할 거리
		location = 0; // 현재위치
		day = 0; // 이동한 날짜
		cur = 0; // 현재속도
		while (true) {
			// 도착점과 출발점 양쪽에서 출발 해서 가운데서 만나는 형식
			// 0 에서 속도1로 -> 방향으로 이동
			// dis( 목적지 ) 에서 속도 1로  <- 방향으로 이동
			// 서로 가운데로 이동하다가, 다음 이동때 겹쳐지면 loop 탈출
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

		// loop 탈출 후 ) dis : B행성에서 출발자의 위치
		// loop 탈출 후 ) location : A행성에서 출발자의 위치
		// loop 탈출 후 ) cur : 최종이동속도 + 1
		// 남은거리 : dis - location
		// loop 탈출 후 ) 서로 만난경우
		if (dis == location) {
			ans = day;
		}
		else {
			// 최종이동속도 + 1  ==  남은 거리
			// 최종이동속도 + 1로 A또는 B가 이동하면된다.
			if (cur == dis - location) {
				ans = day + 1;
			}
			// 최종이동속도 + 1  >  남은 거리
	     	// 최종이동속도 + 1로 A또는 B가 이동
			// 그럼 남은 거리가 ( 남은거리 - cur ) 이된다.
			// 그 남은 거리는 둘중에 한명이 2일연속 어떤 속도로 이동했다고 가정하면 + 1 만 해주면됨.
			else if (cur > dis - location) {
				ans = day + 1;
			}
			// 같은 원리로 생각하면 + 2
			else if (cur < dis - location) {
				ans = day + 2;
			}
		}
		cout << ans << endl;
	}
}