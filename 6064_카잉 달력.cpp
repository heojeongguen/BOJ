#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	ios_base :: sync_with_stdio(false);
 cin.tie(NULL);
 cout.tie(NULL);
	int T, M, N,X,Y,x=1,y=1,count=1,ans;
	int jump;
	cin >> T;
	while (T--) {
		cin >> M >> N >> X >> Y;
		x = 1;
		y = 1;
		ans = 1;
		while (x != X) {
			x++;
			y++;
			y = max(1, y % (N + 1));
			ans++;
		}
		while(y != Y){
			if (M * N < ans) {
				ans = -1;
				break;
			}
			count = M;
			if (count + y < N) {
				y = count + y;
			}
			else if (count + y == N) {
				y += count;
				while (y > N) {
					y -= N;
				}
			}
			else if (count + y > N) {
				y += count;
				while (y > N) {
					y -= N;
				}
			}
			ans += count;

		}
		cout << ans << endl;
	}
}