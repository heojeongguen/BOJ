#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200001;
int n, m, c;
int color[MAX]; //i번 노드의 색깔
vector<int> adj[MAX]; //트리를 만들기 위한 인접리스트
int cnt = 0; // idx를 채우기 위한 카운터
vector<int> arr; //일렬로 편 트리의 색깔
int child[MAX]; //i번 노드의 자식의 개수
pair<int, int> subtreeSeg[MAX]; //i번 노드의 서브트리를 덮는 구간
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

//머지 소트 트리 구현
vector<int> seg[MAX * 4 + 1];
void init(int l, int r, int node) {
     if (l == r) {
          seg[node].push_back(arr[l]);
          return;
     }
     int mid = (l + r) / 2;
     init(l, mid, node * 2), init(mid + 1, r, node * 2 + 1);
     auto &left = seg[node * 2], &right = seg[node * 2 + 1];
     //두 구간을 merge sort로 합쳐준다.
     merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(seg[node]));
}
//[l:r]에서 value보다 작거나 같은 원소의 개수를 구한다.
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