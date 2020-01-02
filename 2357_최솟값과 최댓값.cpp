#include <iostream>
#include <algorithm>
#define MAX_N 100000
using namespace std;

int tree_max[MAX_N * 4];
int tree_min[MAX_N * 4];
int update_tree_max(int now, int target, int data, int start, int end) {
     if (target < start || target > end) return tree_max[now];
     if (start == end) {
          tree_max[now] = data;
          return tree_max[now];
     }
     int mid = (start + end) / 2;
     tree_max[now] = max(update_tree_max(now * 2, target, data, start, mid), update_tree_max(now * 2 + 1, target, data, mid + 1, end));
     return tree_max[now];
}

int query_max(int now, int left, int right, int start, int end) {
     if (left > end || right < start) return 0;
     if (left <= start && right >= end) return tree_max[now];
     int mid = (start + end) / 2;
     return max(query_max(2 * now, left, right, start, mid), query_max(2 * now + 1, left, right, mid + 1, end));
}

int update_tree_min(int now, int target, int data, int start, int end) {
     if (target < start || target > end) return tree_min[now];
     if (start == end) {
          tree_min[now] = data;
          return tree_min[now];
     }
     int mid = (start + end) / 2;
     tree_min[now] = min(update_tree_min(now * 2, target, data, start, mid), update_tree_min(now * 2 + 1, target, data, mid + 1, end));
     return tree_min[now];
}

int query_min(int now, int left, int right, int start, int end) {
     if (left > end || right < start) return 1e9 + 1;
     if (left <= start && right >= end) return tree_min[now];
     int mid = (start + end) / 2;
     return min(query_min(2 * now, left, right, start, mid), query_min(2 * now + 1, left, right, mid + 1, end));
}


int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, M; cin >> N >> M;
     for (int i = 0; i < N; i++) {
          int data; cin >> data;
          update_tree_min(1, i, data, 0, N - 1);
          update_tree_max(1, i, data, 0, N - 1);
     }
     for (int i = 0; i < M; i++)
     {
          int a, b; cin >> a >> b;
          cout << query_min(1, a - 1, b - 1, 0, N - 1) << " " << query_max(1, a - 1, b - 1, 0, N - 1) << "\n";
     }
}