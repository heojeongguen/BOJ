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
     int wei;
     Info(int v, int wei) {
          this->v = v;
          this->wei = wei;
     }
     bool operator < (const Info &b) const {
          return this->wei < b.wei;
     }
     bool operator > (const Info &b) const {
          return this->wei > b.wei;
     }
};
vector<pair<int, int> > vec[1001];
priority_queue<Info, vector<Info>, greater<Info> > pq;
int dp[1001];
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N, M;
     cin >> N >> M;
     for (int i = 0; i < M; i++) {
          int a, b, cnt;
          cin >> a >> b >> cnt;
          vec[a].push_back({ b,cnt });
     }
     int A, B;
     cin >> A >> B;
     for (int i = 1; i <= N; i++) {
          dp[i] = INF;
     }
     pq.push({ A,0 });
     dp[A] = 0;
     while (!pq.empty()) {
          Info top = pq.top(); pq.pop();
          int nowV = top.v;
          int cost = top.wei;

          if (cost > dp[nowV]) continue;

          for (int i = 0; i < vec[nowV].size(); i++) {
               int adj_v = vec[nowV][i].first;
               int adj_cost = cost + vec[nowV][i].second;

               if (dp[adj_v] > adj_cost) {
                    dp[adj_v] = adj_cost;
                    pq.push({ adj_v,adj_cost });
               }
          }
     }
     cout << dp[B] << "\n";

     return 0;
}