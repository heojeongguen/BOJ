#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 1e9
#define MAX_N 101

int dp[MAX_N][MAX_N];

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, Q;
	cin >> N >> Q;
     for (int i = 0; i <= N; i++) {
          for (int j = 0; j <= N; j++) {
               dp[i][j] = INF;
               if (i == j) dp[i][j] = 0;
          }
     }
     for (int i = 0; i < Q; i++) {
          int a, b; cin >> a >> b;
          dp[a][b] = 1;
          dp[b][a] = 1;
	}

     for (int m = 1; m <= N; m++) {
          for (int s = 1; s <= N; s++) {
               for (int e = 1; e <= N; e++) {
                    if(dp[s][m] != INF && dp[m][e] != INF)
                         dp[s][e] = min(dp[s][e], dp[s][m] + dp[m][e]);
               }
          }
     }

     int ans = INF;
     int num = -1;
     for (int i = 1; i <= N; i++) {
          int tmp_ans = 0;
          for (int j = 1; j <= N; j++) {
               if (j == i) continue;
                   tmp_ans += dp[i][j];
          }
          if (tmp_ans < ans) {
               num = i;
               ans = tmp_ans;
          }
     }
     cout << num << "\n";
}