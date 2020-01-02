#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vec;
int main() {
     int N;
     cin >> N;
     for (int i = 0; i < N; i++) {
          int n; cin >> n;
          vec.push_back(n);
     }
     sort(vec.begin(), vec.end());
     if (N == 1) cout << vec[0] * vec[0] << endl;
     else cout << vec.front() * vec.back() << endl;

     return 0;
}