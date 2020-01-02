#include <iostream>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

int main() {
     string str;
     cin >> str;
     int tmp = 0;
     int ans = 0;
     for (int i = 0; i < str.size(); i++) {
          if (str[i] == '(') {
               tmp += 1;
          }
          else if (str[i] == ')') {
               tmp -= 1;
          }
          else if (str[i] == '{') {
               tmp += 2;
          }
          else if (str[i] == '}') {
               tmp -= 2;

          }
          else if (str[i] == '[') {
               tmp += 3;
          }
          else if (str[i] == ']') {
               tmp -= 3;
          }
          else {
               ans = max(ans, tmp);
          }
     }
     cout << ans << endl;
}