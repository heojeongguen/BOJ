#include <iostream>
#include <stack>
#include <deque>
#include <vector>
using namespace std;
#define ull unsigned long long
deque<ull> dq;
deque<ull> dq2;

ull DIV = 1000000007;
ull fac(ull x) {
     ull ans = 1;
     for (int i = x; i >= 1; i--) {
          ans = (ans * i) % DIV;
     }
     return ans % DIV;
}

ull pow(ull a, ull b) {
     ull ret = 1;
     ull aa = a;
     while (b > 0) {
          if (b % 2 == 1) ret = (ret * aa)  % DIV;
          b = b / 2;
          aa = (aa * aa) % DIV;
     }
     return ret % DIV;
}

int main() {
     ull L;
     cin >> L;
     ull N1;
     cin >> N1;
     for (long long i = 0; i < N1; i++) {
          ull data;
          cin >> data;
          dq.push_back(data);
     }
     ull N2;
     ull split = 0;
     ull total = 0;
     ull total_ = 0;
     cin >> N2;
     for (ull i = 0; i < N2; i++) {
          // 나누기, 합치기 total 
          // 나누기 ans
          ull data;
          cin >> data; 
          dq2.push_back(data);
          ull front = dq.front(); dq.pop_front();
          if (data == 1) {
               if (front == 1) {
                    continue;
               }
               else if(front == 2){
                    total++;
                    dq.push_front(1);
                    split++;
               }
          }
          else if(data == 2) {
               if (front == 1) {
                    ull next = dq.front(); dq.pop_front();
                    if (next == 1) {
                         total += 1;
                         continue;
                    }    
                    else if(next == 2){
                         total += 2;
                         dq.push_front(1);
                         split++;
                    }
               }
               else if(front == 2){
                    continue;
               }
          }
     }

     ull head, tail;
     ull ans2 = 0;

     int mergeCnt = 0;

     while(!dq2.empty()) {
          ull front = dq2.front(); dq2.pop_front();
          if (front == 1) {
               continue;
          }
          else if (front == 2) {
               mergeCnt++;
          }
     }


     //head = fac(total) % DIV;
     //tail = (fac(total - ans) * fac(ans)) % DIV;

     //ans2 = (head * pow(tail, DIV - 2)) % DIV;
     //if (total == 0) ans2 = 0;
     //cout << total % DIV << " " << ans2 << "\n";

     cout << "total : " << total << endl;
     cout << "split : " << split << endl;
     cout << "merge : " << mergeCnt << endl;

}



 
