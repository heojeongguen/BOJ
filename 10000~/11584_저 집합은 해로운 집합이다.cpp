#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector< pair< float, float> > vec[11];
double divideMom;
int checkC(float tmp) {
     int C = -1;
     for (int i = 0;  i <= 10; i++) {
          bool in = false;
          for (int j = 0; j < vec[i].size(); j++) {
               if (tmp >= vec[i][j].first && tmp <= vec[i][j].second)in = true;
          }
          if (in == false)
               if (C == -1) C = i;
     }
     return C;
}
int main() {
     ios::sync_with_stdio(false);
     cout.tie(0);
     cin.tie(0);
     vec[0].push_back(make_pair( 0.0,1.0 ));
     for (int i = 1; i <= 10; i++) {
          divideMom = pow(3, i);
          for (int j = 0; j < vec[i - 1].size(); j++) {
               vec[i].push_back({ vec[i - 1][j].first , vec[i - 1][j].first   + 1 / divideMom});
               vec[i].push_back({ vec[i - 1][j].second - 1 / divideMom, vec[i - 1][j].second});
          }
     }
     int N;
     cin >> N;
     double a, b, tmp;
     for (int i = 0; i < N; i++) {
          cin >> a >> b;
          tmp = a / b;
          cout << checkC(tmp) << "\n";
     }
     return 0;
}