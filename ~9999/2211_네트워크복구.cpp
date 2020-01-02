#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX_N 1001
vector<pair<int,int>> vec[MAX_N];

class PQItem {
public:
     int n;
     int cost;
     PQItem(int n, int cost ) {
          this->n = n;
          this->cost = cost;
     }
     bool operator > (const PQItem & b) const {
          return this->cost > b.cost;
     }
};
priority_queue<PQItem, vector<PQItem>, greater<> > pq;

int dist[MAX_N];
int connect[MAX_N];
int connectCnt = 0;

void dijstra() {
     pq.push(PQItem(1, 0));
     dist[1] = 0;
     while (!pq.empty()) {
          PQItem top = pq.top(); pq.pop();
          int n = top.n;
          int cost = top.cost;
          if (dist[n] < cost) continue;
          for (int i = 0; i < vec[n].size(); i++) {
               int nextCost = vec[n][i].second + cost;
               if (dist[vec[n][i].first] > nextCost) {
                    dist[vec[n][i].first] = nextCost;
                    connect[vec[n][i].first] = n;
                    pq.push(PQItem(vec[n][i].first, nextCost));
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
          int a, b, w; cin >> a >> b >> w;
          vec[a].push_back({b,w});
          vec[b].push_back({a,w});
     }
     dijstra();
     cout << N - 1 << "\n";
     for (int i = 2; i <= N; i++) {
         cout << i << " " << connect[i] << "\n";
     }
}