#include <iostream>
#include <algorithm>
using namespace std;
int arr[9];
int info[101];
int main() {
     for (int i = 0; i < 9; i++) {
          cin >> arr[i];
          info[arr[i]] = i + 1;
     }
     int mmax = *max_element(arr, arr + 9);
     cout << mmax << endl;
     cout << info[mmax] << endl;
}