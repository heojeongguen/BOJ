#include <iostream>
#include <vector>
using namespace std;

bool row[9][9];
bool col[9][9];
bool box[9][9];
int arr[9][9];
vector<pair<int,int >> vec;
int cnt = 0;
int getBoxNum(int r, int c) {
     if (r <= 2) {
          if (c <= 2) {
               return 1;
          }
          else if (c <= 5) {
               return 2;
          }
          else if (c <= 8) {
               return 3;
          }
     }
     else if (r <= 5) {
          if (c <= 2) {
               return 4;
          }
          else if (c <= 5) {
               return 5;
          }
          else if (c <= 8) {
               return 6;
          }
     }
     else if (r <= 8) {
          if (c <= 2) {
               return 7;
          }
          else if (c <= 5) {
               return 8;
          }
          else if (c <= 8) {
               return 9;
          }
     }
}

bool suc = false;
void fuc(int n) {
     if (n == cnt) {
          for (int i = 0; i < 9; i++) {
               for (int j = 0; j < 9; j++) {
                    cout << arr[i][j] << " ";
               }
               cout << "\n";
          }
          
          exit(0);
     }

     int r = vec[n].first;
     int c = vec[n].second;

     for (int i = 1; i <= 9; i++) {
          if (row[r][i] == false && col[i][c] == false && box[getBoxNum(r, c)][i] == false) {
               arr[r][c] = i;
               row[r][i] = true;
               col[i][c] = true;
               box[getBoxNum(r, c)][i] = true;
               fuc(n + 1);
               row[r][i] = false;
               col[i][c] = false;
               box[getBoxNum(r, c)][i] = false;
               arr[r][c] = 0;
          }
     }
}

int main() {
     for (int i = 0; i < 9; i++) {
          for (int j = 0; j < 9; j++) {
               int x; cin >> x;
               arr[i][j] = x;
               if (x == 0) {
                    vec.push_back(make_pair(i, j));
               }
               else {
                    row[i][x] = true;
                    col[x][j] = true;
                    box[getBoxNum(i, j)][x] = true;
               }
          }
     }
     cnt = vec.size();
     fuc(0);
     return 0;
}