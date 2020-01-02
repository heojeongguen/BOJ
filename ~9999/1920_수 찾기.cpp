#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
using namespace std;
vector<long long> vec;
vector <long long > ::iterator iter;
vector<int> ans;

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, data;
     cin >> N;
     vec.push_back(LLONG_MIN);
     for (int i = 0; i < N; i++) {
          cin >> data;
          vec.push_back(data);
     }
     vec.push_back(LLONG_MAX);
     sort(vec.begin(), vec.end());

     cin >> N;
     for (int j = 0; j < N; j++) {
          cin >> data;
          iter = lower_bound(vec.begin(), vec.end(), data);
          if (*iter == data) {
               ans.push_back(1);
          }
          else {
               ans.push_back(0);
          }
     }
     for (int i = 0; i < ans.size(); i++) {
          cout << ans[i] << "\n";
     }
}