#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

int arr[100][3];
int s_arr[100];
int b_arr[100];
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N;
     cin >> N;
     for (int i = 0; i < N; i++) {
          string data;
          int s, b;
          cin >> data >> s >> b;
          s_arr[i] = s;
          b_arr[i] = b;
          for (int j = 0; j < 3; j++) {
               int n = (int)data[j] - 48;
               arr[i][j] = n;
          }
     }
     int ans = 0;
     for (int i = 123; i <= 999; i++) {
          int tmp = i;
          int n1, n2, n3;
          n1 = tmp / 100; tmp %= 100;
          n2 = tmp / 10; tmp %= 10;
          n3 = tmp;
          //cout << "n1 : " << n1 << " n2 : " << n2 << " n3 : " << n3 << endl;
          int i_arr[3] = { n1,n2,n3 };
          bool fail = false;
          if (n1 != n2 && n2 != n3 && n1 != 0 && n2 != 0 && n3 != 0 && n1 != n3) {
               for (int j = 0; j < N; j++) {
                    int s_tmp = 0;
                    int b_tmp = 0;
                    for (int z = 0; z < 3; z++) {
                         for (int zz = 0; zz < 3; zz++) {
                              if (arr[j][zz] == i_arr[z] && z == zz) s_tmp++;
                              else if (arr[j][zz] == i_arr[z]) b_tmp++;
                         }
                    }
                    if (s_arr[j] != s_tmp || b_arr[j] != b_tmp) {
                         fail = true;
                         break;
                    }
               }
          }
          else {
               fail = true;
          }
          if (fail == false) {
               ans++;
          }
     }
     cout << ans << "\n";
}