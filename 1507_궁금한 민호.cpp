#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define MAX_N 21
#define INF 1e9
int dp[MAX_N][MAX_N];
int dp2[MAX_N][MAX_N];

int main() {
     ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
     int N; cin >> N;
     for (int i = 0; i < N; i++) {
          for (int j = 0; j < N; j++) {
               int data; cin >> data;
               dp[i][j] = data; // ��ȣ�� ���� �ּڰ�
               dp2[i][j] = data; // ��ȣ�� ���� �ּڰ����� ���� �� �ִ� �ּڰ�
          }
     }

     for (int m = 0; m < N; m++) {
          for (int s = 0; s < N; s++) {
               for (int e = 0; e < N; e++) {
                    if (s == m || e == m) continue; // s -> m -> e �ΰ�쿡 m�� s�� e�� �޶�� ��ȿ�� �񱳰� �ȴ�.
                    if (dp[s][e] == dp[s][m] + dp[m][e]) { 
                         // �߰� ������ ���İ������� �ٷ� ���� �� ���ٸ�
                         // �ٷ� ���� ���� ���±�� ó�� ���ش�
                         dp2[s][e] = 0;
                    }
                    else if (dp[s][e] > dp[s][m] + dp[m][e]){
                         // �ٷ� ���±��� �߰� ������ ���Ŀ��� �ź��� ���� �ɸ��� ����
                         // ��ȣ�� dp table�� �߸� ���� ����̴�.
                         cout << -1 << "\n";
                         return 0;
                    }

               }
          }
     }
     int total = 0;
     // [i][j] = [j][i] �̹Ƿ� �밢���� �����ʸ� �����ش�.
     for (int i = 0; i < N; i++) {
          for (int j = i + 1; j < N; j++) {
               total += dp2[i][j];
          }
     }
     cout << total << "\n";


}