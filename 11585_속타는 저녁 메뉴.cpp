#include <iostream>
#include <string>
using namespace std;

int GCD(int a, int b) {
     while (b > 0) {
          int tmp = a;
          a = b;
          b = tmp % b;
     }
     return a;
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     string A;
     string B;
     int N; char input;
     cin >> N;
     for (int j = 0; j < N; j++) {
          cin >> input;
          A.push_back(input);
     }
     for (int j = 0; j < N; j++) {
          cin >> input;
          B.push_back(input);
     }
     int cnt = 0;
     for (int i = 0; i < N; i++) {
          string tmp = B.substr(i, N - i);
          string tmp2 = B.substr(0, i);
          if (A == tmp + tmp2) cnt++;
     }

     int gcd = GCD(cnt, N);

     cout << cnt / gcd << "/" << N / gcd << "\n";
     return 0;
}