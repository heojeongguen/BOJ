#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[21][6];
vector<pair<int, int>> vec;

class BUG {
public:
     int cnt;
     int birth;
};
queue<pair<int, int> > que;
int main() {
     int N;
     cin >> N;
     que.push({ 1,1 });
     for (int i = 2; i <= N; i++) {
          int size = que.size();
          for (int j = 0; j < size; j++) {
               pair<int, int> front = que.front();
               que.pop();
               que.push({ front.first, i });

               if (front.second % 2 == 1) {
                    if (i - front.second < 3) {
                         que.push({ front.first,front.second });
                    }
               }
               else {
                    if (i - front.second < 4) {
                         que.push({ front.first,front.second });
                    }
               }
          }
     }
     int ans = 0;
     while (!que.empty()) {
          pair<int, int> front = que.front(); que.pop();
          ans += front.first;
     }
     cout << ans << endl;
}
