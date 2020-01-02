#include <iostream>
#include <vector>
using namespace std;


int N, M;
vector<int> vec;
void DFS(int n, int now) {
     if (n == M) {
          for (int i = 0; i < vec.size(); i++) {
               cout << vec[i] << " ";
          }
          cout << "\n";
          return;
     }

     for (int i = now; i <= N; i++) {
          vec.push_back(i);
          DFS(n + 1, i);
          vec.pop_back();
     }
}

int main() {
     cin >> N >> M;
     DFS(0, 1);
}