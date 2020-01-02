#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <queue>
#include <limits.h>
#define INF INT_MAX
using namespace std;
int r, c;
int visit[11][11];
int arr[11][11];
bool row[11];
bool col[11];
pair<int, int> dxdy[4] = { {1,0},{-1,0},{0,1},{0,-1} };
queue<pair<int, int> > que;
int ans = INF;
void BFS() {
     que.push({ r,c });
     visit[r][c] = 0;

     while (!que.empty()) {
          int R = que.front().first;
          int C = que.front().second;
          que.pop();
          if (row[R] == false && col[C] == false) {
               ans = min(ans, visit[R][C]);
               continue;
          }

          for (int i = 0; i < 4; i++) {
               int nR = R + dxdy[i].first;
               int nC = C + dxdy[i].second;
               if (nR <= 0 || nR > 10 || nC <= 0 || nC > 10) continue;
               if (visit[nR][nC] != -1 || arr[nR][nC] == -1) continue;

               visit[nR][nC] = visit[R][C] + 1;
               que.push({ nR,nC });
             
          }
     }
}


int main() {
     cin >> r >> c;
     for (int i = 1; i <= 10; i++) {
          string str;
          cin >> str;
          for (int j = 0; j < 10; j++) {
               if (str[j] == 'o') {
                    row[i] = true;
                    col[j+1] = true;
                    arr[i][j + 1] = -1;
               }
          }
     }
     memset(visit, -1, sizeof(visit));
     BFS();
     cout << ans << endl;
}