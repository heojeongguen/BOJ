#include <iostream>
#include <vector>
#include <queue>
using namespace std;
deque<pair<int,int>> que;
int cnt;
int N, M, K, Q;

class Info {
public:
     vector<int> list;
     Info() {}
};

Info* arr = new Info[500001];
int now_Cnt = 0;
void fuc1(int s, int e) {
     int tmp = e - s + 1;
     arr[s].list.clear();
     for (int i = 0; i < tmp; i++) {
          if (!que.empty()) {
               arr[s].list.push_back(que.front().first); //error
               if (que.front().second == 1) que.pop_front();
               else que[0].second = que[0].second - 1;
          }
          else {
               arr[s + i].list.clear();
               arr[s + i].list.push_back(0);
          }
     }

     cout << "\n소각후 소각로 상태 : ";
     for (int i = 1; i <= M;) {
          for (int j = 0; j < arr[i].list.size(); j++) {
               cout << arr[i].list[j] << " ";
          }
          i += arr[i].list.size();
          now_Cnt -= 1;
     }
     cout << endl;
}

void fuc2(int pos) {
     for (int i = 1; i <= M;) {
          if (arr[i].list.size() + i - 1 >= pos && i <= pos) {
               cout << arr[i].list[pos - i] << " ";
               return;
          }
          i += arr[i].list.size();
     }
}
void fuc3(int p, int q) {
     if(q >= M - now_Cnt){
          for (int i = now_Cnt; i < M; i++) {
               arr[i+1].list.push_back(p);
          }
          que.push_back({ p,q - (M - now_Cnt) });
          now_Cnt = M;
     }
     else {
          for (int i = now_Cnt; i < q; i++) {
               arr[i].list.push_back(p);
          }
          now_Cnt += q;
     }
   

}
void fuc4(int t) {
     for (int i = 0; i < t; i++) {
          que[0].second = que[0].second - 1; // error
          if (que[0].second == 0) {
               que.pop_front();
          }
     }
}

int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     cin >> N >> M >> K >> Q;
     now_Cnt = M;
     for (int i = 1; i <= M; i++) {
          int x; cin >> x;
          arr[i].list.push_back(x);
     }
     for (int i = 0; i < N - M; i++) {
          int x; cin >> x;
          que.push_back({ x,1 });
     }


     for (int i = 0; i < Q; i++) {
          int x; cin >> x;
          if (x == 1) {
               int s, e;
               cin >> s >> e;
               fuc1(s, e);
          }
          else if (x == 2) {
               int pos; cin >> pos;
               fuc2(pos);
          }
          else if (x == 3) {
               int p, q; cin >> p >> q;
               fuc3(p, q);
          }
          else if (x == 4) {
               int t; cin >> t;
               fuc4(t);
          }
     }
     cout << "\n";
     for (int i = 1; i <= M;) {
          for (int j = 0; j < arr[i].list.size(); j++) {
               cout << arr[i].list[j] << " ";
          }
          i += arr[i].list.size();
     }
}