#include <iostream>
#include <string>
#include <queue>
using namespace std;
int R, C;
// 입력 배열
int arr[1001][1001];
// 방문 배열
bool visit[1001][1001][2];
// 상,하,좌,우 BFS 이동 배열
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


class Info {
public:
     int r;
     int c;
     int cnt;
     int hit;
     Info(int r, int c, int cnt, int hit) {
          this->r = r;
          this->c = c;
          this->cnt = cnt;
          this->hit = hit;
     }
};

queue<Info> que;


// visit == true 의미 : 나보다 작거나 같은 cnt로 방문을 하였다
// visit[][][2] 3중배열을 이용하여 벽부순 횟수도 고려하여 BFS를 하였다.
// r == R && c == C : 도착점에 같은 cnt가 리턴되는 r,c가 que에남아 있을 수 있지만 그 이하는 존재할 수 없다.
int BFS() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     while (!que.empty()) {
          int r = que.front().r;
          int c = que.front().c;
          int cnt = que.front().cnt;
          int hit = que.front().hit;
          que.pop();
          if (r == R && c == C) {
               return cnt;
          }
          for (int i = 0; i < 4; i++) {
               int nextR = r + dx[i];
               int nextC = c + dy[i];

               if (nextR >= 1 && nextR <= R && nextC >= 1 && nextC <= C) {
                    if (arr[nextR][nextC] == 1 && hit == 0)
                    {
                         visit[nextR][nextC][hit + 1] = true;
                         que.push(Info(nextR,nextC,cnt+1,hit+1));
                    }
                    else if (arr[nextR][nextC] == 0 && visit[nextR][nextC][hit] == false)
                    {
                         visit[nextR][nextC][hit] = true;
                         que.push(Info(nextR,nextC,cnt+1,hit));
                    }
               }
          }
     }
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     cin >> R >> C;
     string str;
     for (int i = 1; i <= R; i++) {
          cin >> str;
          for (int j = 1; j <= C; j++) {
               arr[i][j] = (int)str[j-1] - '0';
          }
     }
     que.push(Info(1, 1, 1, 0));
     visit[1][1][0] = true;
     int ret = BFS();
     if (visit[R][C][0] == false && visit[R][C][1] == false) {
          cout << -1 << endl;
     }
     else {
          cout << ret << endl;
     }
     return 0;
}