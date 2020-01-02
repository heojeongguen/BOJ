#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define MAX_J 1000000
char arr[MAX_J + 1];

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int J; cin >> J;
     int A; cin >> A;
     for (int i = 1; i <= J; i++) {
          cin >> arr[i];
     }
     int ans = 0;
     for (int i = 0; i < A; i++) {
          char tag; int num;
          cin >> tag >> num;
          if (arr[num] == 'S') {
               if (tag == 'S') {
                    arr[num] = 'X';
                    ans++;
               }
          }
          else if (arr[num] == 'M') {
               if ( tag == 'M' || tag == 'S') {
                    arr[num] = 'X';
                    ans++;
               }
          }
          else if (arr[num] == 'L') {
               if (tag == 'L' || tag == 'M' || tag == 'S') {
                    arr[num] = 'X';
                    ans++;
               }
          }
     }
     cout << ans << "\n";
}