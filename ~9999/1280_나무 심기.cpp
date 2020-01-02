#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>
using namespace std;

#define MAX_N 200000
#define DIV 1000000007
typedef long long ll;
ll tree_dist[MAX_N+1];
int tree_cnt[MAX_N+1];
int N;

void update_dist(int target, int value) {
     while (target <= MAX_N) {
          tree_dist[target] += value;
          target += (target & -target);
     }
}

void update_cnt(int target, int value) {
     while (target <= MAX_N) {
          tree_cnt[target] += value;
          target += (target & -target);

     }
}

ll query_dist(int target) {
     ll ret = 0;
     while (target >= 1) {
          ret += tree_dist[target];
          target -= (target & -target);
     }
     return ret;
}
int query_cnt(int target) {
     int ret = 0;
     while (target >= 1) {
          ret += tree_cnt[target];
          target -= (target & -target);
     }
     return ret;
}

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N; cin >> N;
     ll ret = 1;
     for (int i = 1; i <= N; i++) {
          ll tmp = 0;
          int data; cin >> data; data++;
          if (i == 1) {
               update_cnt(data, 1);
               update_dist(data, data);
          }
          else {
               tmp = (tmp + (query_cnt(data - 1) * data) - (query_dist(data - 1))) % DIV;
               tmp = (tmp + (query_dist(MAX_N) - query_dist(data)) - (query_cnt(MAX_N) - query_cnt(data)) * data) % DIV;;
               update_cnt(data, 1);
               update_dist(data, data);
               ret = (ret * tmp) % DIV;
          }
       
     }
     cout << ret % DIV << "\n";

}