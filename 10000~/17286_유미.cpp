#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits.h>
#define INF INT_MAX
using namespace std;
vector<pair<int, int> > vec;

int x, y;

double getDis(double x1, double y1, double x2, double y2, double x3, double y3) {
     double ret = 0;
     ret += sqrt((x1 - x) * (x1 - x) + (y1 - y)* (y1 - y));
     ret += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1)* (y2 - y1));
     ret += sqrt((x3 - x2) * (x3 - x2) + (y3 - y2)* (y3 - y2));
     return ret;
}


int main() {
     cin >> x >> y;
     for (int i = 0; i < 3; i++) {
          int a, b;
          cin >> a >> b;
          vec.push_back({ a,b });
     }

      double ans = INF;
     for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
               if (i == j) continue;
               for (int z = 0; z < 3; z++) {
                    if (z == i || z == j) continue;
                    ans = min(ans, getDis(vec[i].first, vec[i].second, vec[j].first, vec[j].second, vec[z].first, vec[z].second));
               }
          }
     }
     cout << (int)ans << "\n";
     return 0;
}