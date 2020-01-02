#include <iostream>
using namespace std;

#define MAX_N 500000
int map[1000001];
int tree[MAX_N * 4];

int update_tree(int now, int target,int start, int end) {
     if (target > end || target < start) return tree[now];
     if (start == end) return ++tree[now];
     int mid = (start + end) / 2;
     return tree[now] = update_tree(now * 2, target, start, mid) + update_tree(now * 2 + 1, target, mid + 1, end);
}

int query(int now, int left, int right, int start, int end) {
     if (left > end || right < start) return 0;
     if (left <= start && end <= right) return tree[now];
     int mid = (start + end) / 2;
     return query(now * 2, left, right, start, mid) + query(now * 2 + 1, left, right, mid + 1, end);
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N; cin >> N;
     for (int i = 0; i < N; i++) {
          int data; cin >> data;
          map[data] = i;
     }
     long long ans = 0;
     for (int i = 0; i < N; ++i) {
          int data; cin >> data;
          int target = map[data];
          ans += query(1, target, N - 1, 0, N - 1);
          update_tree(1, target, 0, N - 1);
     }
     cout << ans << "\n";
}