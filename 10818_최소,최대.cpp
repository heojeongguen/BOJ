#include <iostream>
#include <algorithm>
using namespace std;
int arr[1000000];
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N;
     cin >> N;
     for (int i = 0; i < N; i++) {
          cin >> arr[i];
     }
     cout << *min_element(arr, arr + N) << " " << *max_element(arr, arr + N) << endl;
}