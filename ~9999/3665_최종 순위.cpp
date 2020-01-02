#include <iostream>
#include <queue>
using namespace std;

int arr[501];
int arr2[501];
int indegree[501];
int ans[501];
vector<int> vec[501];
queue<int> que;
int main() {
     int T, N,M;
     cin >> T;
     for (int t = 1; t <= T; t++) {
          cin >> N;

          for (int i = 1; i <= N; i++) {
               arr[i] = 0;
               indegree[i] = 0;
               ans[i] = 0;
               vec[i].clear();
          }

          for (int i = 1; i <= N; i++) {
               int data; cin >> data;
               arr[i] = data;
               arr2[data] = i;
          }

          for (int i = 1; i <= N; i++) {
               int nowRank = arr[i];
               for (int j = nowRank+1; j <= N; j++) {
                    vec[i].push_back(arr2[j]);
                    indegree[arr2[j]]++;
               }
          }


          cin >> M;

          for (int i = 0; i < M; i++)
          {
               int a, b;
               cin >> a >> b;
               if (arr[a] < arr[b]) {
                    for (int j = 0; j < vec[a].size(); j++) {
                         if (vec[a][j] == b) {
                              indegree[vec[a][j]]--;

                              vec[a][j] *= -1;
                              break;
                         }
                    }
                    vec[b].push_back(a);
                    indegree[a]++;
               }
               else {
                    for (int j = 0; j < vec[b].size(); j++) {
                         if (vec[b][j] == a) {
                              indegree[vec[b][j]]--;
                              vec[b][j] *= -1;
                              break;
                         }
                    }
                    vec[a].push_back(b);
                    indegree[b]++;
               }
          }



      /*    for (int i = 1; i <= N; i++) {
               cout << i << " : " << " inderee : " << indegree[i] << endl;
               for (int j = 0; j < vec[i].size(); j++) {
                    cout << vec[i][j] << " ";
               }
               cout << endl;
          }*/

          for (int i = 1; i <= N; i++) {
               if (indegree[i] == 0) {
                    que.push(i);
               }
          }

          bool impossible = false;
          int cnt = 0;
          while (!que.empty()) {
               if (que.size() != 1) {
                    impossible = true;
                    break;
               }
               int front = que.front(); que.pop();
               cnt++;
               ans[cnt] = front;
               for (int i = 0; i < vec[front].size(); i++) {
                    if (vec[front][i] > 0) {
                         indegree[vec[front][i]]--;
                         if (indegree[vec[front][i]] == 0) {
                              que.push(vec[front][i]);
                         }
                    }
               }
          }


          if (impossible) cout << "?";
          else if (cnt != N) cout << "IMPOSSIBLE";
          else {
               for (int i = 1; i <= N; i++) {
                    cout << ans[i] << " ";
               }
          }
          cout << endl;

     }
}