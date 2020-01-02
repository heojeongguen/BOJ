#include <iostream>
#include <algorithm>
#include <limits.h>
#define INF INT_MAX

using namespace std;
int dp[401][401];
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int V, E;
     cin >> V >> E;

     for (int i = 1; i <= V; i++) {
          for (int j = 1; j <= V; j++) {

               dp[i][j] = INF;
          }
     }

     for (int i = 0; i < E; i++) {
          int a, b, c;
          cin >> a >> b >> c;
          dp[a][b] = min(dp[a][b], c);
     }


     for (int mid = 1; mid <= V; mid++) {
          for (int s = 1; s <= V; s++) {
               for (int e = 1; e <= V; e++) {
                    if (dp[s][mid] != INF && dp[mid][e] != INF) {
                         dp[s][e] = min(dp[s][e], dp[s][mid] + dp[mid][e]);
                    }
               }
          }
     }

     int ans = INF;

     for (int i = 1; i <= V; i++) {
          ans = min(ans, dp[i][i]);
     }

     if (ans == INF) cout << -1 << "\n";
     else cout << ans << "\n";
}