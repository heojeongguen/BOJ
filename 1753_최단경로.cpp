#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
#define MAX INT_MAX
vector<pair<int,int>> vec[20001];
int dp[20001];

class Info {
public:
     int v;
     int wei;
     Info(int v, int wei) {
          this->v = v;
          this->wei = wei;
     }
     bool operator < (const Info & b) const {
          return this->wei < b.wei;
     }
     bool operator > (const Info & b) const {
          return this->wei > b.wei;
     }
};

priority_queue < Info, vector<Info>, greater<Info> > pq;
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int V, E, st;
     cin >> V >> E;
     cin >> st;
     
     for (int i = 0; i < E; i++) {
          int a, b,c;
          cin >> a >> b >> c;
          vec[a].push_back({ b,c });
     }
     for (int i = 1; i <= V; i++) {
          dp[i] = MAX;
     }

     pq.push({st,0});
     while (!pq.empty()) {
          Info top = pq.top(); pq.pop();
          int cost = top.wei;
          int v = top.v;

          if (dp[v] < cost) continue;

          for (int i = 0; i < vec[v].size(); i++)

          {
               int adj_v = vec[v][i].first;
               int adj_cost = cost + vec[v][i].second;
               if (dp[adj_v] > adj_cost)
               {
                    dp[adj_v] = adj_cost;
                    pq.push(Info(adj_v, adj_cost));
               }
          }
     }

     
     for (int i = 1; i <= V; i++) {
          if (i == st) cout << 0 << endl;
          else if(dp[i] == MAX) cout << "INF\n";
          else cout << dp[i] << "\n";
     }
     return 0;
}