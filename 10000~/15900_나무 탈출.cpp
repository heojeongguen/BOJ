#include <iostream>
#include <vector>
using namespace std;
vector<int> vec[500001];
bool visit[500001];
int cnt_edge = 0;
void dfs(int now,int height) {
     visit[now] = true;
     bool havechild = false;
     for (int i = 0; i < vec[now].size(); i++) {
          if (visit[vec[now][i]] == false) {
               dfs(vec[now][i],height+1);
               havechild = true;
          }
     }
     if (!havechild) cnt_edge += height;
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N;
     cin >> N;
     for (int i = 0; i < N - 1; i++) {
          int a, b;
          cin >> a >> b;
          vec[a].push_back(b);
          vec[b].push_back(a);
     }
     dfs(1,0);
     if (cnt_edge % 2 == 0) {
          cout << "No\n";
     }
     else {
          cout << "Yes\n";
     }
}