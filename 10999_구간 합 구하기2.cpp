#include <iostream>
using namespace std;

#define MAX_N 1000001
#define endl '\n'
typedef long long ll;
ll seg[MAX_N * 4];
ll lazy[MAX_N * 4];

void update_tree(int now, int target, int start, int end, ll value) {
     if (target > end || target < start) return;
     if (start == end) {
          seg[now] = value;
          return;
     }
     int mid = (start + end) / 2;
     update_tree(now * 2, target, start, mid, value);
     update_tree(now * 2 + 1, target, mid + 1, end, value);
     seg[now] = seg[now * 2] + seg[now * 2 + 1];
}

void update_lazy(int now,int start, int end){
     if (lazy[now] != 0) {
          seg[now] += (end - start + 1) * lazy[now];
          // �ڽ��� �ڽ� ��������� ������ŭ segment tree�� ������
          if (start != end) { // ���� ������尡 �ƴ϶��
               lazy[now * 2] += lazy[now];
               lazy[now * 2 + 1] += lazy[now];
               // �ڽ��� �ڽĵ��� ��忡�� lazy ����
          }
          lazy[now] = 0; // �ش� ���׸�Ʈ Ʈ�� ��忡 ���ؼ� ������Ʈ �Ϸ� �������� lazy �ʱ�ȭ
     }
}

void update_range(int now, int left, int right, int start, int end, ll value) {
     update_lazy(now, start, end);
     if (left > end || right < start) return;
     if (left <= start && end <= right) {
          seg[now] += (end - start + 1) * value;
          if (start != end) {
               lazy[now * 2] += value;
               lazy[now * 2 + 1] += value;
          }
          return;
     }
     int mid = (start + end) / 2;
     update_range(now * 2, left, right, start, mid, value);
     update_range(now * 2 + 1, left, right, mid + 1, end, value);
     seg[now] = seg[now * 2] + seg[now * 2 + 1];
}

ll query(int now, int left, int right, int start, int end) {
     update_lazy(now, start, end);
     if (left >end || right < start) return 0;
     if (left <= start && end <= right) {
          return seg[now];
     }
     int mid = (start + end) / 2;
     return (
          query(now * 2, left, right, start, mid) +
          query(now * 2 + 1, left, right, mid + 1, end)
          );
}

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N, M, K;
     cin >> N >> M >> K;
     for (int i = 0; i < N; i++) {
          ll data; cin >> data;
          update_tree(1, i, 0, N - 1, data);
     }
     for (int i = 0; i < M + K; i++) {
          int tag; cin >> tag;
          if (tag == 1) { // b ~ c , d update
               int b, c; ll value;
               cin >> b >> c >> value;
               update_range(1, b - 1, c - 1, 0, N - 1, value);
          }
          else { // b ~ c ������
               int b, c; cin >> b >> c;
               cout << query(1, b - 1, c - 1, 0, N - 1) << endl;
          }
     }
}