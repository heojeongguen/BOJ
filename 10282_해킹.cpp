#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX_N 10001
vector<pair<int, int>> vec[MAX_N];

class PQItem {
public:
     int n, cost, prevCost;
     PQItem(int n, int  cost) {
          this->n = n;
          this->cost = cost;
     }
     bool operator > (const PQItem & b) const {
          return this->cost > b.cost;
     }
};
priority_queue<PQItem, vector<PQItem>, greater<> > pq;

int dist[MAX_N];
bool visit[MAX_N];
pair<int,int> dijstra(int c) {
     int MAX = 0;
     int cnt = 1;
     pq.push(PQItem(c, 0));
     dist[c] = 0;
     visit[c] = true;
     while (!pq.empty()) {
          PQItem top = pq.top(); pq.pop();
          int n = top.n;
          int cost = top.cost;
          int prevConst = top.prevCost;
          if (dist[n] < cost) continue;
          MAX = max(MAX, cost);
          for (int i = 0; i < vec[n].size(); i++) {
               int nextN = vec[n][i].first;
               int nextCost = cost + vec[n][i].second;
               if (dist[nextN] > nextCost) {
                    dist[nextN] = nextCost;
                    if (visit[nextN] == false) {
                         visit[nextN] = true;
                         cnt++;
                    }
                    pq.push(PQItem(nextN, nextCost));
               }
          }
     }
     return { MAX,cnt };
}

int main() {
     ios::sync_with_stdio(false);  cin.tie(0);   cout.tie(0);
     int t; cin >> t;
     while (t--) {
          int n, d, c; cin >> n >> d >> c;
          for (int i = 0; i <= n; i++) {
               dist[i] = 1e9;
               visit[i] = false;
               vec[i].clear();
           }
          for (int i = 0; i < d; i++) {
               int a, b, w; cin >> a >> b >> w;
               vec[b].push_back({ a,w });
          }
          pair<int,int> result = dijstra(c);
          cout << result.second << " " << result.first << "\n";
     }
}