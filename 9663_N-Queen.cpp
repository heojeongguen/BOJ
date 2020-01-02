// ��Ʈ��ŷ ��ǥ����
// ���� ���� ��� : ���� ���� �밢��
// 1���� row, �ι�° row ,3��° row... row�� �Ķ���ͷεθ� trace���� column�� ǥ�����ָ��
// ex) n == 1�϶�(�� row�� 1�϶� ��� �࿡ �ٳ��� ��츦 �����ϸ�� )
// �밢���� ��� n�� , column�� �˰��ִٸ� ���� �밢���� �����ִ��� �� ������ trace-trace , row-row �������� ���� �밢���ΰ���.
#include <iostream>
#include <vector>
using namespace std;

int trace[15];
int N, ans = 0;


void DFS(int n)
{
     if (n == N) {
          // why? : n == N 
          // N * N ü���ǿ� N���� ���� �ڸ��������� ��� ����(row)�� �ϳ��� �ڸ���� �ִ�/
          // ������ n == N �� ü�����ǿ� N���� ���� ��� �ڸ��������� ���̴�.
          ans++;
          return;
     }

     for (int j = 0; j < N; j++)
     {
          // n(row), j(col)�� ���� ���Ҵٴ� �ǹ�.
          // �ڿ������ for���� ���� trace[n] = 0, 1, 2 ... �ڿ������� �ڿ� �������� �ȴ�.
          trace[n] = j;

          // row col �밢 Ȯ��
          // row : ��ĥ���� ����. �Ķ������ü�� �����ϴ� �����̱� ����.
          // col : �Ķ���� ���� ���� row�� ���� trace[row]�� �ݺ������� üũ�Ѵ�.
          // �밢�� : abs(trace[j] - trace[n]) == (n - j) �� üũ�Ѵ�.
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