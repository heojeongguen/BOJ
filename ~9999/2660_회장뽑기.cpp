#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define MAX_N 51
#define INF 1e9
int dp[MAX_N][MAX_N];

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N,a,b; cin >> N;
     for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= N; j++) {
               if (i == j) dp[i][j] = 0;
               else dp[i][j] = INF;
          }
     }
     while (cin >> a >> b) {
          if (a == -1 && b == -1) break;
          dp[a][b] = 1;
          dp[b][a] = 1;
     }

     for (int m = 1; m <= N; m++) {
          for (int s = 1; s <= N; s++) {
               for (int e = 1; e <= N; e++) {
                    if (dp[s][m] != INF && dp[m][e] != INF) {
                         dp[s][e] = min(dp[s][e], dp[s][m] + dp[m][e]);
                    }
               }
          }
     }
     vector<int> ans;
     int mmin = 1e9;
     for (int i = 1; i <= N; i++) {
          int tmp_max = -1;
          for (int j = 1; j <= N; j++) {
               tmp_max = max(tmp_max, dp[i][j]);
          }
          if (mmin == 1e9) {
               mmin = tmp_max;
               ans.push_back(i);
          }
          else {
               if (mmin < tmp_max) continue;
               else if (mmin == tmp_max) ans.push_back(i);
               else {
                    ans.clear();
                    mmin = tmp_max;
                    ans.push_back(i);
               }
          }
     }
     cout << mmin << " " << ans.size() << "\n";
     for (const auto & x : ans) {
          cout << x << " ";
     }
     cout << "\n";
}