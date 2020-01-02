#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

long long arr[10001];
long long mmin = -1;
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     long long K, N;
     long long MIN = 1;
     long long MAX = INT_MAX;
     long long ans = 0;

     cin >> K >> N;
     for (long long i = 0; i < K; i++) {
          cin >> arr[i];
     }
 
     while (MIN <= MAX) {
          long long MID = (MIN + MAX) / 2;
          long long tmp = 0;
          
          for (long long i = 0; i < K; i++) {
               tmp += arr[i] / MID;
          }

          if (tmp >= N) {
               ans = max(ans, MID);
               MIN = MID + 1;
          }
          else {
               MAX = MID - 1;
          }
     }
     cout << ans << "\n";
}