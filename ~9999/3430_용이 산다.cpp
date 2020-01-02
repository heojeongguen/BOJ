#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <deque>
using namespace std;

vector<pair<int, int>> ans;
queue<int> que;
#define MAX 1000000
int arr[MAX+10];

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int t; cin >> t;
     while (t--) {
          int n, m; cin >> n >> m;
          bool fail = false;
          ans.clear();
          for (int i = 1; i < MAX + 10; i++) {
               arr[i] = 0;
          }

          for (int i = 1; i <= m; i++) {
               int data; cin >> data;
               if (fail) continue;
               if (data == 0) {
                    que.push(i);
               }
               else {
                    if (que.empty()) fail = true;
                    else {
						int top = que.front();
                         que.pop();
                         if (arr[data] < top) {
                              ans.push_back({ top,data });
                              arr[data] = i;
                         }
                         else {
                              fail = true;
                         }
                    }
               }
          }

          if (fail) {
               cout << "NO\n";
               while (!que.empty()) que.pop();
          }
          else {
               while (!que.empty()) {
                    ans.push_back({ que.front(),0 });
                    que.pop();
               }
               sort(ans.begin(), ans.end());
               cout << "YES\n";
               for (int i = 0; i < ans.size(); i++) {
                    cout << ans[i].second << " ";
               }
               cout << "\n";
          }

     }
}