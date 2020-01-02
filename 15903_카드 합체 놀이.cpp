#include <iostream>
#include <queue>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long> > pq;
int main() {
     int n, m;
     cin >> n >> m;
     for (int i = 0; i < n; i++) {
          long long data;
          cin >> data;
          pq.push(data);
     }
     for (int i = 0; i < m; i++) {
          long long n1 = pq.top(); pq.pop();
          long long n2 = pq.top(); pq.pop();
          pq.push(n1 + n2);
          pq.push(n1 + n2);
     }
     long long ans = 0;
     while (!pq.empty()) {
          ans += pq.top(); pq.pop();
     }
     cout << ans << endl;
}