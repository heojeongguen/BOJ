#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>

using namespace std;
const int MAX_N = 8e2;
int dp[MAX_N + 1][MAX_N + 1];
int main() {
     int N, E;
     cin >> N >> E;
     fill(&dp[0][0], &dp[MAX_N][MAX_N + 1], INT_MAX);


     for (long long i = 0; i < E; i++) {
          int a, b, c;
          cin >> a >> b >> c;
          dp[a][b] = dp[b][a] = c;
     }

     for (int i = 1; i <= N; i++)
          for (int j = 1; j <= N; j++)
               for (int k = 1; k <= N; k++) {
                    if (dp[j][i] != INT_MAX && dp[i][k] != INT_MAX) {
                         if (dp[j][k] == INT_MAX) {
                              dp[j][k] = dp[j][i] + dp[i][k];
                         }
                         else {
                              dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
                         }
                    }
               }

     int a, b;
     int ans = INT_MAX;
     cin >> a >> b;
     dp[a][a] = dp[b][b] = 0;

     if (dp[1][a] != INT_MAX && dp[a][b] != INT_MAX && dp[b][N] != INT_MAX) {
          ans = min(ans, dp[1][a] + dp[a][b] + dp[b][N]);
     }

     if (dp[1][b] != INT_MAX && dp[b][a] != INT_MAX && dp[a][N] != INT_MAX) {
          ans = min(ans, dp[1][b] + dp[b][a] + dp[a][N]);
     }

     if (ans == INT_MAX) {
          cout << -1 << endl;
     }
     else {
          cout << ans << endl;
     }
     return 0;
}