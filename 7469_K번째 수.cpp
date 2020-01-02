#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100001
vector<int> tree[MAX_N*4]; // 트리는 vector 형태로 정렬되서 자기 하위 노드들의 값이 저장되어 있음.

void update_tree(int now, int target, int start, int end, int value) {
     if (target > end || target < start) return;
     if (start == end) {
          tree[now].push_back(value);
          return;
     }
     // merge sort 를 사용한 init 을 사용하면 더 좋겠지만, 큰차이 없으므로 그냥 main 함수에서 for문으로 sort해주었음.
     tree[now].push_back(value);
     int mid = (start + end) / 2;
     update_tree(now * 2, target, start, mid, value);
     update_tree(now * 2 + 1, target, mid + 1, end, value);
}

// index를 리턴해준다
int query(int now, int left, int right, int start, int end,int k) {
     if (left > end || right < start)  {
          return 0;
     }
     if (left <= start && end <= right) {
          return upper_bound(tree[now].begin(), tree[now].end(), k) - tree[now].begin();
     }
     int mid = (start + end) / 2;
     return query(now * 2, left, right, start, mid, k) + query(now * 2 + 1, left, right, mid + 1, end, k);
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int n, Q;
     cin >> n >> Q;
     for (int i = 0; i < n; i++) {
          int data; cin >> data;
          update_tree(1, i, 0, n - 1, data);
     }

     for (int i = 0; i <= 4 * n; i++) {
          sort(tree[i].begin(), tree[i].end());
     }

     for (int i = 0; i < Q; i++) {
          int s, e, x;
          cin >> s >> e >> x;
          // 문제에서 나타나있는 최대범위를 이용해서 파라매트 릭 서치의 최소와 최댓값을 정해준다
          int MIN = -1e9, MAX = 1e9;
          while (MIN <= MAX) {
               int MID = (MIN + MAX) / 2;
               // s ~ e 값사이의 MID 값이 k번쨰 숫자일 경우
               // k < x : mid값을 높여 줘야 k가 x이상이 나올 수 있다.
               // k > x : mid값을 낮춰 줘야 k가 x이하가 나올 수 있다.
               int k = query(1, s-1, e-1, 0, n-1, MID);
               if (k < x) MIN = MID + 1;
               else MAX = MID - 1;
          }
          // else 구문에서 " k == x " 인경우에 계속 숫자를 낮춰 줬기 때문에, MIN 값이 곧 답이 된다.
          cout << MIN << "\n";
     }
}