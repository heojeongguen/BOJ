#include <iostream>
#include <vector>
#include <algorithm>
#define DIV 1000000007
using namespace std;
// 간선의 정보
vector<int> vec[200001]; 

// color[k] : k번 노드의 color
int color[200001]; 

// childCnt[k] : k번 노드의 자식 갯수
int childCnt[200001]; 

// leaf[k] : index_tree에서 k번쨰 leaf 노드의 색깔 
int leaf[200001]; 

// seg[k] : index_tree에서 k번째 노드의 색깔 list;
// seg[1] : 원래 트리에서 1~N번노드의 모든 색깔리스트를 가지고 있다.
vector<int> seg[800002]; 

// linear[k] : 원래트리의 k번 노드가 index_tree에서 몇번째 리프노드인지 나타냄
int linear[200001]; 

// linear[K] = cnt 를 통해 linear를 set해준다.
int cnt = 0;

int dfs(int now, int prev) {
     int ret = 1;
     for (int i = 0; i < vec[now].size(); i++) {
          if (vec[now][i] != prev) {
               ret += dfs(vec[now][i], now);
          }
     }
     // 1번노드( 루트노드의 경우 cnt는 노드갯수(N)이 된다)
     // 즉, index 트리에서 리프노드의 가장 오른쪽에 위치하게 된다.
     cnt++; 

     // 자식갯수를 count하는 이유 : 인덱스 트리 리프에서
     //  [(자신의 위치 - 자식갯수), 자신의위치] 의 리프노들이 자신이 포함된 서브트리의 노드들이다.
     childCnt[now] = ret;
     linear[now] = cnt;

     leaf[cnt] = color[now];
     return ret;
}

void init(int l, int r, int now) {
     // 리프노드라면, 자기자신의 색깔만을 list에 가지고 있다.
     if (l == r) {
          seg[now].push_back(leaf[l]);
          return;
     }

     //l ~ mid, mid + 1 ~ r;
     int mid = (l + r) / 2;
     init(l, mid, now * 2);
     init(mid + 1,r,now * 2 + 1);


     auto &left = seg[now * 2];
     auto &right = seg[now * 2 + 1];
     merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(seg[now]));
}

int query(int value, int l, int r, int now,int leftNode, int rightNode) {
     //범위 체크
     if (r < leftNode || l > rightNode) return 0;

     // 해당 범위라면, upper_bound를 통해 갯수를 카운트 해준다.
     if (l <= leftNode && rightNode <= r) {
          return distance(seg[now].begin(), upper_bound(seg[now].begin(), seg[now].end(), value));
     }

     // 재귀호출
     int mid = (leftNode + rightNode) / 2;
     return query(value, l, r, now * 2, leftNode, mid) + query(value, l, r, now * 2 + 1, mid + 1, rightNode);
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, M, C;
     cin >> N >> M >> C;
     for (int i = 1; i <= N; i++) {
          cin >> color[i];
     }
     for (int i = 0; i < N - 1; i++) {
          int a, b;
          cin >> a >> b;
          vec[a].push_back(b);
          vec[b].push_back(a);

     }

     dfs(1, -1);
     init(1, N, 1);
     int ans = 0;
     for (int i = 0; i < M; i++) {
          int v, c;
          cin >> v >> c;
          ans = (ans + query(c, linear[v] - (childCnt[v] - 1), linear[v],1,1,N)) % DIV;
     }
     cout << ans << "\n";
    
}