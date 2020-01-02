#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<pair<int, int> > vec;

bool visit[103];
vector<int> map[103];

void dfs(int now) {
     visit[now] = true;
     for (int i = 0; i < map[now].size(); i++) {
          if (visit[map[now][i]] == false) {
               dfs(map[now][i]);
          }
     }
}

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int t; cin >> t;
     while (t--) {
          int n, x, y; cin >> n;
          // �ʱ�ȭ
          for (int i = 0; i <= n + 2; i++) {
               map[i].clear();
               visit[i] = false;
          }
          vec.clear();

          // �Է�
          for (int i = 0; i < n+2; i++) {
               int x, y; cin >> x >> y;
               vec.push_back({ x,y });
          }

          // O(n^2)���� ����������� ����������� ��� update
          for (int i = 0; i < vec.size(); i++) {
               for (int j = 0; j < vec.size(); j++) {
                    if (i == j) continue;
                    int cost;
                    if ((abs(vec[i].first - vec[j].first) + abs(vec[i].second - vec[j].second)) % 50 == 0)
                         cost = (abs(vec[i].first - vec[j].first) + abs(vec[i].second - vec[j].second)) / 50;
                    else
                         cost = (abs(vec[i].first - vec[j].first) + abs(vec[i].second - vec[j].second)) / 50 + 1;

                    if (cost <= 20) {
                         map[i].push_back(j);
                    }
               }
          }

          // DFS
          // 0����� : ���� ��ġ
          // N+1����� : �佺Ƽ���� ��ġ
          dfs(0);
          if (visit[n + 1] == true) cout << "happy\n";
          else cout << "sad\n";
     }
}