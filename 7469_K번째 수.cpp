#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX_N 100001
vector<int> tree[MAX_N*4]; // Ʈ���� vector ���·� ���ĵǼ� �ڱ� ���� ������ ���� ����Ǿ� ����.

void update_tree(int now, int target, int start, int end, int value) {
     if (target > end || target < start) return;
     if (start == end) {
          tree[now].push_back(value);
          return;
     }
     // merge sort �� ����� init �� ����ϸ� �� ��������, ū���� �����Ƿ� �׳� main �Լ����� for������ sort���־���.
     tree[now].push_back(value);
     int mid = (start + end) / 2;
     update_tree(now * 2, target, start, mid, value);
     update_tree(now * 2 + 1, target, mid + 1, end, value);
}

// index�� �������ش�
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
          // �������� ��Ÿ���ִ� �ִ������ �̿��ؼ� �Ķ��Ʈ �� ��ġ�� �ּҿ� �ִ��� �����ش�
          int MIN = -1e9, MAX = 1e9;
          while (MIN <= MAX) {
               int MID = (MIN + MAX) / 2;
               // s ~ e �������� MID ���� k���� ������ ���
               // k < x : mid���� ���� ��� k�� x�̻��� ���� �� �ִ�.
               // k > x : mid���� ���� ��� k�� x���ϰ� ���� �� �ִ�.
               int k = query(1, s-1, e-1, 0, n-1, MID);
               if (k < x) MIN = MID + 1;
               else MAX = MID - 1;
          }
          // else �������� " k == x " �ΰ�쿡 ��� ���ڸ� ���� ��� ������, MIN ���� �� ���� �ȴ�.
          cout << MIN << "\n";
     }
}