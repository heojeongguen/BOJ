#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int arr[1001][5];
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     string A;
     getline(cin, A);
     string B = "UCPC";
     for (int i = 0; i < A.size(); i++) {
          for (int j = 0; j < 4; j++) {
               if (A[i] == B[j]) {
                    arr[i + 1][j + 1] = arr[i][j] + 1;
               }
               else {
                    arr[i + 1][j + 1] = max(arr[i][j + 1], arr[i + 1][j]);
               }
          }    
     }

     if (arr[A.size()][4] == 4) {
          cout << "I love UCPC\n";
     }
     else {
          cout << "I hate UCPC\n";
     }

}