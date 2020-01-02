#include <iostream>
using namespace std;
bool arr[41];
int main() {
     int ans = 0;
     for (int i = 0; i < 10; i++) {
          int n; cin >> n;
          int nn = n % 42;
          if (arr[nn] == false) {
               ans++;
               arr[nn] = true;
          }
     }
     cout << ans << endl;
}