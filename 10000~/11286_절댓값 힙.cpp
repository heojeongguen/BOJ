#include <iostream>
#include <queue>
using namespace std;
priority_queue<int, vector<int>, greater<int> > plus_pq;
priority_queue<int, vector<int>, less<int> > minus_pq;

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N;
     cin >> N;
     for (int i = 0; i < N; i++) {
          int x;
          cin >> x;
          if (x > 0) {
               plus_pq.push(x);
          }
          else if (x < 0) {
               minus_pq.push(x);
          }
          else{
               if (plus_pq.empty() && minus_pq.empty()) {
                    cout << 0 << "\n";
               }
               else if(plus_pq.empty() && !minus_pq.empty()){
                    cout << minus_pq.top() << "\n";
                    minus_pq.pop();
               }
               else if (!plus_pq.empty() && minus_pq.empty()) {
                    cout << plus_pq.top() << "\n";
                    plus_pq.pop();
               }
               else {
                    int plus = plus_pq.top();
                    int minus = minus_pq.top();

                    if (plus < abs(minus)) {
                         cout << plus << "\n";
                         plus_pq.pop();
                    }
                    else {
                         cout << minus << "\n";
                         minus_pq.pop();
                    }
               }

          }
     }
     return 0;
}