#include <iostream>

using namespace std;
int arr[999][999];
pair<int, int> dxdy[4] = { {0,1},{1,0},{0,-1},{-1,0} };
int main() {
     int N, Q;
     int r, c;
     cin >> N >> Q;
     int x = N / 2;
     int y = N / 2;

     int size = 2;
     int cnt = 0;
     int direc = 1;
     for (int i = 1; i <= N * N; i++) {
          if (i == Q) {
               r = x;
               c = y;
          }
          if (i == 1) {
               arr[x][y] = i;
               x--;
          }
          else if (i == 2) {
               arr[x][y] = i;
               y++;
          }
          else if (i == 3) {
               arr[x][y] = i;
               x++;
          }
          else {
               arr[x][y] = i;
               cnt++;
               if (cnt == size) {
                    if (direc == 0 || direc == 2) {
                         direc++;
                         direc %= 4;
                         size++;
                         cnt = 0;
                    }
                    else {
                         direc++;
                         direc %= 4;
                         cnt = 0;
                    }
               }
               x += dxdy[direc].first;
               y += dxdy[direc].second;
          }
     }
     for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
               cout << arr[i][j] << " ";
          }
          cout << endl;
     }
     cout << r + 1 << " " << c + 1 << endl;
}