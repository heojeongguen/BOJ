#include <iostream>
#include <algorithm>
using namespace std;
int arr[200001];
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, C;
     cin >> N >> C;
     for (int i = 0; i < N; i++) {
        cin >> arr[i];
     }
     sort(arr, arr+ N);
     int MAX = arr[N - 1] - arr[0];
     int MIN = 1;
     int ans = 0;
     while (MIN <= MAX) {
          int MID = (MIN + MAX) / 2;
          int cnt = 1;
          int s = arr[0];
          int distance;
          for (int i = 1; i < N; i++) {
               distance = arr[i] - s;
               if (MID <= distance) {
                    cnt++;
                    s = arr[i];
               }
          }
          if (cnt >= C) {
               MIN = MID + 1;
               ans = MID;
          }
          else {
               MAX = MID - 1;
          }
     }
     cout << ans << "\n";
}