#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
long sum(vector<int> vec) {
     long ans = 0;
     for (const auto & x : vec) {
          ans += x;
     }
     return ans;
}
int main() {

}
