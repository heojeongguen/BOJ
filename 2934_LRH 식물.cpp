#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define MAX_N 100000
int tree[MAX_N + 1];

void update(int target,int value) {
     while (target <= MAX_N) {
          tree[target] += value;
          target += (target & -target);
     }
}

void update2(int target, int value) {
     while (target <= MAX_N) {
          tree[target] += value;
          cout << "tree[" << target << "] += " << value << endl;
          target += (target & -target);
     }
}

int query(int target) {
     int ret = 0;
     while (target >= 1) {
          ret += tree[target];
          target -= (target & -target);
     }
     return ret;
}

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N; cin >> N;
     for (int i = 0; i < N; i++) {
          int a, b; cin >> a >> b;
          if (i) {
               int right = query(b);
               int left = query(a);
               update(b, -right); update(b + 1, right);
               update(a, -left); update(a + 1, left);
               cout << right + left << "\n";
          }
          else {
               cout << 0 << "\n";
          }
          update2(a + 1, 1);
          update2(b, -1);
     }
}