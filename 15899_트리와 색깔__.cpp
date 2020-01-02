#include <iostream>
#include <vector>
#include <algorithm>
#define DIV 1000000007
using namespace std;
// ������ ����
vector<int> vec[200001]; 

// color[k] : k�� ����� color
int color[200001]; 

// childCnt[k] : k�� ����� �ڽ� ����
int childCnt[200001]; 

// leaf[k] : index_tree���� k���� leaf ����� ���� 
int leaf[200001]; 

// seg[k] : index_tree���� k��° ����� ���� list;
// seg[1] : ���� Ʈ������ 1~N������� ��� ���򸮽�Ʈ�� ������ �ִ�.
vector<int> seg[800002]; 

// linear[k] : ����Ʈ���� k�� ��尡 index_tree���� ���° ����������� ��Ÿ��
int linear[200001]; 

// linear[K] = cnt �� ���� linear�� set���ش�.
int cnt = 0;

int dfs(int now, int prev) {
     int ret = 1;
     for (int i = 0; i < vec[now].size(); i++) {
          if (vec[now][i] != prev) {
               ret += dfs(vec[now][i], now);
          }
     }
     // 1�����( ��Ʈ����� ��� cnt�� ��尹��(N)�� �ȴ�)
     // ��, index Ʈ������ ��������� ���� �����ʿ� ��ġ�ϰ� �ȴ�.
     cnt++; 

     // �ڽİ����� count�ϴ� ���� : �ε��� Ʈ�� ��������
     //  [(�ڽ��� ��ġ - �ڽİ���), �ڽ�����ġ] �� ��������� �ڽ��� ���Ե� ����Ʈ���� �����̴�.
     childCnt[now] = ret;
     linear[now] = cnt;

     leaf[cnt] = color[now];
     return ret;
}

void init(int l, int r, int now) {
     // ���������, �ڱ��ڽ��� ������ list�� ������ �ִ�.
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
     //���� üũ
     if (r < leftNode || l > rightNode) return 0;

     // �ش� �������, upper_bound�� ���� ������ ī��Ʈ ���ش�.
     if (l <= leftNode && rightNode <= r) {
          return distance(seg[now].begin(), upper_bound(seg[now].begin(), seg[now].end(), value));
     }

     // ���ȣ��
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