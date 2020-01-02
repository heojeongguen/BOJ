#include <iostream>
#include <string>
using namespace std;

int main() {
     string str;
     cin >> str;
     int key = 0;
     for (int i = 0; i <= 255; i++) {
          if ((str[0] ^ i) == (int)'C')
               key = i;
     }

     for (int i = 0; i < str.size(); i++) {
          cout << (char)(str[i] ^ key);
     }
}