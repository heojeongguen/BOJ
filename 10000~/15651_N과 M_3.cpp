#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> vec;

void DFS(int n) {
     if (n == M) {
          for (int i = 0; i < vec.size(); i++) {
               cout << vec[i] << " ";
          }
          cout << "\n";
          return;
     }

     for (int i = 1; i <= N; i++) {
          vec.push_back(i);
          DFS(n+1);
          vec.pop_back();
     }
}


int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     cin >> N >> M;
     DFS(0);
}