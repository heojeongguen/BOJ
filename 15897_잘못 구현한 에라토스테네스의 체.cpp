#include <iostream>
using namespace std;

int main() {
          int ans = 0;
          int N;
          cin >> N;
          if (N % 2 == 0) {
               int n = N / 2;
               ans = 3 + (n + 4)*(n + 5) / 2 - (5 * 6) / 2;
          }
          else {
               int n = N / 2;

               ans = 1 + (n - 1)*(2 * 5 + (n - 2) * 2) / 2;
          }
          cout << ans << "\n";
     return 0;
}