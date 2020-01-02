#include <iostream>

using namespace std;
int arr[129][129];

int white = 0;
int blue = 0;
void fuc(int x, int y, int size) {
     bool fail = false;
     int tmp;
     for (int i = x; i < x + size; i++) {
          for (int j = y; j < y + size; j++) {
               if (i == x && j == y) {
                    tmp = arr[i][j];
               }
               else {
                    if (tmp != arr[i][j]) {
                         fail = true;
                         break;
                    }
               }
          }
          if (fail) break;
     }
     if (fail) {
          fuc(x, y, size / 2);
          fuc(x + size/2, y, size / 2);
          fuc(x, y + size/2, size / 2);
          fuc(x + size / 2, y + size / 2, size / 2);
     }else{
          if (tmp == 1) {
               blue++;
          }
          else {
               white++;
          }
     }
}

int main() {
     int N;
     cin >> N;
     for (int i = 1; i <= N; i++) {
          for (int j = 1; j <= N; j++) {
               cin >> arr[i][j];
          }
     }
     fuc(1, 1, N);
     cout << white << "\n" << blue << "\n";
     return 0;
}