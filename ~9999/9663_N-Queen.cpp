// 백트래킹 대표문제
// 퀸의 공격 방법 : 가로 세로 대각선
// 1번쨰 row, 두번째 row ,3번째 row... row를 파라미터로두면 trace에는 column을 표시해주면됨
// ex) n == 1일때(즉 row가 1일때 모든 행에 다놓는 경우를 생각하면됨 )
// 대각선의 경우 n과 , column을 알고있다면 같은 대각선에 속해있는지 알 수있음 trace-trace , row-row 가같으면 같은 대각선인것임.
#include <iostream>
#include <vector>
using namespace std;

int trace[15];
int N, ans = 0;


void DFS(int n)
{
     if (n == N) {
          // why? : n == N 
          // N * N 체스판에 N개의 퀸이 자리잡으려면 적어도 각열(row)에 하나씩 자리잡고 있다/
          // 때문에 n == N 는 체스파판에 N개의 퀸을 모두 자리잡은후의 값이다.
          ans++;
          return;
     }

     for (int j = 0; j < N; j++)
     {
          // n(row), j(col)에 퀸을 놓았다는 의미.
          // 자원사용후 for문에 의해 trace[n] = 0, 1, 2 ... 자연스럽게 자원 복원까지 된다.
          trace[n] = j;

          // row col 대각 확인
          // row : 겹칠일이 없다. 파라미터자체가 증가하는 형태이기 때문.
          // col : 파라미터 보다 작은 row에 대해 trace[row]를 반복문으로 체크한다.
          // 대각선 : abs(trace[j] - trace[n]) == (n - j) 로 체크한다.
          bool check = true;
          for (int j = 0; j < n; j++)
               if (trace[j] == trace[n] || abs(trace[j] - trace[n]) == (n - j))
                    check = false;
         
          if (check)
               DFS(n + 1);
     }
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     cin >> N;
     DFS(0);
     cout << ans << "\n";
}