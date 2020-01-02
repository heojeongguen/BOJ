#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int,int>> vec;
int dp[101];

int main() {
     int N;
     cin >> N;
     for (int i = 1; i <= N; i++) {
          int a, b;
          cin >> a >> b;
          vec.push_back({ a,b });
     }
     sort(vec.begin(), vec.end());
     for (int i = 0; i < N; i++) {
          int tmp = 0;
          for (int j = 0; j <= i; j++) {
               if (vec[j].second <= vec[i].second) {
                    tmp = max(tmp, dp[j] + 1);
               }
          }
          dp[i] = tmp;
     }
     cout << N - *max_element(dp, dp + N) << endl;
}