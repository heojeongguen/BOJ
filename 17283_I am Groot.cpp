#include <iostream>

using namespace std;

int main() {
     int L;
     double R;
     int cnt = 2;
     int ans = 0;
     cin >> L >> R;
     while (true) {
          L = L * (R / 100);
          if (L <= 5) break;
          ans += cnt * L;
          cnt *= 2;
     }
     cout << ans << "\n";
     return 0;
}