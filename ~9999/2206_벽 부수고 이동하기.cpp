#include <iostream>
#include <string>
#include <queue>
using namespace std;
int R, C;
// �Է� �迭
int arr[1001][1001];
// �湮 �迭
bool visit[1001][1001][2];
// ��,��,��,�� BFS �̵� �迭
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


// visit == true �ǹ� : ������ �۰ų� ���� cnt�� �湮�� �Ͽ���
// visit[][][2] 3�߹迭�� �̿��Ͽ� ���μ� Ƚ���� ����Ͽ� BFS�� �Ͽ���.
// r == R && c == C : �������� ���� cnt�� ���ϵǴ� r,c�� que������ ���� �� ������ �� ���ϴ� ������ �� ����.
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