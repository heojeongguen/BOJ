#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 100001

// { 음수의갯수, 0의 존재여부 }
pair<int,bool> tree[MAX_N * 4];

void update_tree(int now, int target, int start, int end, int value) {
     if (target > end || target < start) return;
     if (start == end) {
          if (value == 0) 
              tree[now] = { 0,true };
          else if (value < 0) 
             tree[now] = { 1,false };
          else 
              tree[now] = { 0, false };
          return;
     }
     int mid = (start + end) / 2;
     update_tree(now * 2, target, start, mid, value);
     update_tree(now * 2 + 1, target, mid + 1, end, value);

     tree[now].first = tree[now * 2].first + tree[now * 2 + 1].first;
     (tree[now * 2].second || tree[now * 2 + 1].second)? tree[now].second = true : tree[now].second = false;
}

pair<int, bool> query(int now, int left, int right, int start, int end) {
     if (left > end || right < start) return {0,false};
     if (left <= start && end <= right) {
          return tree[now];
     }
     int mid = (start + end) / 2;
     pair<int, bool> ret = { 0,false };
     pair<int, bool> left_ret = query(now * 2, left,right, start, mid);
     pair<int, bool> right_ret = query(now * 2 + 1, left, right, mid + 1, end);
     ret.first = left_ret.first + right_ret.first;
     (left_ret.second == true || right_ret.second == true)?ret.second = true: ret.second = false;
     return ret;
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, K;
     while (cin >> N >> K) {
          for (int i = 0; i <= 4 * N; i++) {
               tree[i].first = 0;
               tree[i].second = false;
          }
          for (int i = 0; i < N; i++) {
               int data; cin >> data;
               update_tree(1, i, 0, N - 1, data);
          }
          for (int i = 0; i < K; i++) {
               char tag; cin >> tag;
               if (tag == 'C') {
                    int a, b; cin >> a >> b;
                    update_tree(1, a - 1, 0, N - 1, b);
               }
               else {
                    int a, b; cin >> a >> b;
                    pair<int, bool> ret = query(1, a - 1, b - 1, 0, N - 1);
                    if (ret.second) cout << "0";
                    else {
                         if (ret.first % 2 == 1) cout << "-";
                         else cout << "+";
                    }
               }
          }
          cout << "\n";
     }
}