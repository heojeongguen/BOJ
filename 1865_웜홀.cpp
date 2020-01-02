#include <iostream>
#include <vector>
#include <limits.h>
#define INF INT_MAX
using namespace std;

int dist[501];
vector<pair<int,int>> vec[501];
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int TC; cin >> TC;
     for (int tc = 1; tc <= TC; tc++) {
          int N, M, W;
          cin >> N >> M >> W;

          for (int i = 0; i <= N; i++) {
               dist[i] = INF;
               vec[i].clear();
          }

          for (int i = 0; i < M; i++) {
               int S, E, T;
               cin >> S >> E >> T;
               vec[S].push_back({ E,T });
               vec[E].push_back({ S,T });

          }

          for (int i = 0; i < W; i++) {
               int S, E, T;
               cin >> S >> E >> T;
               vec[S].push_back({ E,T *-1});
          }
          bool cycle = false;
          dist[1] = 0;
          for (int v = 1; v <= N; v++) {
               for (int w = 1; w <= N; w++) {
                    for (const auto & x : vec[w]) {
                         int next = x.first;
                         int d = x.second;
                         if (dist[w] != INF && dist[next] > dist[w] + d) {
                              dist[next] = dist[w] + d;
                              if (v == N) {
                                   cycle = true;
                                   break;
                              }
                         }
                    }
                    if (cycle) break;
               }
               if (cycle) break;
          }
          if (cycle) cout << "YES" << "\n";
          else cout << "NO" << "\n";
     }
}