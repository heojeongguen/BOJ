#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200001;
int n, m, c;
int color[MAX]; //i�� ����� ����
vector<int> adj[MAX]; //Ʈ���� ����� ���� ��������Ʈ
int cnt = 0; // idx�� ä��� ���� ī����
vector<int> arr; //�Ϸķ� �� Ʈ���� ����
int child[MAX]; //i�� ����� �ڽ��� ����
pair<int, int> subtreeSeg[MAX]; //i�� ����� ����Ʈ���� ���� ����
int make_tree(int here, int parent) {
     for (int &there : adj[here]) {
          if (there == parent) continue;
          child[here] += make_tree(there, here);
     }
     arr.push_back(color[here]);
     subtreeSeg[here] = { cnt - child[here], cnt };
     ++cnt;
     return 1 + child[here];
}

//���� ��Ʈ Ʈ�� ����
vector<int> seg[MAX * 4 + 1];
void init(int l, int r, int node) {
     if (l == r) {
          seg[node].push_back(arr[l]);
          return;
     }
     int mid = (l + r) / 2;
     init(l, mid, node * 2), init(mid + 1, r, node * 2 + 1);
     auto &left = seg[node * 2], &right = seg[node * 2 + 1];
     //�� ������ merge sort�� �����ش�.
     merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(seg[node]));
}
//[l:r]���� value���� �۰ų� ���� ������ ������ ���Ѵ�.
int query(int value, int l, int r, int node, int nodeL, int nodeR) {
     if (r < nodeL || nodeR < l) return 0;
     if (l <= nodeL && nodeR <= r)
          return distance(seg[node].begin(), upper_bound(seg[node].begin(), seg[node].end(), value));
     int mid = (nodeL + nodeR) / 2;
     return query(value, l, r, node * 2, nodeL, mid) + query(value, l, r, node * 2 + 1, mid + 1, nodeR);
}

int main() {
     cin >> n >> m >> c;
     for (int i = 1; i <= n; ++i)
          cin >> color[i];
     for (int i = 1; i < n; ++i) {
          int a, b;
          cin >> a >> b;
          adj[a].push_back(b);
          adj[b].push_back(a);
     }

     make_tree(1, 0);

     init(0, n - 1, 1);
     int ans = 0;
     for (int i = 0; i < m; ++i) {
          int a, b;
          cin >> a >> b;
          ans = (ans + query(b, subtreeSeg[a].first, subtreeSeg[a].second, 1, 0, n - 1)) % 1000000007;
     }
     cout << ans;
}