#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 20001
vector<int> vec[MAX_N];

class PQItem {
public:
     int n;
     int cost;
     PQItem(int n, int cost) {
          this->n = n;
          this->cost = cost;
     }
     bool operator > (const PQItem & b) const {
          return this->cost > b.cost;
     }
};
priority_queue<PQItem, vector<PQItem>, greater<> > pq;

int dist[MAX_N];
int num = -1, dis = 0, cnt = 0;

void dijstra() {
     pq.push(PQItem(1, 0));
     dist[1] = 0;
     while (!pq.empty()) {
          PQItem top = pq.top(); pq.pop();
          int n = top.n;
          int cost = top.cost;
          if (dist[n] < cost) continue;
          for (int i = 0; i < vec[n].size(); i++) {
               int nextCost = 1 + cost;
               if (dist[vec[n][i]] > nextCost) {
                    dist[vec[n][i]] = nextCost;
                    dis = max(dis, nextCost);
                    pq.push(PQItem(vec[n][i], nextCost));
               }
          }
     }
}


int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, M;
     cin >> N >> M;
     for (int i = 0; i <= N; i++) {
          dist[i] = 1e9;
     }
     for (int i = 0; i < M; i++) {
          int a, b; cin >> a >> b;
          vec[a].push_back(b);
          vec[b].push_back(a);
     }
     dijstra();
     for (int i = 1; i <= N; i++) {
          if (dis == dist[i]) {
               if (num == -1) num = i;
               cnt++;
          }
     }
     cout << num << " " << dis << " " << cnt << "\n";
}