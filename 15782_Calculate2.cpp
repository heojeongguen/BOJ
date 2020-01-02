#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define endl '\n';
using namespace std;
vector<int> map[100001];
int child[100001];
int number[100001];
int wei[100001];
int p[100001];
int cnt = 0;

// DFS를 통해서 segment트리의 정보를 만듬
// number : number[now] = 0 인 now는 제일처음으로 발견된 리프노드임
//          number[now] = 1 인 now는 2번쨰로 발견된 리프노드 또는 0번째의 부모임.
//          0번째로 발견된 노드는 세그먼트 트리에서 가장 왼쪽아래 리프노드가되고
//          n-1번째로 발견된 노드는 세그먼트 트리에서 가장 오른쪾아래 리프노드가 된다.
// child : 해당 now(node번호)노드의 자식의 수를 담고있는 배열
//         만약 k 번째로 발견된 노드(세그먼트 트리에서 k번쨰 리프노드) 의 child가 4명이면
//         [k-4,k] 가 k번째 노드에 의해 영향받는 자식노드들 이다.
// p 배열 : p [ k ] : 세그먼트 트리에서 k번째 리프노드의 weight를 가지고 있음. 
int init_seg_data(int now,int prev) {
     int child_cnt = 0;
     
     for (int next : map[now]) {
          if (prev != next) child_cnt += init_seg_data(next,now);
     }

     p[cnt] = wei[now];
     number[now] = cnt++;
     child[now] = child_cnt;

     return child_cnt+1;
}

// 제일 초기 XOR 된 값을 가지고 있음
// ( lazy세그먼트 트리는 모두 0으로 초기화 되있음 )
void init(vector<int> &tree, int node, int st, int end) {
     // 해당 노드가 리프노드라면 해당 노드의 weight를 초기화 해줌;
     if (st == end) {
          tree[node] = p[st];
          return;
     }
     init(tree, node * 2, st, (st + end) / 2);
     init(tree, node * 2 + 1, (st + end) / 2 + 1, end);

     // tree[node]는 자신 가지고 있는 모든 자식 노드의 값을 XOR한 값이다;
     tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}


void update_lazy(vector<int> &tree, vector<int>& lazy, int node, int st, int end) {
     if (lazy[node] != 0) {
          if ((end - st + 1) & 1) {
               tree[node] ^= lazy[node];
          }
          if (st != end) {
               lazy[node * 2] ^= lazy[node];
               lazy[node * 2 + 1] ^= lazy[node];
          }
          lazy[node] = 0;
     }
}

void update_range(vector<int> & tree, vector<int> & lazy, int node, int start, int end,int i ,int j , int data) {
     update_lazy(tree, lazy, node, start, end);
     if (i > end || j < start) return;
     if (i <= start && end <= j) {
          if ((end - start + 1) & 1) tree[node] ^= data;
          if (start != end) {
               lazy[node * 2] ^= data;
               lazy[node * 2 + 1] ^= data;
          }
          return;
     }
     update_range(tree, lazy, node * 2, start, (start + end) / 2, i, j, data);
     update_range(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i, j, data);
     tree[node] = tree[node * 2] ^ tree[node * 2 + 1];  
}
int query(vector<int>&tree, vector<int>&lazy, int node, int start, int end, int i, int j) {
     update_lazy(tree, lazy, node, start, end);
     if (i > end || j < start)return 0;
     if (i <= start && end <= j) return tree[node];
     return query(tree, lazy, node * 2, start, (start + end) / 2, i, j) ^ query(tree, lazy, node * 2 + 1, (start + end) / 2 + 1, end, i, j);
}
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, M;
     int a, b;
     cin >> N >> M;

     int h = (int)ceil(log2(N + 1));
     int tree_size = (1 << (h + 1));
     vector<int> tree(tree_size), lazy(tree_size);
     for (int i = 0; i < N-1; i++) {
          cin >> a >> b;
          a--;
          b--;
          map[a].push_back(b);
          map[b].push_back(a);
     }
     for (int i = 0; i < N; i++) {
          int tmp; cin >> tmp;
          wei[i] = tmp;
     }
     init_seg_data(0,-1);
     init(tree, 1, 0, N - 1);

     for (int i = 0; i < M; i++) {
          int x;
          cin >> x;
          if (x == 1) {
               int pos;
               cin >> pos;
               pos--;
               cout << query(tree, lazy, 1, 0, N - 1, number[pos] - child[pos], number[pos]) << endl;
          }
          else {
               int pos, data;
               cin >> pos >> data;
               pos--;
               update_range(tree, lazy, 1, 0, N - 1, number[pos] - child[pos], number[pos], data);
          }
     }
}