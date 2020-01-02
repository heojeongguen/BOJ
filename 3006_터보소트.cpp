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
int pos[MAX_N + 1];



void update(int target, int value) {
     while (target <= MAX_N) {
          tree[target] += value;
          target += (target & -target);
     }
}

int query(int target) {
     int ret = 0;
     while (target >= 1) {
          ret += tree[target];
          target -= (target &-target);
     }
     return ret;
}

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N; cin >> N;

     for (int i = 1; i <= N; i++) {
          int data; cin >> data;
          update(i, 1);
          pos[data] = i;
     }

     for (int i = 1, j = N; i <= j; i++,j--) {
          int minPos = pos[i];
          int maxPos = pos[j];
          cout << query(minPos-1) << "\n";
          update(minPos, -1);
          if (i != j) {
               cout << query(N) - query(maxPos) << "\n";
               update(maxPos, -1);
          }
     }
}