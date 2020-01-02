#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_LEAF 30000

class Info {
public:
     int x, y1, y2;
     bool left;
     Info() {}
     Info(int x, int y1, int y2, bool left) {
          this->x = x;
          this->y1 = y1;
          this->y2 = y2;
          this->left = left;
     }
     bool operator < (const Info & b) const {
        return this->x < b.x;
     }
};

int tree[MAX_LEAF * 4];
int cnt[MAX_LEAF * 4];
void update_tree(int now, int left,int right, int start, int end, int value) {
     // 범위 체크
     if (left > end || right < start) return;

     // 해당 범위에 들어온다면 현재 cnt를 증가 또는 감소 시켜줌
     if (left <= start && end <= right) {
          cnt[now] += value;
     }

     // 범위에 들어올 지언정 " range_update " 를위해 하단 리프노드까지 내려가야 한다.
     else{
          int mid = (start + end) / 2;
          update_tree(now * 2, left, right, start, mid, value);
          update_tree(now * 2 + 1, left, right, mid+1, end, value);
     }

     // 해당 노드가 0 인데 리프노드라면 그냥 0으로 해주면되고
     //                   리프노드가 아니라면 ( 왼쪾자식 + 오른쪽자식 ) 이 자신의 cnt가 된다.
     if (!cnt[now]) {
          if (start != end)  tree[now] = tree[now * 2] + tree[now * 2 + 1];
          else  tree[now] = 0;
     }
     // 만약 자신이 해당범위에 들어와서 위에서 "cnt[now] += value" 로인해 1이상이 되었다면
     // 자기 하위의 모든 노드들은 범위에 포함되므로, 끝 - 시작 + 1 이 cnt가 된다.
     else  tree[now] = end - start + 1;
}


vector<Info> vec;
int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     int N;
     cin >> N;
     for (int i = 0; i < N; i++) {
          int x1, y1, x2, y2;
          cin >> x1 >> y1 >> x2 >> y2;
          vec.push_back(Info(x1, y1, y2, true));
          vec.push_back(Info(x2, y1, y2, false));
     }
     // x축 정렬 ( for 라인스위핑 )
     sort(vec.begin(), vec.end());
     Info prev;

     int ans = 0;
     for (int i = 0; i < vec.size(); i++) {
          if (i) {
               ans += (vec[i].x - vec[i - 1].x) * tree[1];
               cout << "dx : " << vec[i].x - vec[i - 1].x << " dy : " << tree[1] << " ans : " << ans << endl;
          }
          // 왼쪽 선분인경우 : +1, 오른쪽선분인 경우 : -1
          int value = (vec[i].left == true) ? 1 : -1;
          update_tree(1, vec[i].y1, vec[i].y2 - 1, 0, MAX_LEAF - 1, value);
     }
     cout << ans << "\n";
}