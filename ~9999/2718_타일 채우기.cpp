#include <iostream>
#include <cstring>
using namespace std;

int dp[501][16];
int N;

int fun(int n, int nowState) {
     if (n == 0) {
          return 1;
     }
     if (dp[n][nowState] != -1) return dp[n][nowState];
     int ret = 0;
     if (nowState == 0) {
          ret += fun(n-1, 0);
          ret += fun(n-1, 5);
          ret += fun(n-1, 8);
          ret += fun(n-1, 10);
          ret += fun(n-1, 15);

     }else  if (nowState == 1) {
          ret += fun(n-1, 14);
          ret += fun(n-1, 4);
          ret += fun(n-1, 2);
     }
     else  if (nowState == 2) {
          ret += fun(n-1, 1);
          ret += fun(n-1, 13);
     }
     else  if (nowState == 3) {
          ret += fun(n-1, 4);
          ret += fun(n-1, 12);
     }
     else  if (nowState == 4) {
          ret += fun(n-1, 5);
          ret += fun(n-1, 8);
          ret += fun(n-1, 11);
     }
     else  if (nowState == 5) {
          ret += fun(n-1, 0);
          ret += fun(n-1, 10);
     }
     else  if (nowState == 6) {
          ret += fun(n-1, 9);
     }
     else  if (nowState == 7) {
          ret += fun(n-1, 0);
          ret += fun(n-1, 8);
     }
     else  if (nowState == 8) {
          ret += fun(n-1, 7);
     }
     else  if (nowState == 9) {
          ret += fun(n-1, 6);
     }
     else  if (nowState == 10) {
          ret += fun(n-1, 0);
          ret += fun(n-1, 5);
     }
     else  if (nowState == 11) {
          ret += fun(n-1, 4);
     }
     else  if (nowState == 12) {
          ret += fun(n-1, 3);
     }
     else  if (nowState == 13) {
          ret += fun(n-1, 2);
     }
     else  if (nowState == 14) {
          ret += fun(n-1, 1);
     }
     else  if (nowState == 15) {
          ret += fun(n-1, 0);
     }
     dp[n][nowState] = ret;
     //cout << n << " , " << nowState << " : " <<  ret << endl;
     return dp[n][nowState];
}

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     memset(dp, -1, sizeof(dp));
     int t; cin >> t;
     while (t--) {
          cin >> N;
          cout << fun(N, 0) << endl;
     }
     return 0;
}