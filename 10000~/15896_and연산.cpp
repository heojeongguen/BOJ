#include <iostream>
#include <vector>
using namespace std;

vector<int> B;

int bit[31];
int ansBit[31];

int main() {
     int N;
     cin >> N;
     int ans1 = 0;
     for (int i = 0; i < N; i++) {
          int x; cin >> x;
          int loc = 0;
          while (x > 0) {
               if (x % 2 == 1) {
                    bit[loc]++;
               }
               x /= 2;
               loc++;
          }
     }

     int tmp = 1;
     int A_result = 0;
     for (int i = 0; i < 30; i++) {
          if (bit[i] == N) {
               A_result += tmp;
          }
          tmp *= 2;
     }
     int ans2 = -1;
     for (int i = 0; i < N; i++) {
          int loc = 0;
          int x; cin >> x;
          int B_result = A_result + x;
          if (ans2 == -1) {
               ans2 = B_result;
          }
          else {
               ans2 = ans2 & B_result;
          }

          while (x > 0) {
               if (x % 2 == 1) {
                    ansBit[loc] += bit[loc];
               }
               x /= 2;
               loc++;
          }
     }


     tmp = 1;
     for (int i = 0; i < 30; i++) {
          ans1 += (tmp * ansBit[i]) % 1999;
          tmp *= 2;
     }

     cout <<  ans1 << " " << ans2 << "\n";
     
}