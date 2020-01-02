#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
map<int,int> m;
map<int,int>::iterator iter;
#define endl '\n'

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, M;
     cin >> N;
     for (int i = 0; i < N; i++) {
          int x; cin >> x;
          iter = m.find(x);
          if(iter == m.end()){
               m.insert({ x,1 });
          } else{
               iter->second++;
          }

     }
     cin >> M;
     vector<int> ans;
     for (int i = 0; i < M; i++) {
          int x; cin >> x;
          iter = m.find(x);
          if (iter == m.end()) {
               ans.push_back(0);
          } else{
               ans.push_back(iter->second);
          }
     }

     for (const auto & x : ans) {
          cout << x << " ";
     }
     return 0;
}