#include <iostream>
using namespace std;

#define MAX_N 100000
#define endl '\n'

int seg[MAX_N*4];
bool lazy[MAX_N*4];

void update_lazy(int now, int start, int end) {
     if (lazy[now] == true) {
          seg[now] = (end - start + 1) - seg[now];
          if (start != end) {
               lazy[now * 2] = (lazy[now * 2]) ? false : true;
               lazy[now * 2 + 1] = (lazy[now * 2 + 1]) ? false : true;
          }
          lazy[now] = false;
     }
}

void update_range(int now, int left, int right, int start, int end) {
     update_lazy(now, start, end);
     if (left > end || right < start) return;
     if (left <= start && end <= right) {
          seg[now] = (end - start + 1) - seg[now];
          if (start != end) {
               lazy[now * 2] = (lazy[now * 2]) ? false : true;
               lazy[now * 2 + 1] = (lazy[now * 2 + 1]) ? false : true;
          }
          return;
     }
     int mid = (start + end) / 2;
     update_range(now * 2, left, right, start, mid);
     update_range(now * 2 + 1, left, right, mid + 1, end);
     seg[now] = seg[now * 2] + seg[now * 2 + 1];
}

int query(int now, int left, int right, int start, int end) {
     update_lazy(now, start, end);
     if (left > end || right < start) return 0;
     if (left <= start && end <= right) {
          return seg[now];
     }
     int mid = (start + end) / 2;
     return(
          query(now * 2, left, right, start, mid) +
          query(now * 2 + 1, left, right, mid + 1, end)
          );
}

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N, Q; cin >> N >> Q;
     for (int i = 0; i < Q; i++) {
          int tag; cin >> tag;
          if (tag == 0) { // ¹ÝÀü
               int s, e; cin >> s >> e;
               update_range(1, s - 1, e - 1, 0, N - 1);
          }
          else { // onÀÇ °¹¼ö
               int s, e; cin >> s >> e;
               cout << query(1, s - 1, e - 1, 0, N - 1) << endl;
          }
     }
}