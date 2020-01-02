#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>
typedef long long int ll;
using namespace std;


long long dp[100001][21];
ll arr[100001];
int N, K;

// 3차원 디피?
// dp[now][front]만 잇으면되나? zero는? 필요없네.

ll fuc(int now, int two, int five, int prevJump) {
     if (dp[now][prevJump] != -1) return dp[now][prevJump];

     ll nowTwo = 0;
     ll nowFive = 0;
     ll tmp = arr[now];
     while (true) {
          if (tmp % 2 == 0) {
               nowTwo++;
               tmp /= 2;
          }
          else {
               break;
          }
     }
     while (true) {
          if (tmp % 5 == 0) {
               nowFive++;
               tmp /= 5;
          }
          else {
               break;
          }
     }

     ll nextFive = five + nowFive;
     ll nextTwo = two + nowTwo;



     if (now == 1) {
          return min(nextFive, nextTwo);
     }

     dp[now][prevJump] = INT_MAX;

     for (int i = 1; i <= K; i++) {
          if (now - i >= 1)
               dp[now][prevJump] = min(dp[now][prevJump], fuc(now - i, nextTwo, nextFive, i));
     }

     return  dp[now][prevJump];
}



int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int T;
     cin >> T;
     while (T--) {
          memset(arr, 0, sizeof(arr));
          memset(dp, -1, sizeof(dp));

          cin >> N >> K;
          for (int i = 1; i <= N; i++) {
               cin >> arr[i];
          }
          ll ret = fuc(N, 0, 0, 1);
          cout << ret << "\n";
     }
}