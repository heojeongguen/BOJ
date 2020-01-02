#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<pair<long long,long long>> vec[200001];
bool visit[200001];
long long sum[200001];
pair<long long, long long> node;
long long s, e;
void findNode(long long now, long long cnt) {
     visit[now] = true;
     bool check = false;
     for (long long i = 0; i < vec[now].size(); i++) {
          if (visit[vec[now][i].first] == false) {
               check = true;
               findNode(vec[now][i].first, cnt + vec[now][i].second);
          }
     }
     if (!check) {
          if (node.first == -1) {
               node.first = now;
               node.second = cnt;
          }
          else {
               if (node.second < cnt) {
                    node.first = now;
                    node.second = cnt;
               }
          }
     }
}

void findNode2(long long now, long long cnt) {
     visit[now] = true;
     bool check = false;
     for (long long i = 0; i < vec[now].size(); i++) {
          if (visit[vec[now][i].first] == false) {
               check = true;
               findNode(vec[now][i].first, cnt + vec[now][i].second);
          }
     }
     if (!check) {
          if (node.first == -1) {
               node.first = now;
               node.second = cnt;
          }
          else {
               if (node.second < cnt) {
                    node.first = now;
                    node.second = cnt;
               }
          }
     }
}

bool link(long long now) {
     //cout << " now : " << now << " e : " << e << endl;
     visit[now] = true;
     bool check = false;
     bool ret = false;
     for (long long i = 0; i < vec[now].size(); i++) {
          if (visit[vec[now][i].first] == false) {
               check = true;
               bool tmp_ret = link(vec[now][i].first);
               if (tmp_ret == true) {
                    vec[now][i].second = -1;
                    if (!ret) {
                         ret = true;
                    }
               }
               
          }
     }
     if (!check) {
          if (now == e) {
               return true;
          }
          else {
               return false;
          }
     }
     return ret;
}

bool link2(long long now) {
     //cout << " now : " << now << " e : " << e << endl;
     visit[now] = true;
     bool check = false;
     bool ret = false;
     for (long long i = 0; i < vec[now].size(); i++) {
          if (visit[vec[now][i].first] == false) {
               check = true;
               bool tmp_ret = link2(vec[now][i].first);
               if (tmp_ret == true) {
                    vec[now][i].second = -1;
                    if (!ret) {
                         ret = true;
                    }
               }

          }
     }
     if (!check) {
          if (now == e) {
               return true;
          }
          else {
               return false;
          }
     }
     return ret;
}

void findLongest(long long now,long long add) {
     visit[now] = true;
     bool check = false;
     sum[now] = add;
     for (long long i = 0; i < vec[now].size(); i++) {
          if (visit[vec[now][i].first] == false) {
               if (vec[now][i].second != -1) {
                    findLongest(vec[now][i].first, add + vec[now][i].second);
               }
               else {
                    findLongest(vec[now][i].first, add);
               }
          }
     }
}


int main() {
     ios::sync_with_stdio(false);
     cin.tie(0);
     cout.tie(0);
     long long N;
     cin >> N;
     for (long long i = 0; i < N-1; i++) {
          long long a, b, t;
          cin >> a >> b >> t;
          vec[a].push_back({ b,t });
          vec[b].push_back({ a,t });
     }
     node.first = -1;
     node.second = -1;
     findNode(1, 0);
     //cout << "fist : " << node.first << " second : " << node.second << endl;
     memset(visit, false, sizeof(visit));
     s = node.first;
     node.first = -1;
     node.second = -1;
     findNode(s, 0);
     e = node.first;
     //cout << "fist : " << node.first << " second : " << node.second << endl;
     memset(visit, false, sizeof(visit));
     //cout << " s : " << s << " e : " << e << endl;
     link(s);
     memset(visit, false, sizeof(visit));
     link2(e);
     memset(visit, false, sizeof(visit));
     findLongest(s,0);
     long long longest = 0;
     for (long long i = 1; i <= N; i++) {     
          //cout << " sum[" << i << "] : " << sum[i] << endl;
          if (sum[i] != -1) {
               longest = max(longest, sum[i]);
          }
     }
     cout << node.second + longest << "\n";
}