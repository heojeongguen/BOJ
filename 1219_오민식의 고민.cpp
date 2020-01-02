#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <limits.h>
using namespace std;
#define MAX_N 101
typedef long long ll;
vector<pair<int, int> > vec[MAX_N];
int earn[MAX_N];
ll dist[MAX_N];
bool visit[MAX_N];
void DFS(int now) {
     visit[now] = true;
     for (int i = 0; i < vec[now].size(); i++) {
          if (visit[vec[now][i].first] == false) {
               DFS(vec[now][i].first);
          }
     }
}

int main() {
     int N, S, E, M;
     cin >> N >> S >> E >> M;
     for (int i = 0; i < N; i++) {
          dist[i] = LONG_MIN;
     }
     for (int i = 0; i < M; i++) {
          int s, e, c; cin >> s >> e >> c;
          vec[s].push_back({ e, -1 * c });
     }

     for (int i = 0; i < N; i++) {
          cin >> earn[i];
     }

     DFS(S);
     if (visit[E] == false) {
          cout << "gg\n";
          return 0;
     }

     for (int i = 0; i < N; i++) {
          for (int j = 0; j < vec[i].size(); j++) {
               vec[i][j].second += earn[vec[i][j].first];
          }
     }


     dist[S] = earn[S];
     for (int i = 1; i <= 2 * N; i++) {
          for (int j = 0; j < N; j++) {
               for (const auto & x : vec[j]) {
                    int next = x.first; ll cost = x.second;
                    if (dist[j] == LONG_MAX) dist[next] = LONG_MAX;
                    else if (dist[j] != LONG_MIN && dist[next] < dist[j] + cost) {
                         dist[next] = dist[j] + cost;
                         //cout << "dist[" << next << "] : " << dist[next] << endl;
                         if (i >= N) dist[next] = LONG_MAX;
                    }
               }
          }
     }
     // 사이클이 존재한다. 
     if (dist[E] == LONG_MAX) cout << "Gee\n";
     else cout << dist[E] << "\n";
}