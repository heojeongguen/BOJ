#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define MAX_N 20000
int par[MAX_N + 1];
int dist[MAX_N + 1];

int getPar(int x) {
     if (par[x] == x) return x;
     return par[x] = getPar(par[x]);
}

void make_union(int x, int y) {
     int cost = abs(x - y) % 1000;
     x = getPar(x);
     y = getPar(y);
     par[x] = y;
     dist[x] = cost;
     dist[y] += (cost + dist[x]);
}


int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int T; cin >> T;
     while (T--) {
          int N; cin >> N;
          for (int i = 0; i <= N; i++) {
               par[i] = i;
               dist[i] = 0;
          }
          char tag;
          while (cin >> tag) {
               if (tag == 'O') break;
               else if (tag == 'E') {
                    int I; cin >> I;
                    cout << dist[getPar(I)] << "\n";
               }
               else if (tag == 'I') {
                    int I, J; cin >> I >> J;
                    make_union(I, J);
               }
          }
     }
}