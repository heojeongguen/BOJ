#include <iostream>
using namespace std;

#define MAX_N 100001
#define MAX_M 100001
int tree[MAX_N * 8]; 
int ans[MAX_M], arr[MAX_N];

int update_tree(int now, int target, int start, int end, int value) {
     if (target > end || target < start) return tree[now];
     if (start == end) {
          tree[now] = value;
          return tree[now];
     }
     int mid = (start + end) / 2;
     tree[now] = update_tree(now * 2, target, start, mid, value) + update_tree(now*2+1,target,mid+1,end, value);
     return tree[now];
}

int query(int now, int left, int right, int start, int end) {
     if (left > end || right < start) return 0;
     if (left <= start && end <= right)  return tree[now];
     int mid = (start + end) / 2;
     return query(now * 2, left, right, start, mid) + query(now * 2 + 1, left, right, mid + 1, end);
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int T; cin >> T;
     while (T--) {
          int n, m;
          cin >> n >> m;
          int size = n + m - 1;
          for (int i = 0; i < n+m; i++) {
               if (i < n)
                    update_tree(1, i, 0, size, 1);
               else
                    update_tree(1, i, 0, size, 0);
               
          }
          for (int i = n; i >= 1; i--) {
               arr[i] = (n - i);
          }
       
          for (int i = 0; i < m; i++) {
               int data; cin >> data;
               int target = arr[data];
               ans[i] = query(1, target+1, size, 0, size);
               update_tree(1, target, 0, size, 0);
               update_tree(1, n, 0, size, 1);
               arr[data] = ++n;
          }
          for (int i = 0; i < m; i++) {
               cout << ans[i] << " ";
          }
          cout << "\n";
     }
}