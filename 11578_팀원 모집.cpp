#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> vec[11];
bool arr[11];
int N, M;
int n, d;
int mmin = -1;
void fuc(int now, int num, set<int> s) {
     if (now == M+1) {
          if (s.size() == N) {
               if (mmin == -1) mmin = num;
               else  mmin = min(mmin, num);
          }
          return;
     }

     fuc(now + 1, num, s);

     for (const auto & x : vec[now]) 
          s.insert(x);

     fuc(now + 1, num+1, s);
}

int main() {

     cin >> N >> M;
     for (int i = 0; i < M; i++) {
          cin >> n;
          for (int j = 0; j < n; j++) {
               cin >> d;
               vec[i].push_back(d);
          }
     }
     set<int> s;
     fuc(0, 0, s);
     cout << mmin << endl;
}