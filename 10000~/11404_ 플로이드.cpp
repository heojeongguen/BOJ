#include <iostream>
#include <algorithm>
#include <limits.h>
#define INF LONG_MAX
using namespace std;
long long dp[101][101];
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int n, m;
     cin >> n >> m;

     for (int i = 0; i <= n; i++) {
          for (int j = 0; j <= n; j++) {
               dp[i][j] = INF;
          }
     }

     for (int i = 0; i < m; i++) {
          long long a, b, c;
          cin >> a >> b >> c;
          dp[a][b] = min(dp[a][b], c);
     }

     for (int mid = 1; mid <= n; mid++) {
          for (int s = 1; s <= n; s++) {
               for (int e = 1; e <= n; e++) {
                    if (dp[s][mid] != INF && dp[mid][e] != INF) {
                         dp[s][e] = min(dp[s][e], dp[s][mid] + dp[mid][e]);
                    }
               }
          }
     }

     for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
               if(i == j)  cout << 0 << " ";
               else if (dp[i][j] == INF)   cout << 0 << " ";
               else cout << dp[i][j] << " ";
          }
          cout << "\n";
     }
}