// 백트래킹 입문 문제
// DFS로 모든 경우를 탐색하는 백트래킹 알고리즘.

#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int N, M;
bool visit[9];
void DFS(int n) {
     if (n == M) {
          for (int i = 0; i < vec.size(); i++) {
               cout << vec[i] << " ";
          }
          cout << "\n";
          return;
     }

     for (int i = 1; i <= N; i++) {
          if (visit[i] == false) {
               // 자원사용 표시
               visit[i] = true;
               // 자원사용
               vec.push_back(i);
               // 단계진행
               DFS(n + 1);
               // 자원사용 반환 표시
               visit[i] = false;
               // 자원사용 반환
               vec.pop_back();
          }
     }


}

int main() {
     cin >> N >> M;
     DFS(0);
     return 0;
}