#include <iostream>

using namespace std;

int main() {
     int N = 5000;
     int tmp;
     while (cin >> tmp) {
          if (tmp == 1) {
               N -= 500;
          }
          else if (tmp == 2) {
               N -= 800;
          }
          else if (tmp == 3) {
               N -= 1000;
          }
     }
     cout << N << endl;
}