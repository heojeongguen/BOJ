#include <iostream>
#include <vector>
#include <limits.h>
#define INF INT_MAX
using namespace std;
vector<pair<int,int>> vec[502];
int dist[502];
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, M;
     cin >> N >> M;

     fill(dist, dist + N + 1, INF);

     for (int i = 0; i < M; i++) {
          int A, B, C;
          cin >> A >> B >> C;
          vec[A].push_back({ B,C });
     }

     dist[1] = 0;
     bool cycle = false;

     // V-1 + 1( 음의사이클 판단 ) = V번 반복
     for (int i = 1; i <= N; i++) { // (N-1) 까지는 최단거리 계산 ,N번째는 음의사이클 여부 판단
          // 모든 시작정점 에대해서
          for (int j = 1; j <= N; j++) {
               // 모든 시작정점의 간선에 대해서
               for (const auto & x : vec[j]) {
                    int next = x.first, d = x.second;
                    if (dist[j] != INF && dist[next] > dist[j] + d) {
                         dist[next] = dist[j] + d;
                         // i == N일때 변화가 생겼다 -> 음의사이클로인해 무한으로 갱신된다
                         if (i == N) cycle = true;
                    }
               }
          }
     }
     if (cycle) cout << -1 << "\n";
     else {
          for (int i = 2; i <= N; i++) {
               if (dist[i] == INF) cout << -1 << "\n";
               else cout << dist[i] << "\n";
          }
     }


}