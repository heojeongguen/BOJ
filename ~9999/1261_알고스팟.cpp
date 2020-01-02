#include <iostream>
#include <queue>
#include <algorithm>
#include <limits.h>
#include <string>
#define INF INT_MAX
using namespace std;
char arr[101][101];
bool visit[101][101];
pair<int,int> dxdy[4] = { {1,0},{-1,0},{0,1},{0,-1} };
class Info {
public:
     int r, c, cost;
     Info(int r, int c, int cost) {
          this->r = r;
          this->c = c;
          this->cost = cost;
     }
     bool operator > (const Info & b) const {
          return this->cost > b.cost;
     }
};
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int C, R;
     cin >> C >> R;
     for (int i = 0; i < R; i++) {
          string str;
          cin >> str;
          for (int j = 0; j < C; j++) {
               arr[i][j] = str[j];
          }
     }
     priority_queue<Info, vector<Info>, greater<Info> > pq;
     int ans = 0;
     pq.push(Info(0, 0, 0));
     while (!pq.empty()) {
          Info top = pq.top(); pq.pop();
          int r = top.r;
          int c = top.c;
          int cost = top.cost;
          if (r == R - 1 && c == C - 1) {
               ans = cost;
               break;
          }
          for (int i = 0; i < 4; i++) {
               int nextR = r + dxdy[i].first;
               int nextC = c + dxdy[i].second;

               if (nextR < 0 || nextR >= R || nextC < 0 || nextC >= C)continue;
               if (visit[nextR][nextC]) continue;

               if (arr[nextR][nextC] == '1') {
                    pq.push(Info(nextR, nextC, cost + 1));
               }
               else {
                    pq.push(Info(nextR, nextC, cost));
               }
               visit[nextR][nextC] = true;
          }
         
     }
     cout << ans << "\n";
}