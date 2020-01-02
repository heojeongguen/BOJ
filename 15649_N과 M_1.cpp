// ��Ʈ��ŷ �Թ� ����
// DFS�� ��� ��츦 Ž���ϴ� ��Ʈ��ŷ �˰���.

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
               // �ڿ���� ǥ��
               visit[i] = true;
               // �ڿ����
               vec.push_back(i);
               // �ܰ�����
               DFS(n + 1);
               // �ڿ���� ��ȯ ǥ��
               visit[i] = false;
               // �ڿ���� ��ȯ
               vec.pop_back();
          }
     }


}

int main() {
     cin >> N >> M;
     DFS(0);
     return 0;
}