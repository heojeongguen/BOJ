#include <iostream>
#include <algorithm>
#include <limits.h>
#include <queue>
using namespace std;

bool visit[200001];
int N, K;
queue<pair<int,int>> que;

int ans = INT_MAX;
void BFS(int s) {
     que.push({s,0});
     visit[s] = true;
     while (!que.empty()) {
          int front = que.front().first;
          int cnt = que.front().second;
          que.pop();
          if (front == K) {
               ans = min(ans, cnt);
               break;
          }
          else if (front > K) {
               ans = min(ans, front - K + cnt);
          }
          else {
               cnt++;
               if (visit[2 * front] == false) {
                    visit[2 * front] = true;
                    que.push({ 2 * front ,cnt });
               }
               if (front - 1 >= 0) {
                    if (visit[front - 1] == false) {
                         visit[front - 1] = true;
                         que.push({ front - 1 ,cnt });
                    }
               }
               if (visit[front + 1] == false) {
                    visit[front + 1] = true;
                    que.push({ front + 1 ,cnt });
               }
          }
     }
}



int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     cin >> N >> K;
     BFS(N);
     cout << ans << "\n";
}