#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> vec;
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N;
     int i = 2;
     cin >> N;
     while (N > 1) {
          while (N % i == 0) {
               vec.push_back(i);
               N /= i;
          }
          i++;
     }
     for (int i = 0; i < vec.size(); i++) {
          cout << vec[i] << "\n";
     }
     return 0;
}