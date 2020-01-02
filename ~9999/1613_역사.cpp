#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
#define MAX_N 401

int dp[MAX_N][MAX_N];
int dp2[MAX_N][MAX_N];
int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N, Q;
     cin >> N >> Q;
     for (int i = 0; i <= N; i++) {
          for (int j = 0; j <= N; j++) {
               dp[i][j] = INF;
               if (i == j) {
                    dp[i][j] = 0;
               }
          }
     }
     for (int i = 0; i < Q; i++) {
          int a, b; cin >> a >> b;
          dp[a][b] = 1;
     }

     for (int m = 1; m <= N; m++) {
          for (int s = 1; s <= N; s++) {
               for (int e = 1; e <= N; e++) {
                    if (dp[s][m] != INF && dp[m][e] != INF)
                         dp[s][e] = min(dp[s][e], dp[s][m] + dp[m][e]);
               }
          }
     }

     int M; cin >> M;
     for (int i = 0; i < M; i++) {
          int a, b; cin >> a >> b;
          if (dp[a][b] == INF && dp[b][a] == INF) cout << 0 << "\n";
          else if( dp[a][b] == INF) cout << 1<< "\n";
          else cout << -1 << '\n';
     }

}