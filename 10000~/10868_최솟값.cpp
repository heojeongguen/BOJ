#include <iostream>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int tree[MAX_N * 4];

int update_tree(int now,int target,int data,int start, int end) {
     if (target < start || target > end) return tree[now];
     if (start == end) {
          tree[now] = data;
          return tree[now];
     }
     int mid = (start + end) / 2;
     tree[now] = min(update_tree(now * 2, target, data, start, mid), update_tree(now * 2 + 1, target, data, mid+1, end));
     return tree[now];
}

int query(int now, int left, int right, int start, int end) {
     if (left > end || right < start) return 1e9+1;
     if (left <= start && right >= end) return tree[now];
     int mid = (start + end) / 2;
     return min(query(2 * now, left, right, start, mid), query(2 * now + 1, left, right, mid+1, end));
}


int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, M; cin >> N >> M;
     for (int i = 0; i < N; i++) {
          int data; cin >> data;
          update_tree(1, i, data, 0, N - 1);
     }
     for (int i = 0; i < M; i++)
     {
          int a, b; cin >> a >> b;
          cout << query(1, a - 1, b - 1, 0, N - 1) << "\n";
     }
}