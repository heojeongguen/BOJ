#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define MAX_N 21
#define INF 1e9
int dp[MAX_N][MAX_N];
int dp2[MAX_N][MAX_N];

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N; cin >> N;
     for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
               int data; cin >> data;
               dp[i][j] = data; // 민호가 만든 최솟값
               dp2[i][j] = data; // 민호가 만든 최솟값으로 만들 수 있는 최솟값
          }
     }

     for (int m = 0; m < N; m++) {
          for (int s = 0; s < N; s++) {
               for (int e = 0; e < N; e++) {
                    if (s == m || e == m) continue; // s -> m -> e 인경우에 m는 s와 e와 달라야 유효한 비교가 된다.
                    if (dp[s][e] == dp[s][m] + dp[m][e]) { 
                         // 중간 지점을 거쳐갔을때와 바로 갔을 때 같다면
                         // 바로 가는 길을 없는길로 처리 해준다
                         dp2[s][e] = 0;
                    }
                    else if (dp[s][e] > dp[s][m] + dp[m][e]){
                         // 바로 가는길이 중간 지점을 거쳐오는 거보다 오래 걸리는 경우는
                         // 민호가 dp table을 잘못 만든 경우이다.
                         cout << -1 << "\n";
                         return 0;
                    }

               }
          }
     }
     int total = 0;
     // [i][j] = [j][i] 이므로 대각기준 오른쪽만 더해준다.
     for (int i = 0; i < N; i++) {
          for (int j = i + 1; j < N; j++) {
               total += dp2[i][j];
          }
     }
     cout << total << "\n";


}