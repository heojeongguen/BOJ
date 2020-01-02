#include <iostream>
#include <vector>
#include <string>
using namespace std;
string key = "CHICKENS";
vector<int> ans;
int fuc(int now, int data) {
     data += ((int)key[now] - 65);
     data %= 26;
     if (now == 7) {
          int first = (int)key[0] - 65;
          first++;
          first %= 26;
          key[0] = (char)(first + 65);
          return data;
     }
     else {
          return fuc(now + 1, data);
     }
}

int main() {
     // A  : 65 , Z : 90
     // 0 ~ 25;
     string str;
     cin >> str;
     for (int i = 0; i < str.size(); i++) {
          int tmp = fuc(0, (int)str[i] - 65);
          ans.push_back(tmp);
     }
     for (int i = 0; i < ans.size(); i++) {
          cout << (char)(ans[i] + 65);
     }
}