#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
#define MAX_N 501

int dp[MAX_N][MAX_N];
int dp2[MAX_N][MAX_N];
int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N, Q;
     cin >> N >> Q;
     for (int i = 0; i <= N; i++) {
          for (int j = 0; j <= N; j++) {
               dp[i][j] = INF;
               dp2[i][j] = INF;
               if (i == j) {
                    dp[i][j] = 0;
                    dp2[i][j] = 0;
               }
          }
     }
     for (int i = 0; i < Q; i++) {
          int a, b; cin >> a >> b;
          dp[a][b] = 1;
          dp2[b][a] = 1;
     }

     for (int m = 1; m <= N; m++) {
          for (int s = 1; s <= N; s++) {
               for (int e = 1; e <= N; e++) {
                    if (dp[s][m] != INF && dp[m][e] != INF)
                         dp[s][e] = min(dp[s][e], dp[s][m] + dp[m][e]);
               }
          }
     }

     for (int m = 1; m <= N; m++) {
          for (int s = 1; s <= N; s++) {
               for (int e = 1; e <= N; e++) {
                    if (dp2[s][m] != INF && dp2[m][e] != INF)
                         dp2[s][e] = min(dp2[s][e], dp2[s][m] + dp2[m][e]);
               }
          }
     }



     int ans = 0;
     for (int i = 1; i <= N; i++) {
          int tmp_ans = 0;
          for (int j = 1; j <= N; j++) {
               if (j == i) continue;
               if (dp[i][j] == INF && dp2[i][j] == INF) tmp_ans++;
          }
          if (tmp_ans == 0) ans++;
     }
     cout << ans << "\n";
}