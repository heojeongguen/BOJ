#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <numeric>
using namespace std;
#define INF INT_MAX
class Info {
public:
     int end;
     int cost;
     int dis;
     Info(int end, int cost, int dis) {
          this->end = end;
          this->cost = cost;
          this->dis = dis;
     }
};
vector<Info> vec[101];
int dist[101][10001];
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int TC; cin >> TC;
     for (int tc = 1; tc <= TC; tc++) {
          int N, M, K;
          cin >> N >> M >> K;

          for (int i = 0; i <= N; i++) {
               vec[i].clear();
               for (int j = 0; j <= M; j++) {
                    if (i == 1)  dist[i][j] = 0;
                    else dist[i][j] = INF;
               }
          }

          for (int i = 0; i < K; i++) {
               int u, v, c, d;
               cin >> u >> v >> c >> d;
               vec[u].push_back(Info(v,c,d));
          }
          
          for (int i = 1; i <= N-1; i++) {
               for (int j = 1; j <= N; j++) {
                    for (const auto & x : vec[j]) {
                         int next = x.end, cost = x.cost, dis = x.dis;
                         for (int m = 0; m <= M; m++) {
                              if (m + cost > M) break;
                              if (dist[j][m] != INF && m + cost <= M && dist[next][m + cost] > dist[j][m] + dis ) {
                                   dist[next][m + cost] = dist[j][m] + dis;
                              }
                         }
                    }
               }
          }

          int ans = *min_element(dist[N], dist[N] + M + 1);
          if(ans == INF) cout << "Poor KCM" << "\n";
          else cout << ans << "\n";
     }
}