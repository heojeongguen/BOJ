#include <iostream>
#include <vector>
using namespace std;
typedef long long int ll;
vector<int > vec[501];
vector<int> eend;

void print() {
     cout << " eend : ";
     for (const auto & x : eend) {
          cout << x << " ";
     }
     cout << endl;
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int T;
     cin >> T;
     while (T--) {
          eend.clear();
          int n,d;
          cin >> n;
          for (int i = 0; i < n; i++) {
               vec[i].clear();
          }
          for (int i = 0; i < n; i++) {
               for (int j = 0; j < n; j++) {
                    cin >> d;
                    vec[i].push_back(d);
               }
          }
          for (int i = 0; i < n; i++) {
               cin >> d;
               eend.push_back(d);
          }
          bool fail = false;
          ll ans = 0;
          for (int i = 0; i < eend.size(); i++) {
               if (eend[i] % vec[i][i] != 0 || eend[i]* vec[i][i] < 0) {
                    fail = true;
                    break;
               }

               else {
                    int tmp = eend[i] / vec[i][i];
                    ans += tmp;
                    //cout << " i : " << i << " tmp : " << tmp << endl;
                     for (int j = i +1 ; j < eend.size(); j++) {
                         if (vec[i][j] < 0) {
                              eend[j] -= (tmp * vec[i][j]);
                         }
                         else {
                              eend[j] -= (tmp * vec[i][j]);
                         }
                       
                    }
               }
               //print();
          }
          if (fail) cout << 0 << "\n";
          else cout << 1 << " " << ans << "\n";
     }
}