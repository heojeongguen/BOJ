#include <iostream>

using namespace std;

int main() {
     int A, B, V, ans = 0;
     cin >> A >> B >> V;
     int AA, BB, CC;
     int A_B = A - B;
     int remain = V % A_B;


     if (V - A_B - B + A >= V) {
          ans++;
          V -= A;
          ans += V / A_B;
          V %= A_B;
          if (V != 0) ans++;
     }
     cout << ans << endl;

     

}