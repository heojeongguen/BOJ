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

     // V-1 + 1( ���ǻ���Ŭ �Ǵ� ) = V�� �ݺ�
     for (int i = 1; i <= N; i++) { // (N-1) ������ �ִܰŸ� ��� ,N��°�� ���ǻ���Ŭ ���� �Ǵ�
          // ��� �������� �����ؼ�
          for (int j = 1; j <= N; j++) {
               // ��� ���������� ������ ���ؼ�
               for (const auto & x : vec[j]) {
                    int next = x.first, d = x.second;
                    if (dist[j] != INF && dist[next] > dist[j] + d) {
                         dist[next] = dist[j] + d;
                         // i == N�϶� ��ȭ�� ����� -> ���ǻ���Ŭ������ �������� ���ŵȴ�
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