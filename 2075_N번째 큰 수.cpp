#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N; cin >> N;
     for (int i = 0; i < N * N; i++) {
          int x; cin >> x;
          if (pq.empty()) {
               pq.push(x);
          }
          else {
               if (pq.size() < N) {
                    pq.push(x);
               }
               else {
                    if (pq.top() < x) {
                         pq.pop();
                         pq.push(x);
                    }
               }
          }
     }
     cout << pq.top() << "\n";
     return 0;
}