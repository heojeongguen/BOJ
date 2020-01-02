#include <iostream>
using namespace std;

#define MAX_N 1000000

int tree[MAX_N * 4];

int update_tree(int now, int target, int start, int end, int cnt) {
     if (target > end || target < start) return tree[now];
     if (start == end) return tree[now] += cnt;
     int mid = (start + end) / 2;
     return tree[now] = update_tree(now * 2, target, start, mid, cnt) + update_tree(now * 2 + 1, target, mid + 1, end, cnt);
}

int query(int now, int k, int start, int end) {
     if (start == end) {
          return start;
     }

     int mid = (start + end) / 2;
     int right_cnt = tree[now * 2 + 1];
     int left_cnt = tree[now * 2];

     if (left_cnt >= k) {
          return query(now * 2, k, start, mid);
     }
     else {
          return query(now * 2 + 1, k - left_cnt, mid + 1, end);
     }
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N; cin >> N;
     for (int i = 0; i < N; i++) {
          int A, B, C; cin >> A;
          if(A == 1) {
               cin >> B;
               int ret = query(1, B, 0, MAX_N - 1);
               cout << ret + 1 << "\n";
               update_tree(1, ret, 0, MAX_N - 1, -1);
          }
          else {
               cin >> B >> C;
               update_tree(1, B - 1, 0, MAX_N - 1, C);
          }
     }
}