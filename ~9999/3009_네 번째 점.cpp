#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector < pair<int, int>> vec;
bool cmp(pair<int, int> a, pair<int, int> b) {
     if (a.first == b.first) return a.second < b.second;
     else return a.first < b.first;
}

int main() {
     for (int i = 0; i < 3; i++) {
          int x, y;
          cin >> x >> y;
          vec.push_back(make_pair(x, y));
     }
     sort(vec.begin(), vec.end());
     int x_gap;
     int y_gap;
     int x;
     int y;
     if (vec[0].first == vec[1].first) {
          y_gap = vec[1].second - vec[0].second;
          x_gap = vec[2].first - vec[0].first;
          x = vec[2].first;
          if (vec[2].second == vec[0].second) {
               y = vec[1].second;
          }
          else {
               y = vec[0].second;
          }
     }
     else {
          y_gap = vec[2].second - vec[1].second;
          x_gap = vec[1].first - vec[0].first;
          x = vec[0].first;
          if (vec[0].second == vec[1].second) {
               y = vec[2].second;
          }
          else {
               y = vec[1].second;
          }
     }
     cout << x << " " << y << endl;
}