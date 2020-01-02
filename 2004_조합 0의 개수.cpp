#include <iostream>
#include <algorithm>
using namespace std;
long long fuc(long long n, long long div) {
     long long cnt = 0;
     long long tmp = div;
     while (tmp <= n) {
          cnt += n / tmp;
          tmp *= div;
     }
     return cnt;
}


int main() {
     long long n, m, c, cnt_2, cnt_5;
     cin >> n >> m;
     c = n - m;
     cnt_5 = fuc(n, 5);   cnt_2 = fuc(n, 2);
     cnt_5 -= fuc(m, 5);  cnt_2 -= fuc(m, 2);
     cnt_5 -= fuc(c, 5);   cnt_2 -= fuc(c, 2);
     //cout << cnt_5 << " " << cnt_2 << endl;
     cout << min(cnt_5, cnt_2) << endl;
     return 0;
}