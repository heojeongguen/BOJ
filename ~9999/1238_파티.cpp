#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <functional>
#define INF INT_MAX
using namespace std;
class Info {
public:
     int v;
     int cost;
     Info(int v, int cost) {
          this->v = v;
          this->cost = cost;
     }
     bool operator < (const Info &b) const {
          return this->cost < b.cost;
     }
     bool operator > (const Info &b) const {
          return this->cost > b.cost;
     }
};
vector<pair<int, int> > vec[1001];
vector<pair<int, int> > vec2[1001];

priority_queue<Info, vector<Info>, greater<Info> > pq;
int dp[1001];
int dp2[1001];

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, M, X;
     cin >> N >> M >> X;
     for (int i = 0; i < M; i++) {
          int a, b, c;
          cin >> a >> b >> c;
          vec[b].push_back({ a,c });
          vec2[a].push_back({ b,c });
     }
     for (int i = 1; i <= N; i++) {
          dp[i] = INF;
          dp2[i] = INF;
     }

     pq.push({ X,0 });
     dp[X] = 0;
     while (!pq.empty()) {
          Info top = pq.top(); pq.pop();
          int v = top.v;
          int cost = top.cost;
          if (cost > dp[v]) continue;

          for (int i = 0; i < vec[v].size(); i++) {
               int adj_v = vec[v][i].first;
               int adj_cost = cost + vec[v][i].second;

               if (dp[adj_v] > adj_cost) {
                    dp[adj_v] = adj_cost;
                    pq.push({ adj_v, adj_cost });
               }
          }
     }

     pq.push({ X,0 });
     dp2[X] = 0;
     while (!pq.empty()) {
          Info top = pq.top(); pq.pop();
          int v = top.v;
          int cost = top.cost;
          if (cost > dp2[v]) continue;

          for (int i = 0; i < vec2[v].size(); i++) {
               int adj_v = vec2[v][i].first;
               int adj_cost = cost + vec2[v][i].second;

               if (dp2[adj_v] > adj_cost) {
                    dp2[adj_v] = adj_cost;
                    pq.push({ adj_v, adj_cost });
               }
          }
     }
     int ans = -1;
     for (int i = 1; i <= N; i++) {
          ans = max(dp[i] + dp2[i], ans);
     }
     cout << ans << endl;
     return 0;
}