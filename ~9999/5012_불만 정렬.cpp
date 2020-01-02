#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
vector<int> vec;
#define MAX_N 100000
int tree_left[MAX_N + 1];
int tree_right[MAX_N + 1];
vector<int> l, r;

void update(int tree[],int target, int value) {
     while (target <= MAX_N) {
          tree[target] += value;
          target += (target & -target);
     }
}

int query(int tree[],int target) {
     int ret = 0;
     while (target >= 1) {
          ret += tree[target];
          target -= (target &-target);
     }
     return ret;
}

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N;
     cin >> N;
     for (int i = 1; i <= N; i++) {
          int data; cin >> data;
          vec.push_back(data);
     }

     long long ans = 0;
     for (int i = 0, j = vec.size()-1; i < vec.size(); i++, j--) {
          int data_left = vec[i]; 
          int data_right = vec[j];

          int right =  query(tree_right,  data_right-1);
          int left =  query(tree_left, MAX_N) - query(tree_left, data_left);
          l.push_back(left); r.push_back(right);

          update(tree_right, data_right, 1);
          update(tree_left, data_left, 1);

     }
     for (int i = 0, j = r.size()-1; i < l.size(); i++,j--) {
          ans += ((long long)l[i] * r[j]);
     }
     cout << ans << "\n";
}