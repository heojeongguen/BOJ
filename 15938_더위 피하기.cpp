#include <iostream>
#include <algorithm>
#include <queue>
int DIV = 1e9 + 7;
using namespace std;
int xx, yy, T;
long long dp[401][401][202];
bool visit[401][401][202], arr[401][401];
pair<int, int> dxdy[4] = { {1,0},{-1,0},{0,1},{0,-1} };
class Info {
public:
     int x;
     int y;
     int t;
     Info(int x, int y, int t) {
          this->x = x;
          this->y = y;
          this->t = t;
     }
};

queue<Info> que;
long long BFS() {
     dp[200][200][0] = 1;
     que.push(Info(200, 200, 0));
     int x, y, t, nx, ny;
     while (!que.empty()) {
          x = que.front().x;
          y = que.front().y;
          t = que.front().t;
          que.pop();
          for (int i = 0; i < 4; i++) {
               nx = x + dxdy[i].first;
               ny = y + dxdy[i].second;
               if (nx < 0 || nx > 400 || ny < 0 || ny > 400 || t > T) continue;
               if (arr[nx][ny] == true) continue;
               dp[nx][ny][t + 1] += dp[x][y][t];
               dp[nx][ny][t + 1] %= DIV;
               if (!(nx == xx && ny == yy)) {
                    if (!visit[nx][ny][t + 1]) {
                         visit[nx][ny][t + 1] = true;
                         que.push(Info(nx, ny, t + 1));
                    }
               }

          }
     }
     long long ans = 0;
     for (int i = 0; i <= T; i++) {
          ans = (ans + dp[xx][yy][i]) % DIV;
     }
     return ans;
}



int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int x, y;
     int N;

     cin >> x >> y;
     cin >> T;
     cin >> xx >> yy;
     int x_gap = 200 - x;
     int y_gap = 200 - y;
     xx += x_gap;
     yy += y_gap;
     cin >> N;

     if (xx < 0 || xx > 400 || yy < 0 || yy > 400) {
          cout << 0 << "\n";
     }
     else {
          for (int i = 0; i < N; i++) {
               int xi, yi; cin >> xi >> yi;
               xi += x_gap;
               yi += y_gap;
               if (xi < 0 || xi > 400 || yi < 0 || yi > 400) continue;
               else arr[xi][yi] = true;
          }
          cout << BFS() << "\n";
     }
     return 0;
}