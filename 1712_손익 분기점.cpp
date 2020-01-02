#include <iostream>

using namespace std;

int main() {
     int A, B, C;
     cin >> A >> B >> C;
     if (B < C) {
          cout << A / (C - B) + 1 << endl;
     }
     else {
          cout << -1 << endl;
     }
     
}