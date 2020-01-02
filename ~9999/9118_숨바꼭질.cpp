#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define MAX_N 20001

vector<int> vec[MAX_N];

class PQItem {
public:
     int n;
     int cost;
     PQItem(int n, int cost) {
          this->n = n;
          this->cost = cost;
     }
     bool 
};

int main(){
     int N, M;
     cin >> N >> M;
     for (int i = 0; i < M; i++) {
          int a, b; cin >> a >> b;
          vec[a].push_back(b);
          vec[b].push_back(a);
     }
}