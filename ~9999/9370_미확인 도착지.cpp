#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

int dp[2001][2001];
// vector<int> vec[2001]; pq 다익스트라
vector<int> candidate;
vector<int> ans;
int n, m, t;

void fuc(int start) {
     for (int mid = 1; mid <= n; mid++) {
          for (int end = 1; end <= n; end++) {
               if (dp[start][mid] != INT_MAX && dp[mid][end] != INT_MAX) {
                   dp[start][end] = min(dp[start][end], dp[start][mid] + dp[mid][end]);
               }
          }
     }
}
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int testCase;

     cin >> testCase;
     for (int test = 1; test <= testCase; test++) {
          ans.clear();
          candidate.clear();
          cin >> n >> m >> t;
          for (int i = 1; i <= n; i++) {
               for (int j = 1; j <= n; j++) {
                    if (i == j) dp[i][j] = 0;
                    else dp[i][j] = INT_MAX;
               }
          }
          int s, g, h;
          cin >> s >> g >> h;
          for (int i = 0; i < m; i++) {
               int a, b, d;
               cin >> a >> b >> d;
               dp[a][b] = dp[b][a] = min(dp[a][b], d);
          }
          for (int i = 0; i < t; i++) {
               int tmp; cin >> tmp;
               candidate.push_back(tmp);
          }
        
          fuc(s);
          fuc(g);
          fuc(h);
          /*for (int i = 1; i <= n; i++) {
               for (int j = 1; j <= n; j++) {
                    cout << dp[i][j] << " ";
               }
               cout << endl;
          }*/
          for (int i = 0; i < candidate.size(); i++) {
               int e = candidate[i];
               bool check = false;
               if (dp[s][g] != INT_MAX && dp[g][h] != INT_MAX && dp[h][e] != INT_MAX) {
                    if (dp[s][g] + dp[g][h] + dp[h][e] == dp[s][e]) {
                         ans.push_back(e); 
                         check = true;
                    }
               }
               if (!check) {
                    if (dp[s][h] != INT_MAX && dp[h][g] != INT_MAX && dp[g][e] != INT_MAX) {
                         if (dp[s][h] + dp[h][g] + dp[g][e] == dp[s][e]) {
                              ans.push_back(e);
                         }
                    }
               }
          }

          sort(ans.begin(), ans.end());
          for (const auto & x : ans) {
               cout << x << " ";
          }
          cout << "\n";
     }
}