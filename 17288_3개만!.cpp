#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> vec;
int ans = 0;

void fuc(int now,int prev,int cnt) {
     if (now == vec.size()) {
          if (cnt == 3) {
               ans++;
          }
          return;
     }
     if (vec[now] == prev + 1) {
          cnt++;
     }
     else {
          if (cnt == 3) {
               ans++;
          }
          cnt = 1;
     }
     fuc(now + 1, vec[now], cnt);
}

int main() {
     string str;
     cin >> str;
     for (int i = 0; i < str.size(); i++) {
          vec.push_back((int)str[i] - '0');
     }
     fuc(0, -2, 0);
     cout << ans << "\n";
}